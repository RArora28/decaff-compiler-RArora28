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
     ADD = 258,
     SUBTRACT = 259,
     MULTIPLY = 260,
     DIVIDE = 261,
     MODULO = 262,
     EQUAL = 263,
     PLUS_EQUAL = 264,
     MINUS_EQUAL = 265,
     EQUALITY = 266,
     NOT_EQUAL = 267,
     GREATER_EQUAL = 268,
     LESS_EQUAL = 269,
     GREATER = 270,
     LESS = 271,
     NOT = 272,
     CONDITIONAL_AND = 273,
     CONDITIONAL_OR = 274,
     PROGRAM = 275,
     CLASS = 276,
     CALLOUT = 277,
     VOID = 278,
     INT = 279,
     BOOLEAN = 280,
     TRUE = 281,
     FALSE = 282,
     BREAK = 283,
     CONTINUE = 284,
     RETURN = 285,
     FOR = 286,
     IF = 287,
     ELSE = 288,
     NUM = 289,
     HEX_LITERAL = 290,
     CHAR_LITERAL = 291,
     STRING = 292,
     ID = 293,
     ABSOLUTE = 294,
     CURLY_OPEN = 295,
     CURLY_CLOSE = 296,
     SQUARE_OPEN = 297,
     SQUARE_CLOSE = 298,
     OPEN = 299,
     CLOSE = 300,
     SEMI_COLON = 301,
     COMMA = 302
   };
#endif
/* Tokens.  */
#define ADD 258
#define SUBTRACT 259
#define MULTIPLY 260
#define DIVIDE 261
#define MODULO 262
#define EQUAL 263
#define PLUS_EQUAL 264
#define MINUS_EQUAL 265
#define EQUALITY 266
#define NOT_EQUAL 267
#define GREATER_EQUAL 268
#define LESS_EQUAL 269
#define GREATER 270
#define LESS 271
#define NOT 272
#define CONDITIONAL_AND 273
#define CONDITIONAL_OR 274
#define PROGRAM 275
#define CLASS 276
#define CALLOUT 277
#define VOID 278
#define INT 279
#define BOOLEAN 280
#define TRUE 281
#define FALSE 282
#define BREAK 283
#define CONTINUE 284
#define RETURN 285
#define FOR 286
#define IF 287
#define ELSE 288
#define NUM 289
#define HEX_LITERAL 290
#define CHAR_LITERAL 291
#define STRING 292
#define ID 293
#define ABSOLUTE 294
#define CURLY_OPEN 295
#define CURLY_CLOSE 296
#define SQUARE_OPEN 297
#define SQUARE_CLOSE 298
#define OPEN 299
#define CLOSE 300
#define SEMI_COLON 301
#define COMMA 302




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

