/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

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
#define YYBISON_VERSION "2.3"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     SUB = 258,
     SUM = 259,
     REST = 260,
     DIV = 261,
     MULT = 262,
     OR = 263,
     AND = 264,
     NEG = 265,
     FUNCTION = 266,
     INTEGER = 267,
     BOOLEAN = 268,
     DOUBLE = 269,
     CHARACTER = 270,
     DECLARE = 271,
     IN = 272,
     END = 273,
     GLOBAL = 274,
     CALL = 275,
     MAIN = 276,
     PRINT = 277,
     SEMI_COLON = 278,
     IF = 279,
     ELSE = 280,
     FOR = 281,
     WHILE = 282,
     READINT = 283,
     READDOUBLE = 284,
     OPEN_BRACKET = 285,
     CLOSE_BRACKET = 286,
     COLON = 287,
     MENOR = 288,
     MAIOR = 289,
     DIFERENTE = 290,
     MAIORIGUAL = 291,
     MENORIGUAL = 292,
     ASSIGN = 293,
     IGUAL = 294,
     READCHAR = 295,
     NOT = 296,
     RETURN = 297,
     IDENTIFIER = 298,
     VALOR_INTEIRO = 299,
     VALOR_CHAR = 300,
     VALOR_DOUBLE = 301,
     VALOR_BOOLEAN = 302
   };
#endif
/* Tokens.  */
#define SUB 258
#define SUM 259
#define REST 260
#define DIV 261
#define MULT 262
#define OR 263
#define AND 264
#define NEG 265
#define FUNCTION 266
#define INTEGER 267
#define BOOLEAN 268
#define DOUBLE 269
#define CHARACTER 270
#define DECLARE 271
#define IN 272
#define END 273
#define GLOBAL 274
#define CALL 275
#define MAIN 276
#define PRINT 277
#define SEMI_COLON 278
#define IF 279
#define ELSE 280
#define FOR 281
#define WHILE 282
#define READINT 283
#define READDOUBLE 284
#define OPEN_BRACKET 285
#define CLOSE_BRACKET 286
#define COLON 287
#define MENOR 288
#define MAIOR 289
#define DIFERENTE 290
#define MAIORIGUAL 291
#define MENORIGUAL 292
#define ASSIGN 293
#define IGUAL 294
#define READCHAR 295
#define NOT 296
#define RETURN 297
#define IDENTIFIER 298
#define VALOR_INTEIRO 299
#define VALOR_CHAR 300
#define VALOR_DOUBLE 301
#define VALOR_BOOLEAN 302




/* Copy the first part of user declarations.  */
#line 1 "ficha10.exemplo.y"

#include <stdio.h>
#include <stdlib.h>
#include "symbol_table.h"
#include <string.h>
#include "structures.h"
#include "functions.h"
#include "semantic.h"

void show_table(table_element*);

is_block_list* myprog;
prog_env* prog_environment;
is_assgn_stat_2 *variaveis;

int n_while=0;
int n_if=0;
int n_for=0;


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

#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 58 "ficha10.exemplo.y"
{
char* id;
char* valord;
char* valori;
int inteiro;
char character;
double doub;
boolean bool;
is_block_list* ipl;
is_block* ip;
is_vardec_list* ivl;
is_vardec* iv;
is_statement_list* isl;
is_statement* is;
is_call_stat* ics;
is_write_stat* iws;
is_assgn_stat* ias;
is_if_stat* ifs;
is_for_stat* ifrs;
is_if_else_stat* ifes;
is_while_stat* iwls;
is_expression* iex;
is_expression_list* iexl;
is_call_arg *ica;
is_call_arg_list *ical;
is_args_vardec *iav;
is_args_vardec_list *iavl;
is_return_statement* irs;
}
/* Line 187 of yacc.c.  */
#line 240 "y.tab.c"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 253 "y.tab.c"

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
YYID (int i)
#else
static int
YYID (i)
    int i;
#endif
{
  return i;
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
  yytype_int16 yyss;
  YYSTYPE yyvs;
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
# define YYSTACK_RELOCATE(Stack)					\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack, Stack, yysize);				\
	Stack = &yyptr->Stack;						\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  8
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   277

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  48
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  21
/* YYNRULES -- Number of rules.  */
#define YYNRULES  73
/* YYNRULES -- Number of states.  */
#define YYNSTATES  143

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   302

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
      45,    46,    47
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint8 yyprhs[] =
{
       0,     0,     3,     6,     8,    17,    27,    31,    32,    35,
      38,    41,    44,    47,    48,    51,    55,    59,    63,    67,
      68,    71,    73,    75,    77,    79,    81,    83,    85,    87,
      91,   102,   110,   118,   129,   130,   133,   135,   137,   139,
     141,   143,   150,   154,   158,   162,   166,   170,   175,   180,
     185,   190,   195,   200,   201,   204,   206,   208,   210,   212,
     214,   216,   218,   220,   222,   224,   226,   228,   230,   232,
     234,   236,   238,   240
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      49,     0,    -1,    49,    50,    -1,    50,    -1,    11,    21,
      30,    31,    32,    53,    55,    18,    -1,    11,    43,    30,
      51,    31,    32,    53,    55,    18,    -1,    19,    53,    18,
      -1,    -1,    51,    52,    -1,    12,    43,    -1,    15,    43,
      -1,    14,    43,    -1,    13,    43,    -1,    -1,    53,    54,
      -1,    12,    43,    23,    -1,    15,    43,    23,    -1,    14,
      43,    23,    -1,    13,    43,    23,    -1,    -1,    55,    56,
      -1,    65,    -1,    66,    -1,    64,    -1,    61,    -1,    60,
      -1,    59,    -1,    58,    -1,    57,    -1,    42,    43,    23,
      -1,    26,    30,    56,    67,    23,    56,    31,    32,    55,
      18,    -1,    27,    30,    67,    31,    32,    55,    18,    -1,
      24,    30,    67,    31,    32,    55,    18,    -1,    24,    30,
      67,    31,    32,    55,    25,    32,    55,    18,    -1,    -1,
      62,    63,    -1,    43,    -1,    44,    -1,    46,    -1,    45,
      -1,    47,    -1,    20,    43,    30,    62,    31,    23,    -1,
      22,    43,    23,    -1,    22,    44,    23,    -1,    22,    46,
      23,    -1,    22,    45,    23,    -1,    22,    47,    23,    -1,
      43,    38,    45,    23,    -1,    43,    38,    67,    23,    -1,
      43,    38,    47,    23,    -1,    43,    38,    28,    23,    -1,
      43,    38,    29,    23,    -1,    43,    38,    40,    23,    -1,
      -1,    67,    68,    -1,    44,    -1,    46,    -1,     4,    -1,
       6,    -1,     7,    -1,     5,    -1,     8,    -1,     9,    -1,
      30,    -1,    31,    -1,     3,    -1,    43,    -1,    34,    -1,
      36,    -1,    33,    -1,    37,    -1,    39,    -1,    35,    -1,
      41,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    89,    89,    90,    93,    94,    95,    98,    99,   102,
     103,   104,   105,   109,   110,   113,   114,   115,   116,   119,
     120,   123,   124,   125,   126,   127,   128,   129,   130,   133,
     136,   140,   143,   146,   149,   150,   153,   154,   155,   156,
     157,   161,   164,   165,   166,   167,   168,   173,   174,   175,
     176,   177,   178,   181,   182,   185,   186,   187,   188,   189,
     190,   191,   192,   193,   194,   195,   196,   197,   198,   199,
     200,   201,   202,   203
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "SUB", "SUM", "REST", "DIV", "MULT",
  "OR", "AND", "NEG", "FUNCTION", "INTEGER", "BOOLEAN", "DOUBLE",
  "CHARACTER", "DECLARE", "IN", "END", "GLOBAL", "CALL", "MAIN", "PRINT",
  "SEMI_COLON", "IF", "ELSE", "FOR", "WHILE", "READINT", "READDOUBLE",
  "OPEN_BRACKET", "CLOSE_BRACKET", "COLON", "MENOR", "MAIOR", "DIFERENTE",
  "MAIORIGUAL", "MENORIGUAL", "ASSIGN", "IGUAL", "READCHAR", "NOT",
  "RETURN", "IDENTIFIER", "VALOR_INTEIRO", "VALOR_CHAR", "VALOR_DOUBLE",
  "VALOR_BOOLEAN", "$accept", "block_list", "block", "args_vardec_list",
  "args_vardec", "vardeclist", "vardec", "statement_list", "statement",
  "return_stat", "for_stat", "while_stat", "if_stat", "if_else_stat",
  "call_argslist", "call_args", "call_stat", "print_stat", "assgn_stat",
  "expression_list", "expression", 0
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
     295,   296,   297,   298,   299,   300,   301,   302
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    48,    49,    49,    50,    50,    50,    51,    51,    52,
      52,    52,    52,    53,    53,    54,    54,    54,    54,    55,
      55,    56,    56,    56,    56,    56,    56,    56,    56,    57,
      58,    59,    60,    61,    62,    62,    63,    63,    63,    63,
      63,    64,    65,    65,    65,    65,    65,    66,    66,    66,
      66,    66,    66,    67,    67,    68,    68,    68,    68,    68,
      68,    68,    68,    68,    68,    68,    68,    68,    68,    68,
      68,    68,    68,    68
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     1,     8,     9,     3,     0,     2,     2,
       2,     2,     2,     0,     2,     3,     3,     3,     3,     0,
       2,     1,     1,     1,     1,     1,     1,     1,     1,     3,
      10,     7,     7,    10,     0,     2,     1,     1,     1,     1,
       1,     6,     3,     3,     3,     3,     3,     4,     4,     4,
       4,     4,     4,     0,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,    13,     0,     3,     0,     0,     0,     1,     2,
       0,     7,     0,     0,     0,     0,     6,    14,     0,     0,
       0,     0,     0,     0,    13,     0,     0,     0,     0,     0,
       8,    15,    18,    17,    16,    19,     9,    12,    11,    10,
      13,     0,    19,     4,     0,     0,     0,     0,     0,     0,
       0,    20,    28,    27,    26,    25,    24,    23,    21,    22,
       0,     0,     0,     0,     0,     0,     0,    53,     0,    53,
       0,    53,     5,    34,    42,    43,    45,    44,    46,     0,
      53,     0,    29,     0,     0,     0,     0,     0,     0,     0,
      65,    57,    60,    58,    59,    61,    62,    63,    64,    69,
      67,    72,    68,    70,    71,    73,    66,    55,    56,    54,
       0,    64,    50,    51,    52,    47,    49,    48,    64,     0,
      36,    37,    39,    38,    40,    35,    19,     0,    19,    41,
       0,     0,     0,    32,     0,     0,    31,    19,    19,     0,
       0,    33,    30
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     3,     4,    19,    30,     7,    17,    41,    51,    52,
      53,    54,    55,    56,    89,   125,    57,    58,    59,    79,
     109
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -68
static const yytype_int16 yypact[] =
{
      45,   -12,   -68,    46,   -68,   -13,     9,    92,   -68,   -68,
     -21,   -68,    -2,    15,    19,    20,   -68,   -68,    36,     6,
      49,    53,    59,    66,   -68,    65,    68,    69,    70,    37,
     -68,   -68,   -68,   -68,   -68,    79,   -68,   -68,   -68,   -68,
     -68,   148,    79,   -68,    78,   -31,    93,    96,   102,    91,
      71,   -68,   -68,   -68,   -68,   -68,   -68,   -68,   -68,   -68,
     174,   106,    99,   116,   120,   126,   128,   -68,   234,   -68,
     130,    26,   -68,   -68,   -68,   -68,   -68,   -68,   -68,    94,
     -68,   111,   -68,   136,   144,   146,   150,   153,    -1,   -20,
     -68,   -68,   -68,   -68,   -68,   -68,   -68,   -68,   129,   -68,
     -68,   -68,   -68,   -68,   -68,   -68,   -68,   -68,   -68,   -68,
      44,   139,   -68,   -68,   -68,   -68,   -68,   -68,   -68,   154,
     -68,   -68,   -68,   -68,   -68,   -68,   -68,   234,   -68,   -68,
     138,   147,   184,   -68,   151,   152,   -68,   -68,   -68,   210,
     220,   -68,   -68
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -68,   -68,   176,   -68,   -68,     4,   -68,   -42,   -67,   -68,
     -68,   -68,   -68,   -68,   -68,   -68,   -68,   -68,   -68,   -10,
     -68
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      60,    80,    90,    91,    92,    93,    94,    95,    96,     5,
      18,   119,    62,    63,    64,    65,    66,    10,    25,    26,
      27,    28,   117,   120,   121,   122,   123,   124,    35,    97,
     118,     6,    99,   100,   101,   102,   103,    29,   104,    11,
     105,    20,   106,   107,    42,   108,     8,    90,    91,    92,
      93,    94,    95,    96,    83,    84,     1,     1,    21,    81,
     131,    88,    22,    23,     2,     2,    85,   127,    24,    40,
     110,    86,    31,    87,    97,   118,    32,    99,   100,   101,
     102,   103,    33,   104,   130,   105,   132,   106,   107,    34,
     108,    12,    13,    14,    15,   139,   140,    90,    91,    92,
      93,    94,    95,    96,    12,    13,    14,    15,    36,    71,
      16,    37,    38,    39,    90,    91,    92,    93,    94,    95,
      96,    61,    74,    67,    97,    98,    68,    99,   100,   101,
     102,   103,    69,   104,    70,   105,    73,   106,   107,    75,
     108,    97,   111,    76,    99,   100,   101,   102,   103,    77,
     104,    78,   105,    82,   106,   107,   133,   108,    44,   112,
      45,   126,    46,   134,    47,    48,    43,   113,    44,   114,
      45,   128,    46,   115,    47,    48,   116,   129,   135,     9,
      49,    50,     0,   137,   138,     0,     0,     0,     0,     0,
      49,    50,    72,     0,    44,     0,    45,     0,    46,     0,
      47,    48,   136,     0,    44,     0,    45,     0,    46,     0,
      47,    48,     0,     0,     0,     0,    49,    50,     0,     0,
       0,     0,     0,     0,     0,     0,    49,    50,   141,     0,
      44,     0,    45,     0,    46,     0,    47,    48,   142,     0,
      44,     0,    45,     0,    46,     0,    47,    48,     0,     0,
       0,     0,    49,    50,    44,     0,    45,     0,    46,     0,
      47,    48,    49,    50,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    49,    50
};

static const yytype_int16 yycheck[] =
{
      42,    68,     3,     4,     5,     6,     7,     8,     9,    21,
      31,    31,    43,    44,    45,    46,    47,    30,    12,    13,
      14,    15,    23,    43,    44,    45,    46,    47,    24,    30,
      31,    43,    33,    34,    35,    36,    37,    31,    39,    30,
      41,    43,    43,    44,    40,    46,     0,     3,     4,     5,
       6,     7,     8,     9,    28,    29,    11,    11,    43,    69,
     127,    71,    43,    43,    19,    19,    40,    23,    32,    32,
      80,    45,    23,    47,    30,    31,    23,    33,    34,    35,
      36,    37,    23,    39,   126,    41,   128,    43,    44,    23,
      46,    12,    13,    14,    15,   137,   138,     3,     4,     5,
       6,     7,     8,     9,    12,    13,    14,    15,    43,    38,
      18,    43,    43,    43,     3,     4,     5,     6,     7,     8,
       9,    43,    23,    30,    30,    31,    30,    33,    34,    35,
      36,    37,    30,    39,    43,    41,    30,    43,    44,    23,
      46,    30,    31,    23,    33,    34,    35,    36,    37,    23,
      39,    23,    41,    23,    43,    44,    18,    46,    20,    23,
      22,    32,    24,    25,    26,    27,    18,    23,    20,    23,
      22,    32,    24,    23,    26,    27,    23,    23,    31,     3,
      42,    43,    -1,    32,    32,    -1,    -1,    -1,    -1,    -1,
      42,    43,    18,    -1,    20,    -1,    22,    -1,    24,    -1,
      26,    27,    18,    -1,    20,    -1,    22,    -1,    24,    -1,
      26,    27,    -1,    -1,    -1,    -1,    42,    43,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    42,    43,    18,    -1,
      20,    -1,    22,    -1,    24,    -1,    26,    27,    18,    -1,
      20,    -1,    22,    -1,    24,    -1,    26,    27,    -1,    -1,
      -1,    -1,    42,    43,    20,    -1,    22,    -1,    24,    -1,
      26,    27,    42,    43,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    42,    43
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    11,    19,    49,    50,    21,    43,    53,     0,    50,
      30,    30,    12,    13,    14,    15,    18,    54,    31,    51,
      43,    43,    43,    43,    32,    12,    13,    14,    15,    31,
      52,    23,    23,    23,    23,    53,    43,    43,    43,    43,
      32,    55,    53,    18,    20,    22,    24,    26,    27,    42,
      43,    56,    57,    58,    59,    60,    61,    64,    65,    66,
      55,    43,    43,    44,    45,    46,    47,    30,    30,    30,
      43,    38,    18,    30,    23,    23,    23,    23,    23,    67,
      56,    67,    23,    28,    29,    40,    45,    47,    67,    62,
       3,     4,     5,     6,     7,     8,     9,    30,    31,    33,
      34,    35,    36,    37,    39,    41,    43,    44,    46,    68,
      67,    31,    23,    23,    23,    23,    23,    23,    31,    31,
      43,    44,    45,    46,    47,    63,    32,    23,    32,    23,
      55,    56,    55,    18,    25,    31,    18,    32,    32,    55,
      55,    18,    18
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
yy_stack_print (yytype_int16 *bottom, yytype_int16 *top)
#else
static void
yy_stack_print (bottom, top)
    yytype_int16 *bottom;
    yytype_int16 *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
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
      fprintf (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      fprintf (stderr, "\n");
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



/* The look-ahead symbol.  */
int yychar;

/* The semantic value of the look-ahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*----------.
| yyparse.  |
`----------*/

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
  int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Look-ahead token as an internal (translated) token number.  */
  int yytoken = 0;
#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  yytype_int16 yyssa[YYINITDEPTH];
  yytype_int16 *yyss = yyssa;
  yytype_int16 *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  YYSTYPE *yyvsp;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;


  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

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
	YYSTACK_RELOCATE (yyss);
	YYSTACK_RELOCATE (yyvs);

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

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     look-ahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to look-ahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a look-ahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid look-ahead symbol.  */
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

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the look-ahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token unless it is eof.  */
  if (yychar != YYEOF)
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
#line 89 "ficha10.exemplo.y"
    {(yyval.ipl)=insert_block_list((yyvsp[(1) - (2)].ipl), (yyvsp[(2) - (2)].ip));}
    break;

  case 3:
#line 90 "ficha10.exemplo.y"
    {deleteAll(variaveis);variaveis = NULL;(yyval.ipl)=insert_block_list(NULL, (yyvsp[(1) - (1)].ip));
						myprog=(yyval.ipl);}
    break;

  case 4:
#line 93 "ficha10.exemplo.y"
    {(yyval.ip)=insert_procedure("main",NULL, (yyvsp[(6) - (8)].ivl), (yyvsp[(7) - (8)].isl));}
    break;

  case 5:
#line 94 "ficha10.exemplo.y"
    {(yyval.ip)=insert_procedure((yyvsp[(2) - (9)].id),(yyvsp[(4) - (9)].iavl), (yyvsp[(7) - (9)].ivl), (yyvsp[(8) - (9)].isl));}
    break;

  case 6:
#line 95 "ficha10.exemplo.y"
    {(yyval.ip)=insert_globals((yyvsp[(2) - (3)].ivl));}
    break;

  case 7:
#line 98 "ficha10.exemplo.y"
    {(yyval.iavl)=NULL;}
    break;

  case 8:
#line 99 "ficha10.exemplo.y"
    {(yyval.iavl)=insert_arg_vardec_list((yyvsp[(1) - (2)].iavl),(yyvsp[(2) - (2)].iav));}
    break;

  case 9:
#line 102 "ficha10.exemplo.y"
    {(yyval.iav)=insert_arg_vardec(line,integer,(yyvsp[(2) - (2)].id));}
    break;

  case 10:
#line 103 "ficha10.exemplo.y"
    {(yyval.iav)=insert_arg_vardec(line,character,(yyvsp[(2) - (2)].id));}
    break;

  case 11:
#line 104 "ficha10.exemplo.y"
    {(yyval.iav)=insert_arg_vardec(line,doub,(yyvsp[(2) - (2)].id));}
    break;

  case 12:
#line 105 "ficha10.exemplo.y"
    {(yyval.iav)=insert_arg_vardec(line,bool,(yyvsp[(2) - (2)].id));}
    break;

  case 13:
#line 109 "ficha10.exemplo.y"
    {(yyval.ivl)=NULL;}
    break;

  case 14:
#line 110 "ficha10.exemplo.y"
    {(yyval.ivl)=insert_vardec_list((yyvsp[(1) - (2)].ivl), (yyvsp[(2) - (2)].iv));}
    break;

  case 15:
#line 113 "ficha10.exemplo.y"
    {variaveis=update_variaveis(variaveis,(yyvsp[(2) - (3)].id),integer);(yyval.iv)=insert_vardec(line, integer, (yyvsp[(2) - (3)].id));}
    break;

  case 16:
#line 114 "ficha10.exemplo.y"
    {(yyval.iv)=insert_vardec(line, character, (yyvsp[(2) - (3)].id));}
    break;

  case 17:
#line 115 "ficha10.exemplo.y"
    {variaveis=update_variaveis(variaveis,(yyvsp[(2) - (3)].id),doub);(yyval.iv)=insert_vardec(line, doub, (yyvsp[(2) - (3)].id));}
    break;

  case 18:
#line 116 "ficha10.exemplo.y"
    {(yyval.iv)=insert_vardec(line, bool, (yyvsp[(2) - (3)].id));}
    break;

  case 19:
#line 119 "ficha10.exemplo.y"
    {(yyval.isl)=NULL;}
    break;

  case 20:
#line 120 "ficha10.exemplo.y"
    {(yyval.isl)=insert_statement_list((yyvsp[(1) - (2)].isl), (yyvsp[(2) - (2)].is));}
    break;

  case 21:
#line 123 "ficha10.exemplo.y"
    {(yyval.is)=insert_statement_write((yyvsp[(1) - (1)].iws));}
    break;

  case 22:
#line 124 "ficha10.exemplo.y"
    {(yyval.is)=insert_statement_assgn((yyvsp[(1) - (1)].ias));}
    break;

  case 23:
#line 125 "ficha10.exemplo.y"
    {(yyval.is)=insert_statement_call((yyvsp[(1) - (1)].ics));}
    break;

  case 24:
#line 126 "ficha10.exemplo.y"
    {(yyval.is)=insert_statement_if_else((yyvsp[(1) - (1)].ifes));}
    break;

  case 25:
#line 127 "ficha10.exemplo.y"
    {(yyval.is)=insert_statement_if((yyvsp[(1) - (1)].ifs));}
    break;

  case 26:
#line 128 "ficha10.exemplo.y"
    {(yyval.is)=insert_statement_while((yyvsp[(1) - (1)].iwls));}
    break;

  case 27:
#line 129 "ficha10.exemplo.y"
    {(yyval.is)=insert_statement_for((yyvsp[(1) - (1)].ifrs));}
    break;

  case 28:
#line 130 "ficha10.exemplo.y"
    {(yyval.is)=insert_statement_return((yyvsp[(1) - (1)].irs));}
    break;

  case 29:
#line 133 "ficha10.exemplo.y"
    {(yyval.irs)=insert_return_stat(line,(yyvsp[(2) - (3)].id));}
    break;

  case 30:
#line 136 "ficha10.exemplo.y"
    {(yyval.ifrs)=insert_for_stat(line,(yyvsp[(4) - (10)].iexl),(yyvsp[(9) - (10)].isl),(yyvsp[(3) - (10)].is),(yyvsp[(6) - (10)].is),n_for);n_for++;}
    break;

  case 31:
#line 140 "ficha10.exemplo.y"
    {(yyval.iwls)=insert_while_stat(line, (yyvsp[(3) - (7)].iexl),(yyvsp[(6) - (7)].isl),n_while);n_while++;}
    break;

  case 32:
#line 143 "ficha10.exemplo.y"
    {(yyval.ifs)=insert_if_stat(line, (yyvsp[(3) - (7)].iexl), (yyvsp[(6) - (7)].isl));}
    break;

  case 33:
#line 146 "ficha10.exemplo.y"
    {(yyval.ifes)=insert_if_else_stat(line, (yyvsp[(3) - (10)].iexl), (yyvsp[(6) - (10)].isl),(yyvsp[(9) - (10)].isl),n_if);n_if++;}
    break;

  case 34:
#line 149 "ficha10.exemplo.y"
    {(yyval.ical)=NULL;}
    break;

  case 35:
#line 150 "ficha10.exemplo.y"
    {(yyval.ical)=insert_call_agr_list((yyvsp[(1) - (2)].ical),(yyvsp[(2) - (2)].ica));}
    break;

  case 36:
#line 153 "ficha10.exemplo.y"
    {(yyval.ica)=insert_call_args_value((yyvsp[(1) - (1)].id));}
    break;

  case 37:
#line 154 "ficha10.exemplo.y"
    {(yyval.ica)=insert_call_args_int(atoi((yyvsp[(1) - (1)].valori)),integer);}
    break;

  case 38:
#line 155 "ficha10.exemplo.y"
    {(yyval.ica)=insert_call_args_doub(atof((yyvsp[(1) - (1)].valord)),doub);}
    break;

  case 39:
#line 156 "ficha10.exemplo.y"
    {(yyval.ica)=insert_call_args_char((yyvsp[(1) - (1)].character),character);}
    break;

  case 40:
#line 157 "ficha10.exemplo.y"
    {(yyval.ica)=insert_call_args_bool((yyvsp[(1) - (1)].bool),bool);}
    break;

  case 41:
#line 161 "ficha10.exemplo.y"
    {(yyval.ics)=insert_call_stat(line, (yyvsp[(2) - (6)].id),(yyvsp[(4) - (6)].ical));}
    break;

  case 42:
#line 164 "ficha10.exemplo.y"
    {(yyval.iws)=insert_write_stat(line, (yyvsp[(2) - (3)].id));}
    break;

  case 43:
#line 165 "ficha10.exemplo.y"
    {(yyval.iws)=insert_write_stat_int(line, atoi((yyvsp[(2) - (3)].valori)));}
    break;

  case 44:
#line 166 "ficha10.exemplo.y"
    {(yyval.iws)=insert_write_stat_doub(line, atof((yyvsp[(2) - (3)].valord)));}
    break;

  case 45:
#line 167 "ficha10.exemplo.y"
    {(yyval.iws)=insert_write_stat_char(line, (yyvsp[(2) - (3)].character));}
    break;

  case 46:
#line 168 "ficha10.exemplo.y"
    {(yyval.iws)=insert_write_stat_bool(line, (yyvsp[(2) - (3)].bool));}
    break;

  case 47:
#line 173 "ficha10.exemplo.y"
    {(yyval.ias)=insert_assgn_stat_char(line, (yyvsp[(1) - (4)].id), (yyvsp[(3) - (4)].character));}
    break;

  case 48:
#line 174 "ficha10.exemplo.y"
    {if(is_int((yyvsp[(1) - (4)].id),variaveis)!=1){ (yyval.ias)=insert_assgn_stat_double(line, (yyvsp[(1) - (4)].id), (yyvsp[(3) - (4)].iexl));}else{ (yyval.ias)=insert_assgn_stat_int(line, (yyvsp[(1) - (4)].id), (yyvsp[(3) - (4)].iexl));}}
    break;

  case 49:
#line 175 "ficha10.exemplo.y"
    {(yyval.ias)=insert_assgn_stat_boolean(line,(yyvsp[(1) - (4)].id),(yyvsp[(3) - (4)].bool));}
    break;

  case 50:
#line 176 "ficha10.exemplo.y"
    {(yyval.ias)=insert_assgn_stat_read_int(line,(yyvsp[(1) - (4)].id));}
    break;

  case 51:
#line 177 "ficha10.exemplo.y"
    {(yyval.ias)=insert_assgn_stat_read_double(line,(yyvsp[(1) - (4)].id));}
    break;

  case 52:
#line 178 "ficha10.exemplo.y"
    {(yyval.ias)=insert_assgn_stat_read_char(line,(yyvsp[(1) - (4)].id));}
    break;

  case 53:
#line 181 "ficha10.exemplo.y"
    {(yyval.iexl)=NULL;}
    break;

  case 54:
#line 182 "ficha10.exemplo.y"
    {(yyval.iexl)=insert_expression_list((yyvsp[(1) - (2)].iexl),(yyvsp[(2) - (2)].iex));}
    break;

  case 55:
#line 185 "ficha10.exemplo.y"
    {(yyval.iex)=insert_expression(line,(yyvsp[(1) - (1)].valori),not_var);}
    break;

  case 56:
#line 186 "ficha10.exemplo.y"
    {(yyval.iex)=insert_expression(line,(yyvsp[(1) - (1)].valord),not_var);}
    break;

  case 57:
#line 187 "ficha10.exemplo.y"
    {(yyval.iex)=insert_expression(line,"+",not_var);}
    break;

  case 58:
#line 188 "ficha10.exemplo.y"
    {(yyval.iex)=insert_expression(line,"/",not_var);}
    break;

  case 59:
#line 189 "ficha10.exemplo.y"
    {(yyval.iex)=insert_expression(line,"*",not_var);}
    break;

  case 60:
#line 190 "ficha10.exemplo.y"
    {(yyval.iex)=insert_expression(line,"%",not_var);}
    break;

  case 61:
#line 191 "ficha10.exemplo.y"
    {(yyval.iex)=insert_expression(line,"|",not_var);}
    break;

  case 62:
#line 192 "ficha10.exemplo.y"
    {(yyval.iex)=insert_expression(line,"&",not_var);}
    break;

  case 63:
#line 193 "ficha10.exemplo.y"
    {(yyval.iex)=insert_expression(line,"(",not_var);}
    break;

  case 64:
#line 194 "ficha10.exemplo.y"
    {(yyval.iex)=insert_expression(line,")",not_var);}
    break;

  case 65:
#line 195 "ficha10.exemplo.y"
    {(yyval.iex)=insert_expression(line,"-",not_var);}
    break;

  case 66:
#line 196 "ficha10.exemplo.y"
    {(yyval.iex)=insert_expression(line,(yyvsp[(1) - (1)].id),var);}
    break;

  case 67:
#line 197 "ficha10.exemplo.y"
    {(yyval.iex)=insert_expression(line,">",not_var);}
    break;

  case 68:
#line 198 "ficha10.exemplo.y"
    {(yyval.iex)=insert_expression(line,">=",not_var);}
    break;

  case 69:
#line 199 "ficha10.exemplo.y"
    {(yyval.iex)=insert_expression(line,"<",not_var);}
    break;

  case 70:
#line 200 "ficha10.exemplo.y"
    {(yyval.iex)=insert_expression(line,"<=",not_var);}
    break;

  case 71:
#line 201 "ficha10.exemplo.y"
    {(yyval.iex)=insert_expression(line,"==",not_var);}
    break;

  case 72:
#line 202 "ficha10.exemplo.y"
    {(yyval.iex)=insert_expression(line,"!=",not_var);}
    break;

  case 73:
#line 203 "ficha10.exemplo.y"
    {(yyval.iex)=insert_expression(line,"!",not_var);}
    break;


/* Line 1267 of yacc.c.  */
#line 1964 "y.tab.c"
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
      /* If just tried and failed to reuse look-ahead token after an
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

  /* Else will try to reuse look-ahead token after shifting the error
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

  if (yyn == YYFINAL)
    YYACCEPT;

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

#ifndef yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEOF && yychar != YYEMPTY)
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


#line 207 "ficha10.exemplo.y"

int main(int argc, char **argv)
{
int parsingOK;

line=1;

parsingOK=yyparse();

if(parsingOK==0)  //Só faz análise semântica se não houve problemas de sintaxe
{
	prog_environment=semantic_analysis(myprog);

	printf("Your program has %d errors\n", erros);

	if(erros==0)
	{
		translate(myprog, prog_environment);
//		show_block_list(myprog);
//		show_table(prog_environment->global);
	}
}
return 0;
}

int yyerror(char *msg)
{
printf("line %d: %s\n", line, msg);

return 1;
}


void show_table(table_element* table)
{
	table_element *aux;
	printf("\n");

	for(aux=table; aux; aux=aux->next){
		printf("symbol %s, type %s\n", aux->name, typeToString(aux->type));
	}
}


