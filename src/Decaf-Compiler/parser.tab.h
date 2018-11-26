/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

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

#ifndef YY_YY_PARSER_TAB_H_INCLUDED
# define YY_YY_PARSER_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
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
    var_id = 293,
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

/* Value type.  */


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSER_TAB_H_INCLUDED  */
