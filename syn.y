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
%}

%union {
    char* str;
    char* v_type; 
}

/* --- PRIORITÉS (Ordre croissant selon sujet) --- */
%left OR_mc
%left AND_mc
%left NON_mc
%left supperieure inferieure sup_egal inf_egal egal diff_op
%left addition sustra
%left multipl div_op

/* --- TYPES DES NON-TERMINAUX --- */
%type <v_type> TYPE EXPRESSION TERME FACTEUR ENTIER REEL VALEUR SIGNE

/* --- TOKENS --- */
%token BeginProject_mc EndProject_mc Setup_mc Run_mc
%token define_mc const_mc int_mc float_mc
%token if_mc then_mc else_mc endIf_mc
%token loop_mc while_mc endloop_mc for_mc in_mc to_mc endfor_mc
%token out_mc in_mc
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
                int t = atoi($4);
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
        double val = atof($6);
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
            if (strcmp($3, "error") != 0 && strcmp(e->type, $3) != 0) erreurSemantique("Incompatibilite de types", $1);
        }
    }
    | idf crochet_ouvrant ENTIER crochet_fermant affectation EXPRESSION point_virg
    {
        Element* e = rechercher($1);
        if (!e) erreurSemantique("Tableau non declare", $1);
        else if (strcmp(e->code, "Tableau") != 0) erreurSemantique("Pas un tableau", $1);
        else if (strcmp($6, "error") != 0 && strcmp(e->type, $6) != 0) erreurSemantique("Incompatibilite", $1);
    }
    ;

/* Syntaxe: if (cond) then: { ... } else { ... } endIf; */
INSTRUCTION_CONDITION : if_mc parenthese_ouvrante CONDITION parenthese_fermante then_mc deux_points 
                        accolade_ouvrante LISTE_INSTRUCTIONS accolade_fermante
                        else_mc accolade_ouvrante LISTE_INSTRUCTIONS accolade_fermante
                        endIf_mc point_virg ;

/* Syntaxe: for i in 1 to 10 { ... } endfor; */
INSTRUCTION_BOUCLE : loop_mc while_mc parenthese_ouvrante CONDITION parenthese_fermante 
                     accolade_ouvrante LISTE_INSTRUCTIONS accolade_fermante endloop_mc point_virg
                   | for_mc idf in_mc VALEUR to_mc VALEUR 
                     accolade_ouvrante LISTE_INSTRUCTIONS accolade_fermante endfor_mc point_virg ;

INSTRUCTION_IO : out_mc parenthese_ouvrante LISTE_OUT parenthese_fermante point_virg
               | in_mc parenthese_ouvrante idf parenthese_fermante point_virg ;

LISTE_OUT : chaine | chaine virg idf | idf ;

/* --- EXPRESSIONS ARITHMÉTIQUES --- */
EXPRESSION : EXPRESSION addition TERME 
             { if(strcmp($1,$3)!=0) { erreurSemantique("Incompatibilite types","+"); $$="error";} else $$=$1; }
           | EXPRESSION sustra TERME  
             { if(strcmp($1,$3)!=0) { erreurSemantique("Incompatibilite types","-"); $$="error";} else $$=$1; }
           | TERME { $$ = $1; }
           ;

TERME : TERME multipl FACTEUR { $$ = $1; }
      | TERME div_op FACTEUR  { $$ = $1; }
      | FACTEUR               { $$ = $1; }
      ;

FACTEUR : idf 
          { 
            Element* e = rechercher($1); 
            if(!e){ erreurSemantique("Non declare",$1); $$="error";} 
            else $$=e->type; 
          }
        | ENTIER { $$ = "integer"; }
        | REEL   { $$ = "float"; }
        | idf crochet_ouvrant ENTIER crochet_fermant 
          { 
            Element* e = rechercher($1); 
            if(!e || strcmp(e->code,"Tableau")!=0) { erreurSemantique("Erreur tableau",$1); $$="error"; } 
            else $$=e->type; 
          }
        | parenthese_ouvrante EXPRESSION parenthese_fermante { $$ = $2; }
        ;

/* --- LOGIQUE & COMPARAISON --- */
CONDITION : EXPRESSION OPERATEUR_COMP EXPRESSION
          | parenthese_ouvrante CONDITION parenthese_fermante
          | CONDITION AND_mc CONDITION
          | CONDITION OR_mc CONDITION
          | NON_mc CONDITION
          ;

OPERATEUR_COMP : supperieure | inferieure | sup_egal | inf_egal | egal | diff_op ;

VALEUR : ENTIER | REEL ;

ENTIER : cst_int | parenthese_ouvrante SIGNE cst_int parenthese_fermante 
         { char t[50]; sprintf(t,"%s%s",$2,$3); $$=strdup(t); } ;

REEL : cst_float | parenthese_ouvrante SIGNE cst_float parenthese_fermante 
       { char t[50]; sprintf(t,"%s%s",$2,$3); $$=strdup(t); } ;

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
    return 0;
}
int yywrap() { return 1; }