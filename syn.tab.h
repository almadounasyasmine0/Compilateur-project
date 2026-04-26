
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton interface for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.
   
   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* "%code requires" blocks.  */

/* Line 1676 of yacc.c  */
#line 38 "syn.y"

    typedef struct {
        char* nom;
        char* type;
    } Attribut;



/* Line 1676 of yacc.c  */
#line 49 "syn.tab.h"

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     OR_mc = 258,
     AND_mc = 259,
     NON_mc = 260,
     diff_op = 261,
     egal = 262,
     inf_egal = 263,
     sup_egal = 264,
     inferieure = 265,
     supperieure = 266,
     sustra = 267,
     addition = 268,
     div_op = 269,
     multipl = 270,
     BeginProject_mc = 271,
     EndProject_mc = 272,
     Setup_mc = 273,
     Run_mc = 274,
     define_mc = 275,
     const_mc = 276,
     int_mc = 277,
     float_mc = 278,
     if_mc = 279,
     then_mc = 280,
     else_mc = 281,
     endIf_mc = 282,
     loop_mc = 283,
     while_mc = 284,
     endloop_mc = 285,
     for_mc = 286,
     in_mc = 287,
     to_mc = 288,
     endfor_mc = 289,
     out_mc = 290,
     affectation = 291,
     barre_mc = 292,
     deux_points = 293,
     point_virg = 294,
     point = 295,
     virg = 296,
     parenthese_ouvrante = 297,
     parenthese_fermante = 298,
     accolade_ouvrante = 299,
     accolade_fermante = 300,
     crochet_ouvrant = 301,
     crochet_fermant = 302,
     idf = 303,
     cst_int = 304,
     cst_float = 305,
     chaine = 306
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 1676 of yacc.c  */
#line 45 "syn.y"

    char* str;
    char* v_type;
    Attribut attr;



/* Line 1676 of yacc.c  */
#line 125 "syn.tab.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;


