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
     PROGRAM = 258,
     CLASS = 259,
     CALLOUT = 260,
     VOID = 261,
     INT = 262,
     BOOLEAN = 263,
     TRUE = 264,
     FALSE = 265,
     BREAK = 266,
     CONTINUE = 267,
     RETURN = 268,
     FOR = 269,
     IF = 270,
     ELSE = 271,
     NUM = 272,
     ID = 273,
     ADD = 274,
     SUBTRACT = 275,
     MULTIPLY = 276,
     DIVIDE = 277,
     EQUAL = 278,
     PLUS_EQUAL = 279,
     MINUS_EQUAL = 280,
     EQUALITY = 281,
     NOT_EQUAL = 282,
     GREATER_EQUAL = 283,
     LESS_EQUAL = 284,
     GREATER = 285,
     LESS = 286,
     CONDITIONAL_AND = 287,
     CONDITIONAL_OR = 288,
     NOT = 289,
     ABSOLUTE = 290,
     MODULO = 291,
     CURLY_OPEN = 292,
     CURLY_CLOSE = 293,
     SQUARE_OPEN = 294,
     SQUARE_CLOSE = 295,
     OPEN = 296,
     CLOSE = 297,
     SEMI_COLON = 298,
     COMMA = 299
   };
#endif
/* Tokens.  */
#define PROGRAM 258
#define CLASS 259
#define CALLOUT 260
#define VOID 261
#define INT 262
#define BOOLEAN 263
#define TRUE 264
#define FALSE 265
#define BREAK 266
#define CONTINUE 267
#define RETURN 268
#define FOR 269
#define IF 270
#define ELSE 271
#define NUM 272
#define ID 273
#define ADD 274
#define SUBTRACT 275
#define MULTIPLY 276
#define DIVIDE 277
#define EQUAL 278
#define PLUS_EQUAL 279
#define MINUS_EQUAL 280
#define EQUALITY 281
#define NOT_EQUAL 282
#define GREATER_EQUAL 283
#define LESS_EQUAL 284
#define GREATER 285
#define LESS 286
#define CONDITIONAL_AND 287
#define CONDITIONAL_OR 288
#define NOT 289
#define ABSOLUTE 290
#define MODULO 291
#define CURLY_OPEN 292
#define CURLY_CLOSE 293
#define SQUARE_OPEN 294
#define SQUARE_CLOSE 295
#define OPEN 296
#define CLOSE 297
#define SEMI_COLON 298
#define COMMA 299




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

