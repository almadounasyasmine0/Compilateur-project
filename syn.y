%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ts.h"

/* --- VARIABLES ET DÉCLARATIONS C --- */
char saved_name[20];
int yylex();
void yyerror(const char *s);
void erreurSemantique(char* message, char* entite);
void quadr(char oper[], char op1[], char op2[], char res[]);
void updateQuad(int num_quad, int colon_quad, char val[]);
void afficher_qdr();

/* --- Partie Quadruplets ---*/

/* Variables globales pour le backpatching des structures de controle */
int Fin_if = 0;
int deb_else = 0;
int deb_while = 0;
int fin_while = 0;
int deb_for = 0;
int fin_for = 0;
int qc = 0;
int cpt_temp = 0;
char tmp[20];
char idf_for[20];
char borne_for[20];

char* creer_temp() {
    char nom_temp[20];
    sprintf(nom_temp, "T%d", cpt_temp++);
    return strdup(nom_temp);
}

%}

%code requires {
    typedef struct {
        char* nom;
        char* type;
    } Attribut;
}

%union {
    char* str;
    char* v_type;
    Attribut attr;
}

/* --- PRIORITÉS (Ordre croissant selon sujet) --- */
%left OR_mc
%left AND_mc
%left NON_mc
%left supperieure inferieure sup_egal inf_egal egal diff_op
%left addition sustra
%left multipl div_op

/* --- TYPES DES NON-TERMINAUX --- */
%type <str> TYPE SIGNE OPERATEUR_COMP
%type <attr> EXPRESSION TERME FACTEUR ENTIER REEL VALEUR CONDITION

/* --- TOKENS --- */
%token BeginProject_mc EndProject_mc Setup_mc Run_mc
%token define_mc const_mc int_mc float_mc
%token if_mc then_mc else_mc endIf_mc
%token loop_mc while_mc endloop_mc for_mc in_mc to_mc endfor_mc
%token out_mc
%token AND_mc OR_mc NON_mc
%token addition sustra multipl div_op
%token supperieure inferieure sup_egal inf_egal egal diff_op 
%token affectation barre_mc deux_points point_virg point virg
%token parenthese_ouvrante parenthese_fermante
%token accolade_ouvrante accolade_fermante
%token crochet_ouvrant crochet_fermant
%token <str> idf cst_int cst_float chaine

%start S
%%

/* --- II.1. STRUCTURE GÉNÉRALE --- */
S : BeginProject_mc idf point_virg SECTION_SETUP SECTION_RUN EndProject_mc point_virg
    { printf("Felicitations : La structure du programme ProLang est valide !\n"); }
  ;

/* --- II.2. PARTIE DÉCLARATION (Setup) --- */
SECTION_SETUP : Setup_mc deux_points LISTE_DECLARATIONS ;

LISTE_DECLARATIONS : UNE_DECLARATION LISTE_DECLARATIONS | ;

UNE_DECLARATION : DECL_DEFINE | DECL_CONSTANTE ;

/* Syntaxe: define a | b | c : type ; */
DECL_DEFINE : define_mc idf { 
                if (rechercher($2) == NULL) inserer($2, "Variable", "attente", 0, 0);
                else erreurSemantique("Double declaration", $2);
                strcpy(saved_name, $2); 
              } 
              LISTE_IDFS_SUITE deux_points SUITE_TYPE point_virg ;

LISTE_IDFS_SUITE : barre_mc idf LISTE_IDFS_SUITE
                 {
                    if (rechercher($2) == NULL) inserer($2, "Variable", "attente", 0, 0);
                    else erreurSemantique("Double declaration", $2);
                 }
                 | ;

SUITE_TYPE : TYPE OPT_INIT
            { 
                mettreAjourType("attente", $1, 0);
            }
           | crochet_ouvrant TYPE point_virg ENTIER crochet_fermant
            { 
                int t = atoi($4.nom);
                if (t <= 0) erreurSemantique("Taille tableau doit etre > 0", "Tableau");
                mettreAjourType("attente", $2, t); 
            }
           ;

TYPE : int_mc   { $$ = "integer"; }
     | float_mc { $$ = "float"; }
     ;

OPT_INIT : egal VALEUR | ;

/* Syntaxe: const Pi : float = 3.14 ; */
DECL_CONSTANTE : const_mc idf deux_points TYPE egal VALEUR point_virg
{
    if (rechercher($2) == NULL) {
        double val = atof($6.nom);
        if (strcmp($4, "integer") == 0 && (val < -32768 || val > 32767)) {
            erreurSemantique("Valeur hors intervalle [-32768, 32767]", $2);
            val = 0;
        }
        inserer($2, "Constante", $4, (float)val, 0);
    } else erreurSemantique("Constante deja declaree", $2);
}
;

/* --- SECTION RUN (Instructions) --- */
SECTION_RUN : Run_mc deux_points accolade_ouvrante LISTE_INSTRUCTIONS accolade_fermante ;

LISTE_INSTRUCTIONS : UNE_INSTRUCTION LISTE_INSTRUCTIONS | ;

UNE_INSTRUCTION : INSTRUCTION_AFFECTATION | INSTRUCTION_CONDITION | INSTRUCTION_BOUCLE | INSTRUCTION_IO ;

INSTRUCTION_AFFECTATION : idf affectation EXPRESSION point_virg 
    {
        Element* e = rechercher($1);
        if (!e) erreurSemantique("Variable non declaree", $1);
        else {
            // VERIF: Modification de constante
            if (strcmp(e->code, "Constante") == 0) erreurSemantique("Interdit de modifier une constante", $1);
            // VERIF: Compatibilité de types (ex: float vers int)
            else if (strcmp($3.type, "error") != 0 && strcmp(e->type, $3.type) != 0) erreurSemantique("Incompatibilite de types", $1);
            else if (strcmp($3.type, "error") != 0) quadr(":=", $3.nom, "_", $1);
        }
    }
    | idf crochet_ouvrant ENTIER crochet_fermant affectation EXPRESSION point_virg
    {
        Element* e = rechercher($1);
        char dest[100];
        if (!e) erreurSemantique("Tableau non declare", $1);
        else if (strcmp(e->code, "Tableau") != 0) erreurSemantique("Pas un tableau", $1);
        else if (strcmp($6.type, "error") != 0 && strcmp(e->type, $6.type) != 0) erreurSemantique("Incompatibilite", $1);
        else if (strcmp($6.type, "error") != 0) {
            sprintf(dest, "%s[%s]", $1, $3.nom);
            quadr(":=", $6.nom, "_", dest);
        }
    }
    ;

/* Syntaxe: if (cond) then[:]? { ... } else { ... } endIf; */
INSTRUCTION_CONDITION : BLOC_IF else_mc accolade_ouvrante LISTE_INSTRUCTIONS accolade_fermante
                        endIf_mc point_virg
                        {
                            sprintf(tmp, "%d", qc);
                            updateQuad(Fin_if, 1, tmp);
                        }
                        ;

/* R1: tester la condition et reserver le saut vers else */
TETE_IF : if_mc parenthese_ouvrante CONDITION parenthese_fermante
          {
              deb_else = qc;
              quadr("BZ", "", $3.nom, "vide");
          }
          ;

/* R2: fin du bloc then, saut vers la fin du if et MAJ du BZ */
BLOC_IF : TETE_IF then_mc OPT_DEUX_POINTS accolade_ouvrante LISTE_INSTRUCTIONS accolade_fermante
          {
              Fin_if = qc;
              quadr("BR", "", "vide", "vide");
              sprintf(tmp, "%d", qc);
              updateQuad(deb_else, 1, tmp);
          }
          ;

OPT_DEUX_POINTS : deux_points
                |
                ;

/* Syntaxe: for i in 1 to 10 { ... } endfor; */
INSTRUCTION_BOUCLE : BLOC_WHILE
                   | BLOC_FOR
                   ;

/* R1 while: memoriser le debut et tester la condition */
TETE_WHILE : loop_mc while_mc
             {
                 deb_while = qc;
             }
             parenthese_ouvrante CONDITION parenthese_fermante
             {
                 fin_while = qc;
                 quadr("BZ", "", $5.nom, "vide");
             }
             ;

/* R2 while: retour au debut puis MAJ du saut de sortie */
BLOC_WHILE : TETE_WHILE accolade_ouvrante LISTE_INSTRUCTIONS accolade_fermante
             endloop_mc point_virg
             {
                 sprintf(tmp, "%d", deb_while);
                 quadr("BR", tmp, "vide", "vide");
                 sprintf(tmp, "%d", qc);
                 updateQuad(fin_while, 1, tmp);
             }
             ;

/* R1 for: initialisation, test de borne et reservation du BZ */
TETE_FOR : for_mc idf in_mc VALEUR to_mc VALEUR
           {
               Element* e;
               char* temp;

               idf_for[0] = '\0';
               borne_for[0] = '\0';
               e = rechercher($2);

               if (!e) {
                   erreurSemantique("Variable non declaree", $2);
               } else if (strcmp(e->code, "Constante") == 0) {
                   erreurSemantique("Interdit de modifier une constante", $2);
               } else if (strcmp(e->type, "integer") != 0 ||
                          strcmp($4.type, "integer") != 0 ||
                          strcmp($6.type, "integer") != 0) {
                   erreurSemantique("Boucle for exige des entiers", $2);
               } else {
                   strcpy(idf_for, $2);
                   strcpy(borne_for, $6.nom);
                   quadr(":=", $4.nom, "_", idf_for);
                   deb_for = qc;
                   temp = creer_temp();
                   quadr("<=", idf_for, borne_for, temp);
                   fin_for = qc;
                   quadr("BZ", "", temp, "vide");
               }
           }
           ;

/* R2 for: incrementation, retour au test puis MAJ du BZ */
BLOC_FOR : TETE_FOR accolade_ouvrante LISTE_INSTRUCTIONS accolade_fermante
           endfor_mc point_virg
           {
               char* temp;

               if (idf_for[0] != '\0') {
                   temp = creer_temp();
                   quadr("+", idf_for, "1", temp);
                   quadr(":=", temp, "_", idf_for);
                   sprintf(tmp, "%d", deb_for);
                   quadr("BR", tmp, "vide", "vide");
                   sprintf(tmp, "%d", qc);
                   updateQuad(fin_for, 1, tmp);
                   idf_for[0] = '\0';
                   borne_for[0] = '\0';
               }
           }
           ;

INSTRUCTION_IO : out_mc parenthese_ouvrante LISTE_OUT parenthese_fermante point_virg
               | in_mc parenthese_ouvrante idf parenthese_fermante point_virg
                 {
                    Element* e = rechercher($3);
                    if (!e) erreurSemantique("Variable non declaree", $3);
                    else if (strcmp(e->code, "Constante") == 0) erreurSemantique("Interdit de modifier une constante", $3);
                    else quadr("READ", "_", "_", $3);
                 } ;

LISTE_OUT : chaine
            {
                quadr("WRITE", $1, "_", "_");
            }
          | chaine virg idf
            {
                Element* e = rechercher($3);
                quadr("WRITE", $1, "_", "_");
                if (!e) erreurSemantique("Variable non declaree", $3);
                else quadr("WRITE", $3, "_", "_");
            }
          | idf
            {
                Element* e = rechercher($1);
                if (!e) erreurSemantique("Variable non declaree", $1);
                else quadr("WRITE", $1, "_", "_");
            } ;

/* --- EXPRESSIONS ARITHMÉTIQUES --- */
EXPRESSION : EXPRESSION addition TERME 
             {
                char* temp;
                if (strcmp($1.type, "error") == 0 || strcmp($3.type, "error") == 0) {
                    $$.nom = "";
                    $$.type = "error";
                } else if(strcmp($1.type, $3.type) != 0) {
                    erreurSemantique("Incompatibilite types", "+");
                    $$.nom = "";
                    $$.type = "error";
                } else {
                    temp = creer_temp();
                    quadr("+", $1.nom, $3.nom, temp);
                    $$.nom = temp;
                    $$.type = $1.type;
                }
             }
           | EXPRESSION sustra TERME  
             {
                char* temp;
                if (strcmp($1.type, "error") == 0 || strcmp($3.type, "error") == 0) {
                    $$.nom = "";
                    $$.type = "error";
                } else if(strcmp($1.type, $3.type) != 0) {
                    erreurSemantique("Incompatibilite types", "-");
                    $$.nom = "";
                    $$.type = "error";
                } else {
                    temp = creer_temp();
                    quadr("-", $1.nom, $3.nom, temp);
                    $$.nom = temp;
                    $$.type = $1.type;
                }
             }
           | TERME { $$ = $1; }
           ;

TERME : TERME multipl FACTEUR
        {
            char* temp;
            if (strcmp($1.type, "error") == 0 || strcmp($3.type, "error") == 0) {
                $$.nom = "";
                $$.type = "error";
            } else if (strcmp($1.type, $3.type) != 0) {
                erreurSemantique("Incompatibilite types", "*");
                $$.nom = "";
                $$.type = "error";
            } else {
                temp = creer_temp();
                quadr("*", $1.nom, $3.nom, temp);
                $$.nom = temp;
                $$.type = $1.type;
            }
        }
      | TERME div_op FACTEUR
        {
            char* temp;
            if (strcmp($1.type, "error") == 0 || strcmp($3.type, "error") == 0) {
                $$.nom = "";
                $$.type = "error";
            } else if (strcmp($1.type, $3.type) != 0) {
                erreurSemantique("Incompatibilite types", "/");
                $$.nom = "";
                $$.type = "error";
            } else {
                temp = creer_temp();
                quadr("/", $1.nom, $3.nom, temp);
                $$.nom = temp;
                $$.type = $1.type;
            }
        }
      | FACTEUR               { $$ = $1; }
      ;

FACTEUR : idf 
          { 
            Element* e = rechercher($1); 
            if(!e){
                erreurSemantique("Non declare", $1);
                $$.nom = $1;
                $$.type = "error";
            } 
            else {
                $$.nom = $1;
                $$.type = e->type;
            }
          }
        | ENTIER { $$ = $1; }
        | REEL   { $$ = $1; }
        | idf crochet_ouvrant ENTIER crochet_fermant 
          { 
            Element* e = rechercher($1); 
            char ref[100];
            if(!e || strcmp(e->code,"Tableau")!=0) {
                erreurSemantique("Erreur tableau", $1);
                $$.nom = $1;
                $$.type = "error";
            } 
            else {
                sprintf(ref, "%s[%s]", $1, $3.nom);
                $$.nom = strdup(ref);
                $$.type = e->type;
            }
          }
        | parenthese_ouvrante EXPRESSION parenthese_fermante { $$ = $2; }
        ;

/* --- LOGIQUE & COMPARAISON --- */
CONDITION : EXPRESSION OPERATEUR_COMP EXPRESSION
            {
                char* temp;
                if (strcmp($1.type, "error") == 0 || strcmp($3.type, "error") == 0) {
                    $$.nom = "";
                    $$.type = "error";
                } else if (strcmp($1.type, $3.type) != 0) {
                    erreurSemantique("Incompatibilite types", $2);
                    $$.nom = "";
                    $$.type = "error";
                } else {
                    temp = creer_temp();
                    quadr($2, $1.nom, $3.nom, temp);
                    $$.nom = temp;
                    $$.type = "bool";
                }
            }
          | parenthese_ouvrante CONDITION parenthese_fermante { $$ = $2; }
          | CONDITION AND_mc CONDITION
            {
                char* temp;
                temp = creer_temp();
                quadr("AND", $1.nom, $3.nom, temp);
                $$.nom = temp;
                $$.type = "bool";
            }
          | CONDITION OR_mc CONDITION
            {
                char* temp;
                temp = creer_temp();
                quadr("OR", $1.nom, $3.nom, temp);
                $$.nom = temp;
                $$.type = "bool";
            }
          | NON_mc CONDITION
            {
                char* temp;
                temp = creer_temp();
                quadr("NOT", $2.nom, "_", temp);
                $$.nom = temp;
                $$.type = "bool";
            }
          ;

OPERATEUR_COMP : supperieure { $$ = ">"; }
               | inferieure  { $$ = "<"; }
               | sup_egal    { $$ = ">="; }
               | inf_egal    { $$ = "<="; }
               | egal        { $$ = "=="; }
               | diff_op     { $$ = "!="; }
               ;

VALEUR : ENTIER { $$ = $1; }
       | REEL   { $$ = $1; }
       ;

ENTIER : cst_int
         {
            $$.nom = $1;
            $$.type = "integer";
         }
       | parenthese_ouvrante SIGNE cst_int parenthese_fermante 
         {
            char t[50];
            sprintf(t, "%s%s", $2, $3);
            $$.nom = strdup(t);
            $$.type = "integer";
         } ;

REEL : cst_float
       {
            $$.nom = $1;
            $$.type = "float";
       }
     | parenthese_ouvrante SIGNE cst_float parenthese_fermante 
       {
            char t[50];
            sprintf(t, "%s%s", $2, $3);
            $$.nom = strdup(t);
            $$.type = "float";
       } ;

SIGNE : addition { $$ = "+"; } | sustra { $$ = "-"; } ;

%%

void erreurSemantique(char* message, char* entite) {
    extern int nb_ligne;
    extern int nb_colonne;
    printf("Erreur Semantique [L:%d, C:%d]: %s sur '%s'\n", nb_ligne, nb_colonne, message, entite);
}

void yyerror(const char *s) {
    extern int nb_ligne;
    fprintf(stderr, "Erreur syntaxique ligne %d: %s\n", nb_ligne, s);
}

int main() {
    initialiserTS();
    yyparse();
    afficherTS();
    afficher_qdr();
    return 0;
}
int yywrap() { return 1; }
