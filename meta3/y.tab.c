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
     RESERVED = 258,
     IF = 259,
     ELSE = 260,
     WHILE = 261,
     ATOI = 262,
     ITOA = 263,
     CHAR = 264,
     PRINTF = 265,
     RETURN = 266,
     EQ = 267,
     ASSIGN = 268,
     GE = 269,
     GT = 270,
     LE = 271,
     LT = 272,
     NE = 273,
     AMP = 274,
     AND = 275,
     AST = 276,
     DIV = 277,
     COMMA = 278,
     SEMI = 279,
     LBRACE = 280,
     RBRACE = 281,
     LSQ = 282,
     RSQ = 283,
     LPAR = 284,
     RPAR = 285,
     MINUS = 286,
     PLUS = 287,
     MOD = 288,
     NOT = 289,
     OR = 290,
     INT = 291,
     UMINUS = 292,
     UPLUS = 293,
     INTLIT = 294,
     CHRLIT = 295,
     STRLIT = 296,
     ID = 297
   };
#endif
/* Tokens.  */
#define RESERVED 258
#define IF 259
#define ELSE 260
#define WHILE 261
#define ATOI 262
#define ITOA 263
#define CHAR 264
#define PRINTF 265
#define RETURN 266
#define EQ 267
#define ASSIGN 268
#define GE 269
#define GT 270
#define LE 271
#define LT 272
#define NE 273
#define AMP 274
#define AND 275
#define AST 276
#define DIV 277
#define COMMA 278
#define SEMI 279
#define LBRACE 280
#define RBRACE 281
#define LSQ 282
#define RSQ 283
#define LPAR 284
#define RPAR 285
#define MINUS 286
#define PLUS 287
#define MOD 288
#define NOT 289
#define OR 290
#define INT 291
#define UMINUS 292
#define UPLUS 293
#define INTLIT 294
#define CHRLIT 295
#define STRLIT 296
#define ID 297




/* Copy the first part of user declarations.  */
#line 1 "qccompiler.y"

	
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "structures.h"
#include "functions.h"
#include "shows.h"
#include "symbol_table.h"
#include "semantic.h"

extern int countLines;
extern int countColumns;
extern int yyleng;
extern char* yytext;

void yyerror (char *s);
int yylex(void);

is_node *myProgram;
prog_env *myProgramSemantic;

void show_program_semantic(table_element *table);
void show_program_semantic_procedures(environment_list* table);




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
#line 39 "qccompiler.y"
{
	int valorInteiro;
	char* valorChar;
	char* valorString;
	char* valorID;
	is_node *node;
}
/* Line 193 of yacc.c.  */
#line 217 "y.tab.c"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 230 "y.tab.c"

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
# if defined YYENABLE_NLS && YYENABLE_NLS
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
#define YYLAST   577

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  43
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  21
/* YYNRULES -- Number of rules.  */
#define YYNRULES  70
/* YYNRULES -- Number of states.  */
#define YYNSTATES  136

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   297

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
      35,    36,    37,    38,    39,    40,    41,    42
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint8 yyprhs[] =
{
       0,     0,     3,     6,     9,    12,    14,    16,    18,    25,
      28,    29,    33,    39,    41,    42,    45,    49,    50,    54,
      59,    63,    64,    66,    68,    72,    75,    76,    80,    81,
      83,    86,    90,    98,   104,   110,   114,   117,   118,   122,
     126,   130,   134,   138,   142,   146,   150,   154,   158,   162,
     166,   170,   174,   177,   180,   183,   186,   189,   194,   199,
     204,   209,   216,   220,   222,   224,   226,   228,   231,   232,
     236
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      44,     0,    -1,    44,    45,    -1,    44,    47,    -1,    44,
      53,    -1,    45,    -1,    47,    -1,    53,    -1,    55,    48,
      25,    46,    60,    26,    -1,    46,    53,    -1,    -1,    55,
      48,    24,    -1,    57,    42,    29,    49,    30,    -1,    50,
      -1,    -1,    52,    51,    -1,    51,    23,    52,    -1,    -1,
      55,    57,    42,    -1,    55,    56,    54,    24,    -1,    54,
      23,    56,    -1,    -1,    36,    -1,     9,    -1,    57,    42,
      58,    -1,    57,    21,    -1,    -1,    27,    61,    28,    -1,
      -1,    24,    -1,    61,    24,    -1,    25,    60,    26,    -1,
       4,    29,    61,    30,    59,     5,    59,    -1,     4,    29,
      61,    30,    59,    -1,     6,    29,    61,    30,    59,    -1,
      11,    61,    24,    -1,    60,    59,    -1,    -1,    61,    13,
      61,    -1,    61,    35,    61,    -1,    61,    20,    61,    -1,
      61,    14,    61,    -1,    61,    16,    61,    -1,    61,    15,
      61,    -1,    61,    17,    61,    -1,    61,    18,    61,    -1,
      61,    12,    61,    -1,    61,    33,    61,    -1,    61,    22,
      61,    -1,    61,    21,    61,    -1,    61,    31,    61,    -1,
      61,    32,    61,    -1,    34,    61,    -1,    31,    61,    -1,
      32,    61,    -1,    21,    61,    -1,    19,    61,    -1,    61,
      27,    61,    28,    -1,    42,    29,    62,    30,    -1,     7,
      29,    61,    30,    -1,    10,    29,    61,    30,    -1,     8,
      29,    61,    23,    61,    30,    -1,    29,    61,    30,    -1,
      41,    -1,    40,    -1,    39,    -1,    42,    -1,    61,    63,
      -1,    -1,    63,    23,    61,    -1,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    61,    61,    62,    63,    64,    65,    66,    70,    78,
      79,    82,    85,    88,    89,    92,    95,    96,    99,   102,
     105,   106,   109,   110,   113,   123,   124,   127,   128,   131,
     132,   133,   145,   166,   176,   185,   188,   189,   192,   193,
     194,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   223,   224,   227,
     228
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "RESERVED", "IF", "ELSE", "WHILE",
  "ATOI", "ITOA", "CHAR", "PRINTF", "RETURN", "EQ", "ASSIGN", "GE", "GT",
  "LE", "LT", "NE", "AMP", "AND", "AST", "DIV", "COMMA", "SEMI", "LBRACE",
  "RBRACE", "LSQ", "RSQ", "LPAR", "RPAR", "MINUS", "PLUS", "MOD", "NOT",
  "OR", "INT", "UMINUS", "UPLUS", "INTLIT", "CHRLIT", "STRLIT", "ID",
  "$accept", "start", "functionDefinition", "new_eleven",
  "functionDeclaration", "functionDeclarator", "new_ten", "parameterList",
  "new_nine", "parameterDeclaration", "declaration", "new_eight",
  "typeSpecifier", "declarator", "new_six", "new_seven", "statement",
  "new_four", "expression", "new_one", "new_two", 0
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
     295,   296,   297
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    43,    44,    44,    44,    44,    44,    44,    45,    46,
      46,    47,    48,    49,    49,    50,    51,    51,    52,    53,
      54,    54,    55,    55,    56,    57,    57,    58,    58,    59,
      59,    59,    59,    59,    59,    59,    60,    60,    61,    61,
      61,    61,    61,    61,    61,    61,    61,    61,    61,    61,
      61,    61,    61,    61,    61,    61,    61,    61,    61,    61,
      61,    61,    61,    61,    61,    61,    61,    62,    62,    63,
      63
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     2,     2,     1,     1,     1,     6,     2,
       0,     3,     5,     1,     0,     2,     3,     0,     3,     4,
       3,     0,     1,     1,     3,     2,     0,     3,     0,     1,
       2,     3,     7,     5,     5,     3,     2,     0,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     2,     2,     2,     2,     2,     4,     4,     4,
       4,     6,     3,     1,     1,     1,     1,     2,     0,     3,
       0
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    23,    22,     0,     5,     6,     7,    26,     1,     2,
       3,     4,     0,    21,     0,    11,    10,     0,    25,    28,
      37,    26,    19,     0,    14,    24,     9,    26,     0,    20,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      65,    64,    63,    66,     0,     0,    13,    17,    26,     0,
       0,     0,    29,    37,     8,    36,     0,    28,     0,     0,
       0,    56,    55,     0,    53,    54,    52,    68,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    27,
       0,     0,     0,     0,    12,    15,     0,     0,     0,     0,
       0,    30,     0,     0,     0,    62,    70,     0,    46,    38,
      41,    43,    42,    44,    45,    40,    49,    48,     0,    50,
      51,    47,    39,     0,    18,     0,     0,    35,    31,    59,
       0,    60,    67,    58,    57,    16,     0,     0,     0,     0,
      33,    34,    61,    69,     0,    32
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     3,     4,    20,     5,    12,    45,    46,    85,    47,
       6,    17,     7,    13,    30,    25,    55,    28,    56,    97,
     122
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -109
static const yytype_int16 yypact[] =
{
      -6,  -109,  -109,    20,  -109,  -109,  -109,  -109,  -109,  -109,
    -109,  -109,   -16,  -109,   -17,  -109,  -109,    -2,  -109,     5,
      -6,  -109,  -109,   185,    -6,  -109,  -109,  -109,    79,  -109,
     -15,   -12,     9,    10,   185,   185,   185,   185,   185,   185,
    -109,  -109,  -109,    11,   216,    -7,  -109,  -109,  -109,    12,
      13,   185,  -109,  -109,  -109,  -109,   240,     6,   185,   185,
     185,    36,    36,   264,    36,    36,    36,   185,   185,   185,
     185,   185,   185,   185,   185,   185,   185,   185,   185,  -109,
     185,   185,   185,   185,  -109,    43,   -11,   185,   185,   288,
     118,  -109,   312,   336,   360,  -109,   480,    45,   544,   480,
      40,    40,    40,    40,   544,   524,    36,    36,   384,    47,
      47,    36,   502,    -6,  -109,   408,   432,  -109,  -109,  -109,
     185,  -109,    53,  -109,  -109,  -109,   157,   157,   456,   185,
      65,  -109,  -109,   480,   157,  -109
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
    -109,  -109,    74,  -109,    75,  -109,  -109,  -109,  -109,   -34,
       4,  -109,   -19,    60,    -5,  -109,  -108,    29,   -23,  -109,
    -109
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      44,    27,    14,     1,    18,    48,    18,    11,    15,    16,
      18,    61,    62,    63,    64,    65,    66,    58,   130,   131,
       8,    21,    22,    84,    26,    19,   135,    57,    89,     1,
       2,   114,    23,    23,    24,    92,    93,    94,    59,    60,
      67,    87,    88,    86,    96,    98,    99,   100,   101,   102,
     103,   104,   105,   106,   107,   108,     2,   109,   110,   111,
     112,    76,    77,    78,   115,   116,   113,    78,    76,    77,
     134,    80,    81,    82,    78,   123,   129,     9,    10,   125,
      82,    29,    90,    49,     0,    50,    31,    32,     0,    33,
      51,     0,     0,     0,    48,     0,     0,   128,    34,     0,
      35,     0,     0,    52,    53,    54,   133,     0,    36,     0,
      37,    38,     0,    39,     0,     0,     0,     0,    40,    41,
      42,    43,    49,     0,    50,    31,    32,     0,    33,    51,
       0,     0,     0,     0,     0,     0,     0,    34,     0,    35,
       0,     0,    52,    53,   118,     0,     0,    36,     0,    37,
      38,     0,    39,     0,     0,     0,     0,    40,    41,    42,
      43,    49,     0,    50,    31,    32,     0,    33,    51,     0,
       0,     0,     0,     0,     0,     0,    34,     0,    35,     0,
       0,    52,    53,     0,     0,     0,    36,     0,    37,    38,
       0,    39,    31,    32,     0,    33,    40,    41,    42,    43,
       0,     0,     0,     0,    34,     0,    35,     0,     0,     0,
       0,     0,     0,     0,    36,     0,    37,    38,     0,    39,
       0,     0,     0,     0,    40,    41,    42,    43,    68,    69,
      70,    71,    72,    73,    74,     0,    75,    76,    77,     0,
       0,     0,     0,    78,    79,     0,     0,    80,    81,    82,
       0,    83,    68,    69,    70,    71,    72,    73,    74,     0,
      75,    76,    77,     0,    91,     0,     0,    78,     0,     0,
       0,    80,    81,    82,     0,    83,    68,    69,    70,    71,
      72,    73,    74,     0,    75,    76,    77,     0,     0,     0,
       0,    78,     0,     0,    95,    80,    81,    82,     0,    83,
      68,    69,    70,    71,    72,    73,    74,     0,    75,    76,
      77,     0,   117,     0,     0,    78,     0,     0,     0,    80,
      81,    82,     0,    83,    68,    69,    70,    71,    72,    73,
      74,     0,    75,    76,    77,     0,     0,     0,     0,    78,
       0,     0,   119,    80,    81,    82,     0,    83,    68,    69,
      70,    71,    72,    73,    74,     0,    75,    76,    77,   120,
       0,     0,     0,    78,     0,     0,     0,    80,    81,    82,
       0,    83,    68,    69,    70,    71,    72,    73,    74,     0,
      75,    76,    77,     0,     0,     0,     0,    78,     0,     0,
     121,    80,    81,    82,     0,    83,    68,    69,    70,    71,
      72,    73,    74,     0,    75,    76,    77,     0,     0,     0,
       0,    78,   124,     0,     0,    80,    81,    82,     0,    83,
      68,    69,    70,    71,    72,    73,    74,     0,    75,    76,
      77,     0,     0,     0,     0,    78,     0,     0,   126,    80,
      81,    82,     0,    83,    68,    69,    70,    71,    72,    73,
      74,     0,    75,    76,    77,     0,     0,     0,     0,    78,
       0,     0,   127,    80,    81,    82,     0,    83,    68,    69,
      70,    71,    72,    73,    74,     0,    75,    76,    77,     0,
       0,     0,     0,    78,     0,     0,   132,    80,    81,    82,
       0,    83,    68,    69,    70,    71,    72,    73,    74,     0,
      75,    76,    77,     0,     0,     0,     0,    78,     0,     0,
       0,    80,    81,    82,    68,    83,    70,    71,    72,    73,
      74,     0,    75,    76,    77,     0,     0,     0,     0,    78,
       0,     0,     0,    80,    81,    82,    68,     0,    70,    71,
      72,    73,    74,     0,     0,    76,    77,     0,     0,     0,
       0,    78,     0,     0,     0,    80,    81,    82,    70,    71,
      72,    73,     0,     0,     0,    76,    77,     0,     0,     0,
       0,    78,     0,     0,     0,    80,    81,    82
};

static const yytype_int16 yycheck[] =
{
      23,    20,     7,     9,    21,    24,    21,     3,    24,    25,
      21,    34,    35,    36,    37,    38,    39,    29,   126,   127,
       0,    23,    24,    30,    20,    42,   134,    42,    51,     9,
      36,    42,    27,    27,    29,    58,    59,    60,    29,    29,
      29,    29,    29,    48,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    36,    80,    81,    82,
      83,    21,    22,    27,    87,    88,    23,    27,    21,    22,
       5,    31,    32,    33,    27,    30,    23,     3,     3,   113,
      33,    21,    53,     4,    -1,     6,     7,     8,    -1,    10,
      11,    -1,    -1,    -1,   113,    -1,    -1,   120,    19,    -1,
      21,    -1,    -1,    24,    25,    26,   129,    -1,    29,    -1,
      31,    32,    -1,    34,    -1,    -1,    -1,    -1,    39,    40,
      41,    42,     4,    -1,     6,     7,     8,    -1,    10,    11,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    19,    -1,    21,
      -1,    -1,    24,    25,    26,    -1,    -1,    29,    -1,    31,
      32,    -1,    34,    -1,    -1,    -1,    -1,    39,    40,    41,
      42,     4,    -1,     6,     7,     8,    -1,    10,    11,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    19,    -1,    21,    -1,
      -1,    24,    25,    -1,    -1,    -1,    29,    -1,    31,    32,
      -1,    34,     7,     8,    -1,    10,    39,    40,    41,    42,
      -1,    -1,    -1,    -1,    19,    -1,    21,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    29,    -1,    31,    32,    -1,    34,
      -1,    -1,    -1,    -1,    39,    40,    41,    42,    12,    13,
      14,    15,    16,    17,    18,    -1,    20,    21,    22,    -1,
      -1,    -1,    -1,    27,    28,    -1,    -1,    31,    32,    33,
      -1,    35,    12,    13,    14,    15,    16,    17,    18,    -1,
      20,    21,    22,    -1,    24,    -1,    -1,    27,    -1,    -1,
      -1,    31,    32,    33,    -1,    35,    12,    13,    14,    15,
      16,    17,    18,    -1,    20,    21,    22,    -1,    -1,    -1,
      -1,    27,    -1,    -1,    30,    31,    32,    33,    -1,    35,
      12,    13,    14,    15,    16,    17,    18,    -1,    20,    21,
      22,    -1,    24,    -1,    -1,    27,    -1,    -1,    -1,    31,
      32,    33,    -1,    35,    12,    13,    14,    15,    16,    17,
      18,    -1,    20,    21,    22,    -1,    -1,    -1,    -1,    27,
      -1,    -1,    30,    31,    32,    33,    -1,    35,    12,    13,
      14,    15,    16,    17,    18,    -1,    20,    21,    22,    23,
      -1,    -1,    -1,    27,    -1,    -1,    -1,    31,    32,    33,
      -1,    35,    12,    13,    14,    15,    16,    17,    18,    -1,
      20,    21,    22,    -1,    -1,    -1,    -1,    27,    -1,    -1,
      30,    31,    32,    33,    -1,    35,    12,    13,    14,    15,
      16,    17,    18,    -1,    20,    21,    22,    -1,    -1,    -1,
      -1,    27,    28,    -1,    -1,    31,    32,    33,    -1,    35,
      12,    13,    14,    15,    16,    17,    18,    -1,    20,    21,
      22,    -1,    -1,    -1,    -1,    27,    -1,    -1,    30,    31,
      32,    33,    -1,    35,    12,    13,    14,    15,    16,    17,
      18,    -1,    20,    21,    22,    -1,    -1,    -1,    -1,    27,
      -1,    -1,    30,    31,    32,    33,    -1,    35,    12,    13,
      14,    15,    16,    17,    18,    -1,    20,    21,    22,    -1,
      -1,    -1,    -1,    27,    -1,    -1,    30,    31,    32,    33,
      -1,    35,    12,    13,    14,    15,    16,    17,    18,    -1,
      20,    21,    22,    -1,    -1,    -1,    -1,    27,    -1,    -1,
      -1,    31,    32,    33,    12,    35,    14,    15,    16,    17,
      18,    -1,    20,    21,    22,    -1,    -1,    -1,    -1,    27,
      -1,    -1,    -1,    31,    32,    33,    12,    -1,    14,    15,
      16,    17,    18,    -1,    -1,    21,    22,    -1,    -1,    -1,
      -1,    27,    -1,    -1,    -1,    31,    32,    33,    14,    15,
      16,    17,    -1,    -1,    -1,    21,    22,    -1,    -1,    -1,
      -1,    27,    -1,    -1,    -1,    31,    32,    33
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     9,    36,    44,    45,    47,    53,    55,     0,    45,
      47,    53,    48,    56,    57,    24,    25,    54,    21,    42,
      46,    23,    24,    27,    29,    58,    53,    55,    60,    56,
      57,     7,     8,    10,    19,    21,    29,    31,    32,    34,
      39,    40,    41,    42,    61,    49,    50,    52,    55,     4,
       6,    11,    24,    25,    26,    59,    61,    42,    29,    29,
      29,    61,    61,    61,    61,    61,    61,    29,    12,    13,
      14,    15,    16,    17,    18,    20,    21,    22,    27,    28,
      31,    32,    33,    35,    30,    51,    57,    29,    29,    61,
      60,    24,    61,    61,    61,    30,    61,    62,    61,    61,
      61,    61,    61,    61,    61,    61,    61,    61,    61,    61,
      61,    61,    61,    23,    42,    61,    61,    24,    26,    30,
      23,    30,    63,    30,    28,    52,    30,    30,    61,    23,
      59,    59,    30,    61,     5,    59
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
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
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
#line 61 "qccompiler.y"
    {(yyval.node)=insert_link((yyvsp[(1) - (2)].node), (yyvsp[(2) - (2)].node));}
    break;

  case 3:
#line 62 "qccompiler.y"
    {(yyval.node)=insert_link((yyvsp[(1) - (2)].node), (yyvsp[(2) - (2)].node));}
    break;

  case 4:
#line 63 "qccompiler.y"
    {(yyval.node)=insert_link((yyvsp[(1) - (2)].node), (yyvsp[(2) - (2)].node));}
    break;

  case 5:
#line 64 "qccompiler.y"
    {(yyval.node)=(yyvsp[(1) - (1)].node); myProgram=(yyval.node);}
    break;

  case 6:
#line 65 "qccompiler.y"
    {(yyval.node)=(yyvsp[(1) - (1)].node); myProgram=(yyval.node);}
    break;

  case 7:
#line 66 "qccompiler.y"
    {(yyval.node)=(yyvsp[(1) - (1)].node); myProgram=(yyval.node);}
    break;

  case 8:
#line 70 "qccompiler.y"
    {
														(yyvsp[(5) - (6)].node)=reverse((yyvsp[(5) - (6)].node));
														(yyvsp[(4) - (6)].node)=reverse((yyvsp[(4) - (6)].node));
														is_node *body = insert_func_body(d_func_body, (yyvsp[(4) - (6)].node), (yyvsp[(5) - (6)].node)); 
														(yyval.node)=insert_function_definition(d_func_definition, (yyvsp[(1) - (6)].node), (yyvsp[(2) - (6)].node), body);
													}
    break;

  case 9:
#line 78 "qccompiler.y"
    {(yyval.node)=insert_link((yyvsp[(2) - (2)].node), (yyvsp[(1) - (2)].node));}
    break;

  case 10:
#line 79 "qccompiler.y"
    {(yyval.node)=insert_token(d_null);}
    break;

  case 11:
#line 82 "qccompiler.y"
    {(yyval.node)=insert_function_declaration(d_func_declaration, (yyvsp[(1) - (3)].node), (yyvsp[(2) - (3)].node));}
    break;

  case 12:
#line 85 "qccompiler.y"
    {(yyval.node)=insert_function_declarator(d_func_declarator, (yyvsp[(1) - (5)].node), insert_string(d_id, (yyvsp[(2) - (5)].valorID)), (yyvsp[(4) - (5)].node));}
    break;

  case 13:
#line 88 "qccompiler.y"
    {(yyval.node)=(yyvsp[(1) - (1)].node);}
    break;

  case 14:
#line 89 "qccompiler.y"
    {(yyval.node)=insert_token(d_null);}
    break;

  case 15:
#line 92 "qccompiler.y"
    {/*$$=insert_param_list(d_param_list, $1, $2);*/(yyval.node)=insert_link((yyvsp[(1) - (2)].node), (yyvsp[(2) - (2)].node)); (yyval.node)->next = reverse((yyval.node)->next);}
    break;

  case 16:
#line 95 "qccompiler.y"
    {(yyval.node)=insert_link((yyvsp[(3) - (3)].node), (yyvsp[(1) - (3)].node));}
    break;

  case 17:
#line 96 "qccompiler.y"
    {(yyval.node)=insert_token(d_null);}
    break;

  case 18:
#line 99 "qccompiler.y"
    {(yyval.node)=insert_param_declaration(d_param_declaration, (yyvsp[(1) - (3)].node), (yyvsp[(2) - (3)].node), insert_string(d_id, (yyvsp[(3) - (3)].valorID)));}
    break;

  case 19:
#line 102 "qccompiler.y"
    {(yyvsp[(3) - (4)].node)=reverse((yyvsp[(3) - (4)].node)); (yyval.node)=insert_declaration(d_declaration, (yyvsp[(1) - (4)].node),(yyvsp[(2) - (4)].node), (yyvsp[(3) - (4)].node));}
    break;

  case 20:
#line 105 "qccompiler.y"
    {(yyval.node)=insert_link((yyvsp[(3) - (3)].node), (yyvsp[(1) - (3)].node));}
    break;

  case 21:
#line 106 "qccompiler.y"
    {(yyval.node)=insert_token(d_null);}
    break;

  case 22:
#line 109 "qccompiler.y"
    {(yyval.node)=insert_token(d_int);}
    break;

  case 23:
#line 110 "qccompiler.y"
    {(yyval.node)=insert_token(d_char);}
    break;

  case 24:
#line 113 "qccompiler.y"
    {
										if((yyvsp[(3) - (3)].node)->d_node==d_null){
											(yyval.node)=insert_declarator(d_declarator, (yyvsp[(1) - (3)].node), insert_string(d_id, (yyvsp[(2) - (3)].valorID)), (yyvsp[(3) - (3)].node));
										} else {
											(yyval.node)=insert_declarator(d_array_declarator, (yyvsp[(1) - (3)].node), insert_string(d_id, (yyvsp[(2) - (3)].valorID)), (yyvsp[(3) - (3)].node));
										}

									}
    break;

  case 25:
#line 123 "qccompiler.y"
    {(yyval.node)=insert_link(insert_token(d_pointer), (yyvsp[(1) - (2)].node));}
    break;

  case 26:
#line 124 "qccompiler.y"
    {(yyval.node)=insert_token(d_null);}
    break;

  case 27:
#line 127 "qccompiler.y"
    {(yyval.node)=(yyvsp[(2) - (3)].node);}
    break;

  case 28:
#line 128 "qccompiler.y"
    {(yyval.node)=insert_token(d_null);}
    break;

  case 29:
#line 131 "qccompiler.y"
    {(yyval.node)=insert_token(d_null);}
    break;

  case 30:
#line 132 "qccompiler.y"
    {(yyval.node)=(yyvsp[(1) - (2)].node);}
    break;

  case 31:
#line 133 "qccompiler.y"
    {
																	int count = compoundStatCounter((yyvsp[(2) - (3)].node)); 
																	(yyvsp[(2) - (3)].node)=reverse((yyvsp[(2) - (3)].node)); 																	
																	if(count==0){
																		(yyval.node)=insert_token(d_null);
																	} else if(count==1){
																		(yyval.node)=insert_compound(d_stat, (yyvsp[(2) - (3)].node));	
																	} else {
																		(yyval.node)=insert_compound(d_compound_stat, (yyvsp[(2) - (3)].node));	
																	}
																}
    break;

  case 32:
#line 145 "qccompiler.y"
    {
																	is_node * aux1;
																	is_node * aux2;
																	aux1 = (yyvsp[(5) - (7)].node);
																	aux2 = (yyvsp[(7) - (7)].node);

																	int conta = contaStatements((yyvsp[(5) - (7)].node));
     																int conta2 = contaStatements((yyvsp[(7) - (7)].node));

																	if(conta==0)
																		aux1 = insert_null_node();
																	
																	if(conta2==0)
																		aux2 = insert_null_node();

																	
																	(yyval.node)=insert_if_else(d_if_else, (yyvsp[(3) - (7)].node), aux1, aux2);

																}
    break;

  case 33:
#line 166 "qccompiler.y"
    {


																	if((yyvsp[(5) - (5)].node)->d_node == d_null){
																		(yyvsp[(5) - (5)].node) = insert_token(d_print_null);
 	 																	(yyval.node)=insert_if(d_if,(yyvsp[(3) - (5)].node),insert_link(insert_token(d_print_null),(yyvsp[(5) - (5)].node)));
																 	}else
																 		(yyval.node) = insert_if(d_if,(yyvsp[(3) - (5)].node),insert_link((yyvsp[(5) - (5)].node), insert_token(d_print_null)));

																}
    break;

  case 34:
#line 176 "qccompiler.y"
    {
																int conta = contaStatements((yyvsp[(5) - (5)].node));
																
																if(conta==0)
																	(yyval.node)=insert_while(d_while, (yyvsp[(3) - (5)].node), insert_null_node());
																else
																	(yyval.node)=insert_while(d_while, (yyvsp[(3) - (5)].node), (yyvsp[(5) - (5)].node));
																}
    break;

  case 35:
#line 185 "qccompiler.y"
    {(yyval.node)=insert_return(d_return, (yyvsp[(2) - (3)].node));}
    break;

  case 36:
#line 188 "qccompiler.y"
    {(yyval.node)=insert_link((yyvsp[(2) - (2)].node), (yyvsp[(1) - (2)].node));}
    break;

  case 37:
#line 189 "qccompiler.y"
    {(yyval.node)=insert_token(d_null); }
    break;

  case 38:
#line 192 "qccompiler.y"
    {(yyval.node)=insert_infix_expression(d_store, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node));}
    break;

  case 39:
#line 193 "qccompiler.y"
    {(yyval.node)=insert_infix_expression(d_or, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node));}
    break;

  case 40:
#line 194 "qccompiler.y"
    {(yyval.node)=insert_infix_expression(d_and, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node));}
    break;

  case 41:
#line 195 "qccompiler.y"
    {(yyval.node)=insert_infix_expression(d_ge, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node));}
    break;

  case 42:
#line 196 "qccompiler.y"
    {(yyval.node)=insert_infix_expression(d_le, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node));}
    break;

  case 43:
#line 197 "qccompiler.y"
    {(yyval.node)=insert_infix_expression(d_gt, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node));}
    break;

  case 44:
#line 198 "qccompiler.y"
    {(yyval.node)=insert_infix_expression(d_lt, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node));}
    break;

  case 45:
#line 199 "qccompiler.y"
    {(yyval.node)=insert_infix_expression(d_ne, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node));}
    break;

  case 46:
#line 200 "qccompiler.y"
    {(yyval.node)=insert_infix_expression(d_eq, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node));}
    break;

  case 47:
#line 201 "qccompiler.y"
    {(yyval.node)=insert_infix_expression(d_mod, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node));}
    break;

  case 48:
#line 202 "qccompiler.y"
    {(yyval.node)=insert_infix_expression(d_div, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node));}
    break;

  case 49:
#line 203 "qccompiler.y"
    {(yyval.node)=insert_infix_expression(d_mul, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node));}
    break;

  case 50:
#line 204 "qccompiler.y"
    {(yyval.node)=insert_infix_expression(d_sub, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node));}
    break;

  case 51:
#line 205 "qccompiler.y"
    {(yyval.node)=insert_infix_expression(d_add, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node));}
    break;

  case 52:
#line 206 "qccompiler.y"
    {(yyval.node)=insert_unary_expression(d_not, (yyvsp[(2) - (2)].node));}
    break;

  case 53:
#line 207 "qccompiler.y"
    {(yyval.node)=insert_unary_expression(d_minus, (yyvsp[(2) - (2)].node));}
    break;

  case 54:
#line 208 "qccompiler.y"
    {(yyval.node)=insert_unary_expression(d_plus, (yyvsp[(2) - (2)].node));}
    break;

  case 55:
#line 209 "qccompiler.y"
    {(yyval.node)=insert_unary_expression(d_deref, (yyvsp[(2) - (2)].node));}
    break;

  case 56:
#line 210 "qccompiler.y"
    {(yyval.node)=insert_unary_expression(d_addr, (yyvsp[(2) - (2)].node));}
    break;

  case 57:
#line 211 "qccompiler.y"
    {is_node *add = insert_add(d_add, (yyvsp[(1) - (4)].node), (yyvsp[(3) - (4)].node)); (yyval.node)=insert_unary_expression(d_deref, add);}
    break;

  case 58:
#line 212 "qccompiler.y"
    {is_node * tmp = reverse((yyvsp[(3) - (4)].node)->next); (yyvsp[(3) - (4)].node)->next = tmp; tmp=insert_link(insert_string(d_id, (yyvsp[(1) - (4)].valorID)), (yyvsp[(3) - (4)].node)); (yyval.node)=insert_call(d_call, tmp);}
    break;

  case 59:
#line 213 "qccompiler.y"
    {(yyval.node)=insert_atoi(d_atoi, (yyvsp[(3) - (4)].node));}
    break;

  case 60:
#line 214 "qccompiler.y"
    {(yyval.node)=insert_printf(d_print, (yyvsp[(3) - (4)].node));}
    break;

  case 61:
#line 215 "qccompiler.y"
    {(yyval.node)=insert_itoa(d_itoa, (yyvsp[(3) - (6)].node), (yyvsp[(5) - (6)].node));}
    break;

  case 62:
#line 216 "qccompiler.y"
    {(yyval.node)=(yyvsp[(2) - (3)].node);}
    break;

  case 63:
#line 217 "qccompiler.y"
    {(yyval.node)=insert_string(d_strlit, (yyvsp[(1) - (1)].valorString));}
    break;

  case 64:
#line 218 "qccompiler.y"
    {(yyval.node)=insert_string(d_charlit, (yyvsp[(1) - (1)].valorChar));}
    break;

  case 65:
#line 219 "qccompiler.y"
    {(yyval.node)=insert_number(d_intlit, (yyvsp[(1) - (1)].valorInteiro));}
    break;

  case 66:
#line 220 "qccompiler.y"
    {(yyval.node)=insert_string(d_id, (yyvsp[(1) - (1)].valorID));}
    break;

  case 67:
#line 223 "qccompiler.y"
    {(yyval.node)=insert_link((yyvsp[(1) - (2)].node), (yyvsp[(2) - (2)].node));}
    break;

  case 68:
#line 224 "qccompiler.y"
    {(yyval.node)=insert_token(d_null);}
    break;

  case 69:
#line 227 "qccompiler.y"
    {(yyval.node)=insert_link((yyvsp[(3) - (3)].node), (yyvsp[(1) - (3)].node));}
    break;

  case 70:
#line 228 "qccompiler.y"
    {(yyval.node)=insert_token(d_null);}
    break;


/* Line 1267 of yacc.c.  */
#line 2034 "y.tab.c"
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


#line 231 "qccompiler.y"

int main(int argc, char *argv[])
{
	int i, show_tree = 0, show_semantic=0;

	if(yyparse()==0){

		myProgramSemantic = semantic_analysis(myProgram);

		for(i=0; i<argc; i++){
			if(strcmp(argv[i], "-t") == 0){
				show_tree = 1;
			} else if(strcmp(argv[i], "-s") == 0) {
				show_semantic = 1;
			}
			
		}

		if(show_tree == 1){
			printf("Program\n");
			show_program(myProgram, 1);
		} 
		if( show_semantic == 1){
			show_program_semantic(myProgramSemantic->global);
			show_program_semantic_procedures(myProgramSemantic->procs);
		}

	}
	return 0;
}

void yyerror (char *s) {

	countColumns -= yyleng;

	if(strcmp(yytext, "") == 0){
		countColumns++;
	}
	printf("Line %d, col %d: %s: %s\n", countLines, countColumns, s, yytext);
	
}

void show_program_semantic(table_element *table){

	table_element *aux;
	int i;

	printf("===== Global Symbol Table =====\n");

	for(aux=table; aux; aux = aux->next){

		printf("%s\t", aux->name);

		switch(aux->type_data.type){
			case(CHARe): printf("char"); break;
			case(INTe): printf("int"); break;
			case(FUNC): printf("function"); break;
			default: break;
		}

		for(i=0; i<aux->type_data.pointers; i++){
			printf("*");
		}

		if(aux->type_data.size!=-1){
			printf("[%d]", aux->type_data.size);
		}
		printf("\n");
	}

}


void show_program_semantic_procedures(environment_list* table)
{

	
	environment_list *aux;
	table_element* aux2;
	param_data *data;
	int i;

	for(aux=table; aux; aux = aux->next){
	
		printf("===== Function %s Symbol Table =====\n", aux->name);
		
		printf("return\t");
		switch(aux->return_type){

			case d_char:
				printf("char");
				break;
			case d_int:
				printf("int");
				break;
			default: break;
		}

		for(i=0; i<aux->pointers; i++){
			printf("*");
		}
		printf("\n");

		for(data=aux->params; data ;data=data->next){
			printf("%s\t", data->name);
			switch(data->type){

				case INTe:
					printf("int");
					break;
				case CHARe:
					printf("char");
					break;
				default: break;
			}

			for(i=0; i< data->pointers; i++){
				printf("*");
			}

			printf("\tparam\n");
		}

		for(aux2=aux->locals; aux2; aux2=aux2->next){
			printf("%s\t", aux2->name);

			switch(aux2->type_data.type){
				case(CHARe): printf("char"); break;
				case(INTe): printf("int"); break;
				default: break;
			}

			for(i=0; i<aux2->type_data.pointers; i++){
				printf("*");
			}

			if(aux2->type_data.size!=-1){
				printf("[%d]", aux2->type_data.size);
			}
			printf("\n");
		}


	}


}



