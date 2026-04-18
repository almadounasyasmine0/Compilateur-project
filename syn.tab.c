
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C
   
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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.4.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Copy the first part of user declarations.  */

/* Line 189 of yacc.c  */
#line 1 "syn.y"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ts.h"

/* --- VARIABLES ET DÉCLARATIONS C --- */
char saved_name[20];
int yylex();
void yyerror(const char *s);
void erreurSemantique(char* message, char* entite);


/* Line 189 of yacc.c  */
#line 87 "syn.tab.c"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif


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

/* Line 214 of yacc.c  */
#line 14 "syn.y"

    char* str;
    char* v_type; 



/* Line 214 of yacc.c  */
#line 181 "syn.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 193 "syn.tab.c"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   216

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  52
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  29
/* YYNRULES -- Number of rules.  */
#define YYNRULES  65
/* YYNRULES -- Number of states.  */
#define YYNSTATES  168

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   306

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint8 yyprhs[] =
{
       0,     0,     3,    11,    15,    18,    19,    21,    23,    24,
      32,    36,    37,    40,    46,    48,    50,    53,    54,    62,
      68,    71,    72,    74,    76,    78,    80,    85,    93,   109,
     120,   132,   138,   144,   146,   150,   152,   156,   160,   162,
     166,   170,   172,   174,   176,   178,   183,   187,   191,   195,
     199,   203,   206,   208,   210,   212,   214,   216,   218,   220,
     222,   224,   229,   231,   236,   238
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      53,     0,    -1,    16,    48,    39,    54,    64,    17,    39,
      -1,    18,    38,    55,    -1,    56,    55,    -1,    -1,    57,
      -1,    63,    -1,    -1,    20,    48,    58,    59,    38,    60,
      39,    -1,    37,    48,    59,    -1,    -1,    61,    62,    -1,
      46,    61,    39,    78,    47,    -1,    22,    -1,    23,    -1,
       7,    77,    -1,    -1,    21,    48,    38,    61,     7,    77,
      39,    -1,    19,    38,    44,    65,    45,    -1,    66,    65,
      -1,    -1,    67,    -1,    68,    -1,    69,    -1,    70,    -1,
      48,    36,    72,    39,    -1,    48,    46,    78,    47,    36,
      72,    39,    -1,    24,    42,    75,    43,    25,    38,    44,
      65,    45,    26,    44,    65,    45,    27,    39,    -1,    28,
      29,    42,    75,    43,    44,    65,    45,    30,    39,    -1,
      31,    48,    32,    77,    33,    77,    44,    65,    45,    34,
      39,    -1,    35,    42,    71,    43,    39,    -1,    32,    42,
      48,    43,    39,    -1,    51,    -1,    51,    41,    48,    -1,
      48,    -1,    72,    13,    73,    -1,    72,    12,    73,    -1,
      73,    -1,    73,    15,    74,    -1,    73,    14,    74,    -1,
      74,    -1,    48,    -1,    78,    -1,    79,    -1,    48,    46,
      78,    47,    -1,    42,    72,    43,    -1,    72,    76,    72,
      -1,    42,    75,    43,    -1,    75,     4,    75,    -1,    75,
       3,    75,    -1,     5,    75,    -1,    11,    -1,    10,    -1,
       9,    -1,     8,    -1,     7,    -1,     6,    -1,    78,    -1,
      79,    -1,    49,    -1,    42,    80,    49,    43,    -1,    50,
      -1,    42,    80,    50,    43,    -1,    13,    -1,    12,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    49,    49,    54,    56,    56,    58,    58,    61,    61,
      68,    73,    75,    79,    87,    88,    91,    91,    94,   108,
     110,   110,   112,   112,   112,   112,   114,   125,   135,   141,
     143,   146,   147,   149,   149,   149,   152,   154,   156,   159,
     160,   161,   164,   170,   171,   172,   178,   182,   183,   184,
     185,   186,   189,   189,   189,   189,   189,   189,   191,   191,
     193,   193,   196,   196,   199,   199
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "OR_mc", "AND_mc", "NON_mc", "diff_op",
  "egal", "inf_egal", "sup_egal", "inferieure", "supperieure", "sustra",
  "addition", "div_op", "multipl", "BeginProject_mc", "EndProject_mc",
  "Setup_mc", "Run_mc", "define_mc", "const_mc", "int_mc", "float_mc",
  "if_mc", "then_mc", "else_mc", "endIf_mc", "loop_mc", "while_mc",
  "endloop_mc", "for_mc", "in_mc", "to_mc", "endfor_mc", "out_mc",
  "affectation", "barre_mc", "deux_points", "point_virg", "point", "virg",
  "parenthese_ouvrante", "parenthese_fermante", "accolade_ouvrante",
  "accolade_fermante", "crochet_ouvrant", "crochet_fermant", "idf",
  "cst_int", "cst_float", "chaine", "$accept", "S", "SECTION_SETUP",
  "LISTE_DECLARATIONS", "UNE_DECLARATION", "DECL_DEFINE", "$@1",
  "LISTE_IDFS_SUITE", "SUITE_TYPE", "TYPE", "OPT_INIT", "DECL_CONSTANTE",
  "SECTION_RUN", "LISTE_INSTRUCTIONS", "UNE_INSTRUCTION",
  "INSTRUCTION_AFFECTATION", "INSTRUCTION_CONDITION", "INSTRUCTION_BOUCLE",
  "INSTRUCTION_IO", "LISTE_OUT", "EXPRESSION", "TERME", "FACTEUR",
  "CONDITION", "OPERATEUR_COMP", "VALEUR", "ENTIER", "REEL", "SIGNE", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    52,    53,    54,    55,    55,    56,    56,    58,    57,
      59,    59,    60,    60,    61,    61,    62,    62,    63,    64,
      65,    65,    66,    66,    66,    66,    67,    67,    68,    69,
      69,    70,    70,    71,    71,    71,    72,    72,    72,    73,
      73,    73,    74,    74,    74,    74,    74,    75,    75,    75,
      75,    75,    76,    76,    76,    76,    76,    76,    77,    77,
      78,    78,    79,    79,    80,    80
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     7,     3,     2,     0,     1,     1,     0,     7,
       3,     0,     2,     5,     1,     1,     2,     0,     7,     5,
       2,     0,     1,     1,     1,     1,     4,     7,    15,    10,
      11,     5,     5,     1,     3,     1,     3,     3,     1,     3,
       3,     1,     1,     1,     1,     4,     3,     3,     3,     3,
       3,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     4,     1,     4,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     1,     0,     0,     0,     5,     0,
       0,     0,     0,     3,     5,     6,     7,     0,     0,     8,
       0,     4,    21,     2,    11,     0,     0,     0,     0,     0,
       0,     0,     0,    21,    22,    23,    24,    25,     0,     0,
      14,    15,     0,     0,     0,     0,     0,     0,     0,     0,
      19,    20,    11,     0,     0,     0,     0,    42,    60,    62,
       0,    38,    41,     0,    43,    44,     0,     0,     0,    35,
      33,     0,     0,     0,     0,     0,    10,     0,     0,    17,
       0,     0,    58,    59,    51,    65,    64,     0,     0,     0,
       0,    57,    56,    55,    54,    53,    52,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    26,     0,     0,     0,     9,     0,    12,    18,    46,
      48,     0,     0,     0,    37,    36,    47,    40,    39,    50,
      49,     0,     0,     0,    32,    34,    31,     0,     0,    16,
      61,    63,    45,     0,    21,     0,     0,     0,    21,     0,
      21,    27,    13,     0,     0,     0,     0,     0,     0,     0,
      29,     0,    21,    30,     0,     0,     0,    28
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     2,     7,    13,    14,    15,    24,    39,    78,    42,
     117,    16,    10,    32,    33,    34,    35,    36,    37,    71,
      60,    61,    62,    63,    99,    81,    64,    65,    89
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -63
static const yytype_int16 yypact[] =
{
      -3,    -8,    38,    42,   -63,    59,    51,    82,    25,    78,
      97,    80,    84,   -63,    25,   -63,   -63,    89,    96,   -63,
      98,   -63,    52,   -63,   101,    76,    92,   108,    93,   102,
     103,   -11,    94,    52,   -63,   -63,   -63,   -63,    99,   104,
     -63,   -63,   133,    -1,   106,   111,   105,    27,    44,    55,
     -63,   -63,   101,    33,    53,    -1,     2,   109,   -63,   -63,
     112,    91,   -63,    14,   -63,   -63,    -1,    53,   107,   -63,
     110,   113,    24,    49,    95,   114,   -63,    76,   115,   139,
      95,   118,   -63,   -63,   -63,   -63,   -63,    21,    17,    60,
      55,   -63,   -63,   -63,   -63,   -63,   -63,    44,    44,    44,
      44,    44,    -1,    -1,   124,    20,   119,   120,   116,   121,
      -4,   -63,   117,   122,   123,   -63,    53,   -63,   -63,   -63,
     -63,   125,   126,   127,    91,    91,   100,   -63,   -63,   159,
     -63,   129,   128,    53,   -63,   -63,   -63,    44,    55,   -63,
     -63,   -63,   -63,   131,    52,   132,    57,   130,    52,   134,
      52,   -63,   -63,   135,   140,   136,   145,   143,   144,   141,
     -63,   147,    52,   -63,   138,   146,   148,   -63
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -63,   -63,   -63,   151,   -63,   -63,   -63,   137,   -63,   -10,
     -63,   -63,   -63,   -33,   -63,   -63,   -63,   -63,   -63,   -63,
     -46,    29,    30,   -44,   -63,   -62,   -48,   -51,   142
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      51,    75,    73,    83,    55,   106,    82,    55,    97,    98,
      87,    84,    88,     1,    85,    86,    83,   102,   103,    82,
     102,   103,   105,   102,   103,    48,   110,    91,    92,    93,
      94,    95,    96,    97,    98,    49,    85,    86,     4,   119,
       3,    56,   123,    79,    56,    11,    12,    57,    58,    59,
      57,    58,    59,   126,   139,    40,    41,   104,   129,   130,
     120,    97,    98,   132,   119,    83,    72,   114,    82,    97,
      98,   145,    57,    58,    59,    69,    26,     6,    70,    77,
      27,     5,    83,    28,    29,    82,    72,    30,   111,     8,
     147,   146,    57,    58,    59,    80,   151,    74,    40,    41,
      31,     9,    58,    59,    58,   100,   101,    85,    86,   121,
     122,   149,    97,    98,    18,   153,    17,   155,    91,    92,
      93,    94,    95,    96,    97,    98,   124,   125,    19,   164,
     127,   128,    20,    22,    43,    23,    25,    44,    38,    50,
      54,    45,    53,    67,    46,    47,   116,    52,    66,   131,
     107,   108,   133,    68,   115,    90,   109,   118,   137,   134,
     136,   113,   138,   103,   135,    21,   121,   143,   140,   141,
     157,   159,   144,   166,   142,   148,   150,   152,   161,   154,
     156,   158,   160,   165,     0,   162,   163,   167,     0,    76,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   112
};

static const yytype_int16 yycheck[] =
{
      33,    49,    48,    54,     5,    67,    54,     5,    12,    13,
      56,    55,    56,    16,    12,    13,    67,     3,     4,    67,
       3,     4,    66,     3,     4,    36,    72,     6,     7,     8,
       9,    10,    11,    12,    13,    46,    12,    13,     0,    43,
      48,    42,    90,    53,    42,    20,    21,    48,    49,    50,
      48,    49,    50,    99,   116,    22,    23,    43,   102,   103,
      43,    12,    13,    43,    43,   116,    42,    77,   116,    12,
      13,   133,    48,    49,    50,    48,    24,    18,    51,    46,
      28,    39,   133,    31,    32,   133,    42,    35,    39,    38,
     138,   137,    48,    49,    50,    42,    39,    42,    22,    23,
      48,    19,    49,    50,    49,    14,    15,    12,    13,    49,
      50,   144,    12,    13,    17,   148,    38,   150,     6,     7,
       8,     9,    10,    11,    12,    13,    97,    98,    48,   162,
     100,   101,    48,    44,    42,    39,    38,    29,    37,    45,
       7,    48,    38,    32,    42,    42,     7,    48,    42,    25,
      43,    41,    33,    48,    39,    46,    43,    39,    36,    39,
      39,    47,    39,     4,    48,    14,    49,    38,    43,    43,
      30,    26,    44,    27,    47,    44,    44,    47,    34,    45,
      45,    45,    39,    45,    -1,    44,    39,    39,    -1,    52,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    74
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    16,    53,    48,     0,    39,    18,    54,    38,    19,
      64,    20,    21,    55,    56,    57,    63,    38,    17,    48,
      48,    55,    44,    39,    58,    38,    24,    28,    31,    32,
      35,    48,    65,    66,    67,    68,    69,    70,    37,    59,
      22,    23,    61,    42,    29,    48,    42,    42,    36,    46,
      45,    65,    48,    38,     7,     5,    42,    48,    49,    50,
      72,    73,    74,    75,    78,    79,    42,    32,    48,    48,
      51,    71,    42,    72,    42,    78,    59,    46,    60,    61,
      42,    77,    78,    79,    75,    12,    13,    72,    75,    80,
      46,     6,     7,     8,     9,    10,    11,    12,    13,    76,
      14,    15,     3,     4,    43,    75,    77,    43,    41,    43,
      72,    39,    80,    47,    61,    39,     7,    62,    39,    43,
      43,    49,    50,    78,    73,    73,    72,    74,    74,    75,
      75,    25,    43,    33,    39,    48,    39,    36,    39,    77,
      43,    43,    47,    38,    44,    77,    72,    78,    44,    65,
      44,    39,    47,    65,    45,    65,    45,    30,    45,    26,
      39,    34,    44,    39,    65,    45,    27,    39
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif



#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
	switch (*++yyp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++yyp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}

/* Prevent warnings from -Wmissing-prototypes.  */
#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*-------------------------.
| yyparse or yypush_parse.  |
`-------------------------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{


    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks thru separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */
  yyssp = yyss;
  yyvsp = yyvs;

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;

	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),
		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss_alloc, yyss);
	YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:

/* Line 1455 of yacc.c  */
#line 50 "syn.y"
    { printf("Felicitations : La structure du programme ProLang est valide !\n"); ;}
    break;

  case 8:

/* Line 1455 of yacc.c  */
#line 61 "syn.y"
    { 
                if (rechercher((yyvsp[(2) - (2)].str)) == NULL) inserer((yyvsp[(2) - (2)].str), "Variable", "attente", 0, 0);
                else erreurSemantique("Double declaration", (yyvsp[(2) - (2)].str));
                strcpy(saved_name, (yyvsp[(2) - (2)].str)); 
              ;}
    break;

  case 10:

/* Line 1455 of yacc.c  */
#line 69 "syn.y"
    {
                    if (rechercher((yyvsp[(2) - (3)].str)) == NULL) inserer((yyvsp[(2) - (3)].str), "Variable", "attente", 0, 0);
                    else erreurSemantique("Double declaration", (yyvsp[(2) - (3)].str));
                 ;}
    break;

  case 12:

/* Line 1455 of yacc.c  */
#line 76 "syn.y"
    { 
                mettreAjourType("attente", (yyvsp[(1) - (2)].v_type), 0);
            ;}
    break;

  case 13:

/* Line 1455 of yacc.c  */
#line 80 "syn.y"
    { 
                int t = atoi((yyvsp[(4) - (5)].v_type));
                if (t <= 0) erreurSemantique("Taille tableau doit etre > 0", "Tableau");
                mettreAjourType("attente", (yyvsp[(2) - (5)].v_type), t); 
            ;}
    break;

  case 14:

/* Line 1455 of yacc.c  */
#line 87 "syn.y"
    { (yyval.v_type) = "integer"; ;}
    break;

  case 15:

/* Line 1455 of yacc.c  */
#line 88 "syn.y"
    { (yyval.v_type) = "float"; ;}
    break;

  case 18:

/* Line 1455 of yacc.c  */
#line 95 "syn.y"
    {
    if (rechercher((yyvsp[(2) - (7)].str)) == NULL) {
        double val = atof((yyvsp[(6) - (7)].v_type));
        if (strcmp((yyvsp[(4) - (7)].v_type), "integer") == 0 && (val < -32768 || val > 32767)) {
            erreurSemantique("Valeur hors intervalle [-32768, 32767]", (yyvsp[(2) - (7)].str));
            val = 0;
        }
        inserer((yyvsp[(2) - (7)].str), "Constante", (yyvsp[(4) - (7)].v_type), (float)val, 0);
    } else erreurSemantique("Constante deja declaree", (yyvsp[(2) - (7)].str));
;}
    break;

  case 26:

/* Line 1455 of yacc.c  */
#line 115 "syn.y"
    {
        Element* e = rechercher((yyvsp[(1) - (4)].str));
        if (!e) erreurSemantique("Variable non declaree", (yyvsp[(1) - (4)].str));
        else {
            // VERIF: Modification de constante
            if (strcmp(e->code, "Constante") == 0) erreurSemantique("Interdit de modifier une constante", (yyvsp[(1) - (4)].str));
            // VERIF: Compatibilité de types (ex: float vers int)
            if (strcmp((yyvsp[(3) - (4)].v_type), "error") != 0 && strcmp(e->type, (yyvsp[(3) - (4)].v_type)) != 0) erreurSemantique("Incompatibilite de types", (yyvsp[(1) - (4)].str));
        }
    ;}
    break;

  case 27:

/* Line 1455 of yacc.c  */
#line 126 "syn.y"
    {
        Element* e = rechercher((yyvsp[(1) - (7)].str));
        if (!e) erreurSemantique("Tableau non declare", (yyvsp[(1) - (7)].str));
        else if (strcmp(e->code, "Tableau") != 0) erreurSemantique("Pas un tableau", (yyvsp[(1) - (7)].str));
        else if (strcmp((yyvsp[(6) - (7)].v_type), "error") != 0 && strcmp(e->type, (yyvsp[(6) - (7)].v_type)) != 0) erreurSemantique("Incompatibilite", (yyvsp[(1) - (7)].str));
    ;}
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 153 "syn.y"
    { if(strcmp((yyvsp[(1) - (3)].v_type),(yyvsp[(3) - (3)].v_type))!=0) { erreurSemantique("Incompatibilite types","+"); (yyval.v_type)="error";} else (yyval.v_type)=(yyvsp[(1) - (3)].v_type); ;}
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 155 "syn.y"
    { if(strcmp((yyvsp[(1) - (3)].v_type),(yyvsp[(3) - (3)].v_type))!=0) { erreurSemantique("Incompatibilite types","-"); (yyval.v_type)="error";} else (yyval.v_type)=(yyvsp[(1) - (3)].v_type); ;}
    break;

  case 38:

/* Line 1455 of yacc.c  */
#line 156 "syn.y"
    { (yyval.v_type) = (yyvsp[(1) - (1)].v_type); ;}
    break;

  case 39:

/* Line 1455 of yacc.c  */
#line 159 "syn.y"
    { (yyval.v_type) = (yyvsp[(1) - (3)].v_type); ;}
    break;

  case 40:

/* Line 1455 of yacc.c  */
#line 160 "syn.y"
    { (yyval.v_type) = (yyvsp[(1) - (3)].v_type); ;}
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 161 "syn.y"
    { (yyval.v_type) = (yyvsp[(1) - (1)].v_type); ;}
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 165 "syn.y"
    { 
            Element* e = rechercher((yyvsp[(1) - (1)].str)); 
            if(!e){ erreurSemantique("Non declare",(yyvsp[(1) - (1)].str)); (yyval.v_type)="error";} 
            else (yyval.v_type)=e->type; 
          ;}
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 170 "syn.y"
    { (yyval.v_type) = "integer"; ;}
    break;

  case 44:

/* Line 1455 of yacc.c  */
#line 171 "syn.y"
    { (yyval.v_type) = "float"; ;}
    break;

  case 45:

/* Line 1455 of yacc.c  */
#line 173 "syn.y"
    { 
            Element* e = rechercher((yyvsp[(1) - (4)].str)); 
            if(!e || strcmp(e->code,"Tableau")!=0) { erreurSemantique("Erreur tableau",(yyvsp[(1) - (4)].str)); (yyval.v_type)="error"; } 
            else (yyval.v_type)=e->type; 
          ;}
    break;

  case 46:

/* Line 1455 of yacc.c  */
#line 178 "syn.y"
    { (yyval.v_type) = (yyvsp[(2) - (3)].v_type); ;}
    break;

  case 61:

/* Line 1455 of yacc.c  */
#line 194 "syn.y"
    { char t[50]; sprintf(t,"%s%s",(yyvsp[(2) - (4)].v_type),(yyvsp[(3) - (4)].str)); (yyval.v_type)=strdup(t); ;}
    break;

  case 63:

/* Line 1455 of yacc.c  */
#line 197 "syn.y"
    { char t[50]; sprintf(t,"%s%s",(yyvsp[(2) - (4)].v_type),(yyvsp[(3) - (4)].str)); (yyval.v_type)=strdup(t); ;}
    break;

  case 64:

/* Line 1455 of yacc.c  */
#line 199 "syn.y"
    { (yyval.v_type) = "+"; ;}
    break;

  case 65:

/* Line 1455 of yacc.c  */
#line 199 "syn.y"
    { (yyval.v_type) = "-"; ;}
    break;



/* Line 1455 of yacc.c  */
#line 1754 "syn.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
	 error, discard it.  */

      if (yychar <= YYEOF)
	{
	  /* Return failure if at end of input.  */
	  if (yychar == YYEOF)
	    YYABORT;
	}
      else
	{
	  yydestruct ("Error: discarding",
		      yytoken, &yylval);
	  yychar = YYEMPTY;
	}
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
	    {
	      yyn = yytable[yyn];
	      if (0 < yyn)
		break;
	    }
	}

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
	YYABORT;


      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  *++yyvsp = yylval;


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined(yyoverflow) || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}



/* Line 1675 of yacc.c  */
#line 201 "syn.y"


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
