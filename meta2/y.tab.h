/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton interface for Bison's Yacc-like parsers in C

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
     INTLIT = 292,
     CHRLIT = 293,
     STRLIT = 294,
     ID = 295
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
#define INTLIT 292
#define CHRLIT 293
#define STRLIT 294
#define ID 295




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 28 "qcparser.y"
{
	char* valorInteiro;
	char* valorChar;
	char* valorString;
	char* valorID;
}
/* Line 1529 of yacc.c.  */
#line 136 "y.tab.h"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

