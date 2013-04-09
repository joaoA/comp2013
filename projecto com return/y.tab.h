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
/* Line 1489 of yacc.c.  */
#line 173 "y.tab.h"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

