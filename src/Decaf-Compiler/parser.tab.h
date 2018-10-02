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
     HEX_DIGIT = 273,
     STRING = 274,
     ID = 275,
     ADD = 276,
     SUBTRACT = 277,
     MULTIPLY = 278,
     DIVIDE = 279,
     EQUAL = 280,
     PLUS_EQUAL = 281,
     MINUS_EQUAL = 282,
     EQUALITY = 283,
     NOT_EQUAL = 284,
     GREATER_EQUAL = 285,
     LESS_EQUAL = 286,
     GREATER = 287,
     LESS = 288,
     CONDITIONAL_AND = 289,
     CONDITIONAL_OR = 290,
     NOT = 291,
     ABSOLUTE = 292,
     MODULO = 293,
     CURLY_OPEN = 294,
     CURLY_CLOSE = 295,
     SQUARE_OPEN = 296,
     SQUARE_CLOSE = 297,
     OPEN = 298,
     CLOSE = 299,
     SEMI_COLON = 300,
     COMMA = 301
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
#define HEX_DIGIT 273
#define STRING 274
#define ID 275
#define ADD 276
#define SUBTRACT 277
#define MULTIPLY 278
#define DIVIDE 279
#define EQUAL 280
#define PLUS_EQUAL 281
#define MINUS_EQUAL 282
#define EQUALITY 283
#define NOT_EQUAL 284
#define GREATER_EQUAL 285
#define LESS_EQUAL 286
#define GREATER 287
#define LESS 288
#define CONDITIONAL_AND 289
#define CONDITIONAL_OR 290
#define NOT 291
#define ABSOLUTE 292
#define MODULO 293
#define CURLY_OPEN 294
#define CURLY_CLOSE 295
#define SQUARE_OPEN 296
#define SQUARE_CLOSE 297
#define OPEN 298
#define CLOSE 299
#define SEMI_COLON 300
#define COMMA 301




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

