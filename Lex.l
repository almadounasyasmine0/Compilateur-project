%{
    #include "quad.h"
    #include "syn.tab.h"
    #include <string.h>
    int nb_ligne=1;
    int nb_colonne=1;
%}

/* Définitions */

/* IDF conforme : commence par lettre, min, chiffres, _, pas de __ au milieu, pas de _ à la fin */
Idf     [a-z]([a-z0-9]|(_[a-z0-9]))*

Integer [0-9]+
Float   [0-9]+\.[0-9]+
String  \"[^"]*\"

%%

"BeginProject" {nb_colonne+=yyleng; return BeginProject_mc;}
"Setup"        {nb_colonne+=yyleng; return Setup_mc;}
"Run"          {nb_colonne+=yyleng; return Run_mc;}
"EndProject"   {nb_colonne+=yyleng; return EndProject_mc;}
"define"       {nb_colonne+=yyleng; return define_mc;}
"integer"      {nb_colonne+=yyleng; return int_mc;}
"float"        {nb_colonne+=yyleng; return float_mc;}
"const"        {nb_colonne+=yyleng; return const_mc;}
"if"           {nb_colonne+=yyleng; return if_mc;}
"then"         {nb_colonne+=yyleng; return then_mc;}
"else"         {nb_colonne+=yyleng; return else_mc;}
"endIf"        {nb_colonne+=yyleng; return endIf_mc;}
"loop"         {nb_colonne+=yyleng; return loop_mc;}
"while"        {nb_colonne+=yyleng; return while_mc;}
"endloop"      {nb_colonne+=yyleng; return endloop_mc;}
"for"          {nb_colonne+=yyleng; return for_mc;}
"in"           {nb_colonne+=yyleng; return in_mc;}
"to"           {nb_colonne+=yyleng; return to_mc;}
"endfor"       {nb_colonne+=yyleng; return endfor_mc;}
"out"          {nb_colonne+=yyleng; return out_mc;}
"in"           {nb_colonne+=yyleng; return in_mc;}

"<-"           {nb_colonne+=yyleng; return affectation;}
":"            {nb_colonne+=yyleng; return deux_points;}
";"            {nb_colonne+=yyleng; return point_virg;}
"("            {nb_colonne+=yyleng; return parenthese_ouvrante;}
")"            {nb_colonne+=yyleng; return parenthese_fermante;}
"{"            {nb_colonne+=yyleng; return accolade_ouvrante;}
"}"            {nb_colonne+=yyleng; return accolade_fermante;}
"["            {nb_colonne+=yyleng; return crochet_ouvrant;}
"]"            {nb_colonne+=yyleng; return crochet_fermant;}

">="           {nb_colonne+=yyleng; return sup_egal;}
"<="           {nb_colonne+=yyleng; return inf_egal;}
"=="           {nb_colonne+=yyleng; return egal;}
">"            {nb_colonne+=yyleng; return supperieure;}
"<"            {nb_colonne+=yyleng; return inferieure;}
"!="           {nb_colonne+=yyleng; return diff_op;}

"+"            {nb_colonne+=yyleng; yylval.v_type = strdup(yytext); return addition;}
"-"            {nb_colonne+=yyleng; yylval.v_type = strdup(yytext); return sustra;}
"*"            {nb_colonne+=yyleng; return multipl;}
"/"            {nb_colonne+=yyleng; return div_op;}
"|"            {nb_colonne+=yyleng; return barre_mc;}
"."            {nb_colonne+=yyleng; return point;}
"="            {nb_colonne+=yyleng; return egal;}
","            {nb_colonne+=yyleng; return virg;}

"AND"          {nb_colonne+=yyleng; return AND_mc;}
"OR"           {nb_colonne+=yyleng; return OR_mc;}
"NON"          {nb_colonne+=yyleng; return NON_mc;}

"%%".* { /* Commentaire ligne : on ne fait rien */ }
"//*"([^*]|\*+[^*/])*\*+"//" { 
    /* Commentaire multi-ligne */
    for(int i=0; i<yyleng; i++) {
        if(yytext[i]=='\n') { nb_ligne++; nb_colonne=1; }
        else nb_colonne++;
    }
}

{Integer} {
    nb_colonne += yyleng; 
    yylval.v_type = strdup(yytext); 
    return cst_int; 
}

{Float} {
    nb_colonne += yyleng; 
    yylval.v_type = strdup(yytext); 
    return cst_float; 
}

{Idf} {
    if(yyleng > 14) {
        printf("Erreur Lexicale : Idf '%s' trop long (>14) a la ligne %d\n", yytext, nb_ligne);
    }
    nb_colonne += yyleng;
    yylval.v_type = strdup(yytext); 
    return idf;
}

{String}       {nb_colonne+=yyleng; return chaine;}

[ \t]          {nb_colonne++;}
\n             {nb_ligne++; nb_colonne=1;}
.              {printf("Erreur lexicale [L:%d, C:%d]: entite inconnue '%s'\n", nb_ligne, nb_colonne, yytext); nb_colonne++;}

%%