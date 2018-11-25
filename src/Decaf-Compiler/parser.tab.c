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




/* Copy the first part of user declarations.  */
#line 1 "parser.y"

	#include <bits/stdc++.h>	
	#include "ast.h"
	extern "C" int yylex();
	extern "C" int yyparse();
	extern "C" void yyerror(const char *s);
	extern union Node yylval;
	program* root; 


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
typedef int YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 210 "parser.tab.c"

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
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   372

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  48
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  40
/* YYNRULES -- Number of rules.  */
#define YYNRULES  93
/* YYNRULES -- Number of states.  */
#define YYNSTATES  170

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
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,    10,    12,    14,    15,    19,    22,    24,
      28,    30,    35,    38,    39,    46,    53,    59,    65,    67,
      71,    74,    78,    79,    82,    83,    87,    90,    92,    96,
      97,   100,   102,   104,   106,   108,   110,   112,   114,   119,
     121,   126,   133,   134,   137,   145,   149,   152,   155,   158,
     161,   164,   169,   173,   175,   179,   184,   191,   193,   197,
     199,   201,   203,   205,   207,   209,   211,   213,   215,   217,
     221,   225,   229,   233,   237,   241,   245,   249,   253,   257,
     261,   265,   269,   273,   276,   279,   281,   283,   285,   287,
     289,   291,   293,   295
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      49,     0,    -1,    21,    20,    40,    51,    55,    41,    -1,
      24,    -1,    25,    -1,    -1,    51,    52,    46,    -1,    50,
      53,    -1,    54,    -1,    53,    47,    54,    -1,    38,    -1,
      38,    42,    85,    43,    -1,    56,    55,    -1,    -1,    23,
      38,    44,    57,    45,    59,    -1,    50,    38,    44,    57,
      45,    59,    -1,    23,    38,    44,    45,    59,    -1,    50,
      38,    44,    45,    59,    -1,    58,    -1,    57,    47,    58,
      -1,    50,    38,    -1,    40,    60,    41,    -1,    -1,    61,
      64,    -1,    -1,    61,    62,    46,    -1,    50,    63,    -1,
      38,    -1,    63,    47,    38,    -1,    -1,    64,    65,    -1,
      66,    -1,    73,    -1,    68,    -1,    70,    -1,    71,    -1,
      72,    -1,    59,    -1,    67,    83,    79,    46,    -1,    38,
      -1,    38,    42,    79,    43,    -1,    32,    44,    79,    45,
      59,    69,    -1,    -1,    33,    59,    -1,    31,    38,     8,
      79,    47,    79,    59,    -1,    30,    79,    46,    -1,    30,
      46,    -1,    28,    46,    -1,    29,    46,    -1,    74,    46,
      -1,    76,    46,    -1,    38,    44,    75,    45,    -1,    38,
      44,    45,    -1,    79,    -1,    75,    47,    79,    -1,    22,
      44,    87,    45,    -1,    22,    44,    87,    47,    77,    45,
      -1,    78,    -1,    77,    47,    78,    -1,    79,    -1,    87,
      -1,    67,    -1,    73,    -1,    84,    -1,    85,    -1,    86,
      -1,    80,    -1,    82,    -1,    81,    -1,    79,     3,    79,
      -1,    79,     4,    79,    -1,    79,     5,    79,    -1,    79,
       6,    79,    -1,    79,     7,    79,    -1,    79,    15,    79,
      -1,    79,    16,    79,    -1,    79,    13,    79,    -1,    79,
      14,    79,    -1,    79,    11,    79,    -1,    79,    12,    79,
      -1,    79,    18,    79,    -1,    79,    19,    79,    -1,    44,
      79,    45,    -1,     4,    79,    -1,    17,    79,    -1,     8,
      -1,     9,    -1,    10,    -1,    36,    -1,    34,    -1,    35,
      -1,    26,    -1,    27,    -1,    37,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   108,   108,   116,   118,   125,   126,   130,   134,   139,
     143,   145,   150,   153,   156,   161,   165,   170,   176,   181,
     186,   192,   197,   198,   205,   206,   210,   214,   219,   226,
     227,   231,   232,   233,   234,   235,   236,   237,   240,   244,
     246,   250,   255,   256,   260,   264,   266,   270,   272,   276,
     278,   281,   283,   287,   292,   299,   301,   306,   311,   317,
     319,   323,   324,   325,   326,   327,   328,   329,   330,   333,
     335,   337,   339,   341,   343,   345,   347,   349,   351,   353,
     355,   357,   361,   365,   367,   372,   374,   376,   381,   385,
     387,   391,   393,   397
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "ADD", "SUBTRACT", "MULTIPLY", "DIVIDE",
  "MODULO", "EQUAL", "PLUS_EQUAL", "MINUS_EQUAL", "EQUALITY", "NOT_EQUAL",
  "GREATER_EQUAL", "LESS_EQUAL", "GREATER", "LESS", "NOT",
  "CONDITIONAL_AND", "CONDITIONAL_OR", "PROGRAM", "CLASS", "CALLOUT",
  "VOID", "INT", "BOOLEAN", "TRUE", "FALSE", "BREAK", "CONTINUE", "RETURN",
  "FOR", "IF", "ELSE", "NUM", "HEX_LITERAL", "CHAR_LITERAL", "STRING",
  "ID", "ABSOLUTE", "CURLY_OPEN", "CURLY_CLOSE", "SQUARE_OPEN",
  "SQUARE_CLOSE", "OPEN", "CLOSE", "SEMI_COLON", "COMMA", "$accept",
  "program_declaration", "var_type", "field_declarations",
  "field_declaration", "field_names", "field_name", "method_declarations",
  "method_declaration", "parameter_declarations", "parameter_declaration",
  "code_block", "block", "var_declarations", "var_declaration",
  "var_names", "statements", "statement", "assign_statement", "location",
  "if_statement", "else_statement", "for_statement", "return_statement",
  "terminal_statement", "method_call_statement", "method_call",
  "method_call_args", "callout_call", "callout_args", "callout_arg",
  "expr", "binary_expr", "enclosed_expr", "unary_expr", "assign_op",
  "char_literal", "int_literal", "bool_literal", "string_literal", 0
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
       0,    48,    49,    50,    50,    51,    51,    52,    53,    53,
      54,    54,    55,    55,    56,    56,    56,    56,    57,    57,
      58,    59,    60,    60,    61,    61,    62,    63,    63,    64,
      64,    65,    65,    65,    65,    65,    65,    65,    66,    67,
      67,    68,    69,    69,    70,    71,    71,    72,    72,    73,
      73,    74,    74,    75,    75,    76,    76,    77,    77,    78,
      78,    79,    79,    79,    79,    79,    79,    79,    79,    80,
      80,    80,    80,    80,    80,    80,    80,    80,    80,    80,
      80,    80,    81,    82,    82,    83,    83,    83,    84,    85,
      85,    86,    86,    87
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     6,     1,     1,     0,     3,     2,     1,     3,
       1,     4,     2,     0,     6,     6,     5,     5,     1,     3,
       2,     3,     0,     2,     0,     3,     2,     1,     3,     0,
       2,     1,     1,     1,     1,     1,     1,     1,     4,     1,
       4,     6,     0,     2,     7,     3,     2,     2,     2,     2,
       2,     4,     3,     1,     3,     4,     6,     1,     3,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     2,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     1,     5,    13,     0,     3,     4,
       0,     0,     0,    13,     0,    10,     7,     8,     6,     2,
       0,    12,     0,     0,     0,     0,     0,     0,     0,     0,
      18,    89,    90,     0,     0,     0,    10,     9,    24,    16,
      20,     0,     0,    11,    17,     0,     0,    29,    14,    19,
      15,    21,     0,     0,    23,    27,    26,    25,     0,     0,
       0,     0,     0,     0,    39,    37,    30,    31,     0,    33,
      34,    35,    36,    32,     0,     0,     0,     0,    47,    48,
       0,     0,    91,    92,    88,     0,    46,    61,    62,     0,
      66,    68,    67,    63,    64,    65,     0,     0,     0,     0,
      85,    86,    87,     0,    49,    50,    28,    93,     0,    83,
      84,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    45,     0,     0,     0,    52,
       0,    53,     0,    55,     0,    82,    69,    70,    71,    72,
      73,    78,    79,    76,    77,    74,    75,    80,    81,     0,
       0,    40,    51,     0,    38,     0,    57,    59,    60,     0,
      42,    54,    56,     0,     0,     0,    41,    58,    44,    43
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,    28,     6,    11,    16,    17,    12,    13,    29,
      30,    39,    46,    47,    53,    56,    54,    66,    67,    87,
      69,   166,    70,    71,    72,    88,    74,   130,    75,   155,
     156,   157,    90,    91,    92,   103,    93,    94,    95,   158
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -60
static const yytype_int16 yypact[] =
{
     -18,   -10,    13,    -6,   -60,   -60,    50,    -8,   -60,   -60,
       4,    20,    -4,    50,     1,   -38,     3,   -60,   -60,   -60,
      44,   -60,   -16,   -17,    -9,    53,    85,    69,    83,   101,
     -60,   -60,   -60,   112,    69,   133,   123,   -60,   106,   -60,
     -60,    69,    77,   -60,   -60,    69,   136,    77,   -60,   -60,
     -60,   -60,   143,   128,   163,   -60,   135,   -60,   142,   141,
     144,    -3,   161,   160,   183,   -60,   -60,   -60,   105,   -60,
     -60,   -60,   -60,   -60,   159,   168,   177,   185,   -60,   -60,
     233,   233,   -60,   -60,   -60,   233,   -60,   -60,   -60,    92,
     -60,   -60,   -60,   -60,   -60,   -60,   220,   233,   233,   162,
     -60,   -60,   -60,   233,   -60,   -60,   -60,   -60,   193,   321,
     140,   138,   233,   233,   233,   233,   233,   233,   233,   233,
     233,   233,   233,   233,   233,   -60,   233,   157,   205,   -60,
     194,   286,   121,   -60,   209,   -60,   306,   321,   335,   345,
      74,   353,   104,    33,   214,     9,   140,   215,   -60,    65,
      69,   -60,   -60,   233,   -60,   204,   -60,   286,   -60,   233,
     219,   286,   -60,   209,   269,    69,   -60,   -60,   -60,   -60
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -60,   -60,    -1,   -60,   -60,   -60,   217,   241,   -60,   232,
     216,   -34,   -60,   -60,   -60,   -60,   -60,   -60,   -60,   203,
     -60,   -60,   -60,   -60,   -60,   207,   -60,   -60,   -60,   -60,
      99,   -59,   -60,   -60,   -60,   -60,   -60,   240,   -60,   187
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -23
static const yytype_int16 yytable[] =
{
      44,    80,    89,     1,    23,    10,    24,    48,     8,     9,
       3,    50,    20,     4,    81,     8,     9,    31,    32,    58,
      65,   109,   110,    82,    83,   122,   111,   123,   124,    27,
      14,    31,    32,    84,     5,    64,    34,    19,   127,   128,
     131,    85,    15,    86,   132,    22,    52,   120,   121,   122,
      25,   123,   124,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   148,    18,   149,   112,   113,
     114,   115,   116,     7,     8,     9,   117,   118,   119,   120,
     121,   122,    26,   123,   124,   117,   118,   119,   120,   121,
     122,    36,   123,   124,   161,   112,   113,   114,   115,   116,
     164,     8,     9,   117,   118,   119,   120,   121,   122,    38,
     123,   124,   159,   100,   101,   102,   160,   119,   120,   121,
     122,    40,   123,   124,   112,   113,   114,   115,   116,    24,
     168,   169,   117,   118,   119,   120,   121,   122,   125,   123,
     124,   112,   113,   114,   115,   116,    41,   -22,    42,   117,
     118,   119,   120,   121,   122,    43,   123,   124,   123,   124,
     112,   113,   114,   115,   116,    23,    80,   154,   117,   118,
     119,   120,   121,   122,    57,   123,   124,    51,    45,    81,
      42,    55,    76,   135,    58,    58,    77,    78,    82,    83,
      79,    59,    60,    61,    62,    63,    31,    32,    84,    96,
      64,    64,   150,    38,    97,   104,    85,   129,   112,   113,
     114,   115,   116,    80,   105,   106,   117,   118,   119,   120,
     121,   122,   107,   123,   124,    98,    81,    99,   126,   121,
     122,    58,   123,   124,   124,    82,    83,    80,   133,   152,
     134,   153,    37,    31,    32,    84,   107,    64,   151,   162,
      81,   163,   165,    85,    21,    58,    35,    68,    49,    82,
      83,    73,   167,    33,   108,     0,     0,    31,    32,    84,
       0,    64,   112,   113,   114,   115,   116,    85,     0,     0,
     117,   118,   119,   120,   121,   122,     0,   123,   124,   112,
     113,   114,   115,   116,     0,     0,     0,   117,   118,   119,
     120,   121,   122,     0,   123,   124,     0,     0,     0,    38,
     113,   114,   115,   116,     0,     0,     0,   117,   118,   119,
     120,   121,   122,     0,   123,   124,   114,   115,   116,     0,
       0,     0,   117,   118,   119,   120,   121,   122,     0,   123,
     124,   115,   116,     0,     0,     0,   117,   118,   119,   120,
     121,   122,   116,   123,   124,     0,   117,   118,   119,   120,
     121,   122,     0,   123,   124,   118,   119,   120,   121,   122,
       0,   123,   124
};

static const yytype_int16 yycheck[] =
{
      34,     4,    61,    21,    42,     6,    44,    41,    24,    25,
      20,    45,    13,     0,    17,    24,    25,    34,    35,    22,
      54,    80,    81,    26,    27,    16,    85,    18,    19,    45,
      38,    34,    35,    36,    40,    38,    45,    41,    97,    98,
      99,    44,    38,    46,   103,    44,    47,    14,    15,    16,
      47,    18,    19,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,    46,   126,     3,     4,
       5,     6,     7,    23,    24,    25,    11,    12,    13,    14,
      15,    16,    38,    18,    19,    11,    12,    13,    14,    15,
      16,    38,    18,    19,   153,     3,     4,     5,     6,     7,
     159,    24,    25,    11,    12,    13,    14,    15,    16,    40,
      18,    19,    47,     8,     9,    10,   150,    13,    14,    15,
      16,    38,    18,    19,     3,     4,     5,     6,     7,    44,
     164,   165,    11,    12,    13,    14,    15,    16,    46,    18,
      19,     3,     4,     5,     6,     7,    45,    41,    47,    11,
      12,    13,    14,    15,    16,    43,    18,    19,    18,    19,
       3,     4,     5,     6,     7,    42,     4,    46,    11,    12,
      13,    14,    15,    16,    46,    18,    19,    41,    45,    17,
      47,    38,    47,    45,    22,    22,    44,    46,    26,    27,
      46,    28,    29,    30,    31,    32,    34,    35,    36,    38,
      38,    38,    45,    40,    44,    46,    44,    45,     3,     4,
       5,     6,     7,     4,    46,    38,    11,    12,    13,    14,
      15,    16,    37,    18,    19,    42,    17,    44,     8,    15,
      16,    22,    18,    19,    19,    26,    27,     4,    45,    45,
      47,    47,    25,    34,    35,    36,    37,    38,    43,    45,
      17,    47,    33,    44,    13,    22,    24,    54,    42,    26,
      27,    54,   163,    23,    77,    -1,    -1,    34,    35,    36,
      -1,    38,     3,     4,     5,     6,     7,    44,    -1,    -1,
      11,    12,    13,    14,    15,    16,    -1,    18,    19,     3,
       4,     5,     6,     7,    -1,    -1,    -1,    11,    12,    13,
      14,    15,    16,    -1,    18,    19,    -1,    -1,    -1,    40,
       4,     5,     6,     7,    -1,    -1,    -1,    11,    12,    13,
      14,    15,    16,    -1,    18,    19,     5,     6,     7,    -1,
      -1,    -1,    11,    12,    13,    14,    15,    16,    -1,    18,
      19,     6,     7,    -1,    -1,    -1,    11,    12,    13,    14,
      15,    16,     7,    18,    19,    -1,    11,    12,    13,    14,
      15,    16,    -1,    18,    19,    12,    13,    14,    15,    16,
      -1,    18,    19
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    21,    49,    20,     0,    40,    51,    23,    24,    25,
      50,    52,    55,    56,    38,    38,    53,    54,    46,    41,
      50,    55,    44,    42,    44,    47,    38,    45,    50,    57,
      58,    34,    35,    85,    45,    57,    38,    54,    40,    59,
      38,    45,    47,    43,    59,    45,    60,    61,    59,    58,
      59,    41,    50,    62,    64,    38,    63,    46,    22,    28,
      29,    30,    31,    32,    38,    59,    65,    66,    67,    68,
      70,    71,    72,    73,    74,    76,    47,    44,    46,    46,
       4,    17,    26,    27,    36,    44,    46,    67,    73,    79,
      80,    81,    82,    84,    85,    86,    38,    44,    42,    44,
       8,     9,    10,    83,    46,    46,    38,    37,    87,    79,
      79,    79,     3,     4,     5,     6,     7,    11,    12,    13,
      14,    15,    16,    18,    19,    46,     8,    79,    79,    45,
      75,    79,    79,    45,    47,    45,    79,    79,    79,    79,
      79,    79,    79,    79,    79,    79,    79,    79,    79,    79,
      45,    43,    45,    47,    46,    77,    78,    79,    87,    47,
      59,    79,    45,    47,    79,    33,    69,    78,    59,    59
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
#line 109 "parser.y"
    { 	
								(yyval.prog) = new program((yyvsp[(4) - (6)].fieldDecls), (yyvsp[(5) - (6)].meDecls)); 
								root = (yyval.prog); 
							;}
    break;

  case 3:
#line 117 "parser.y"
    { 	(yyval.vType) = new varType("int"); 		;}
    break;

  case 4:
#line 119 "parser.y"
    { 	(yyval.vType) = new varType("boolean"); 	;}
    break;

  case 5:
#line 125 "parser.y"
    { 	(yyval.fieldDecls) = new fieldDeclarations(); 	;}
    break;

  case 6:
#line 127 "parser.y"
    {	(yyval.fieldDecls) = (yyvsp[(1) - (3)].fieldDecls); (yyval.fieldDecls)->add((yyvsp[(2) - (3)].fieldDecl)); ;}
    break;

  case 7:
#line 131 "parser.y"
    { 	(yyval.fieldDecl) = new fieldDeclaration((yyvsp[(1) - (2)].vType), (yyvsp[(2) - (2)].fieldN)); 	;}
    break;

  case 8:
#line 135 "parser.y"
    { 
								(yyval.fieldN) = new fieldNames(); 
								(yyval.fieldN)->add((yyvsp[(1) - (1)].singleField)); 
							;}
    break;

  case 9:
#line 140 "parser.y"
    { 	(yyval.fieldN)->add((yyvsp[(3) - (3)].singleField)); 	;}
    break;

  case 10:
#line 144 "parser.y"
    { 	(yyval.singleField) = new field((yyvsp[(1) - (1)].keyword), NULL); 	;}
    break;

  case 11:
#line 146 "parser.y"
    { 	(yyval.singleField) = new field((yyvsp[(1) - (4)].keyword), (yyvsp[(3) - (4)].integerLit)); 	;}
    break;

  case 12:
#line 151 "parser.y"
    { 	(yyval.meDecls) = (yyvsp[(2) - (2)].meDecls); (yyval.meDecls)->add((yyvsp[(1) - (2)].meDecl)); ;}
    break;

  case 13:
#line 153 "parser.y"
    { 	(yyval.meDecls) = new methodDeclarations(); ;}
    break;

  case 14:
#line 157 "parser.y"
    {
								class varType* temp = new varType("void");
								(yyval.meDecl) = new methodDeclaration(temp, (yyvsp[(2) - (6)].keyword), (yyvsp[(4) - (6)].parDecls), (yyvsp[(6) - (6)].codeBl)); 
							;}
    break;

  case 15:
#line 162 "parser.y"
    {	
								(yyval.meDecl) = new methodDeclaration((yyvsp[(1) - (6)].vType), (yyvsp[(2) - (6)].keyword), (yyvsp[(4) - (6)].parDecls), (yyvsp[(6) - (6)].codeBl)); 	
							;}
    break;

  case 16:
#line 166 "parser.y"
    {
								class varType* temp = new varType("void");
								(yyval.meDecl) = new methodDeclaration(temp, (yyvsp[(2) - (5)].keyword), NULL, (yyvsp[(5) - (5)].codeBl)); 
							;}
    break;

  case 17:
#line 171 "parser.y"
    {	
								(yyval.meDecl) = new methodDeclaration((yyvsp[(1) - (5)].vType), (yyvsp[(2) - (5)].keyword), NULL, (yyvsp[(5) - (5)].codeBl)); 	
							;}
    break;

  case 18:
#line 177 "parser.y"
    {	
								(yyval.parDecls) = new parameterDeclarations(); 
								(yyval.parDecls)->add((yyvsp[(1) - (1)].parDecl)); 
							;}
    break;

  case 19:
#line 182 "parser.y"
    {	(yyval.parDecls)->add((yyvsp[(3) - (3)].parDecl)); 	;}
    break;

  case 20:
#line 187 "parser.y"
    {	(yyval.parDecl) = new parameterDeclaration((yyvsp[(1) - (2)].vType), (yyvsp[(2) - (2)].keyword)); 	;}
    break;

  case 21:
#line 193 "parser.y"
    { 	(yyval.codeBl) = new codeBlock((yyvsp[(2) - (3)].Bl)); ;}
    break;

  case 22:
#line 197 "parser.y"
    { 	(yyval.Bl) = new block(NULL, NULL); ;}
    break;

  case 23:
#line 199 "parser.y"
    { 	(yyval.Bl) = new block((yyvsp[(1) - (2)].varDecls), (yyvsp[(2) - (2)].stmts)); ;}
    break;

  case 24:
#line 205 "parser.y"
    { 	(yyval.varDecls) = new varDeclarations();		;}
    break;

  case 25:
#line 207 "parser.y"
    { 	(yyval.varDecls)->add((yyvsp[(2) - (3)].varDecl)); ;}
    break;

  case 26:
#line 211 "parser.y"
    { 	(yyval.varDecl) = new varDeclaration((yyvsp[(1) - (2)].vType), (yyvsp[(2) - (2)].varN)); 	;}
    break;

  case 27:
#line 215 "parser.y"
    { 
								(yyval.varN) = new varNames(); 
								(yyval.varN)->add((yyvsp[(1) - (1)].keyword)); 
							;}
    break;

  case 28:
#line 220 "parser.y"
    { 	(yyval.varN)->add((yyvsp[(3) - (3)].keyword)); ;}
    break;

  case 29:
#line 226 "parser.y"
    { 	(yyval.stmts) = new statements();  ;}
    break;

  case 30:
#line 228 "parser.y"
    { 	(yyval.stmts)->add((yyvsp[(2) - (2)].stmt)); 		;}
    break;

  case 31:
#line 231 "parser.y"
    { (yyval.stmt) = (yyvsp[(1) - (1)].Assign); ;}
    break;

  case 32:
#line 232 "parser.y"
    { (yyval.stmt) = (yyvsp[(1) - (1)].mCSt); ;}
    break;

  case 33:
#line 233 "parser.y"
    { (yyval.stmt) = (yyvsp[(1) - (1)].If); ;}
    break;

  case 34:
#line 234 "parser.y"
    { (yyval.stmt) = (yyvsp[(1) - (1)].For); ;}
    break;

  case 35:
#line 235 "parser.y"
    { (yyval.stmt) = (yyvsp[(1) - (1)].Return); ;}
    break;

  case 36:
#line 236 "parser.y"
    { (yyval.stmt) = (yyvsp[(1) - (1)].ter); ;}
    break;

  case 37:
#line 237 "parser.y"
    { (yyval.stmt) = (yyvsp[(1) - (1)].codeBl); ;}
    break;

  case 38:
#line 241 "parser.y"
    { 	(yyval.Assign) = new assignSt((yyvsp[(1) - (4)].loc), (yyvsp[(2) - (4)].asOp), (yyvsp[(3) - (4)].Exp)); ;}
    break;

  case 39:
#line 245 "parser.y"
    { 	(yyval.loc) = new location((yyvsp[(1) - (1)].keyword), NULL); ;}
    break;

  case 40:
#line 247 "parser.y"
    { 	(yyval.loc) = new location((yyvsp[(1) - (4)].keyword), (yyvsp[(3) - (4)].Exp)); ;}
    break;

  case 41:
#line 251 "parser.y"
    { 	(yyval.If) = new ifSt((yyvsp[(3) - (6)].Exp), (yyvsp[(5) - (6)].codeBl), (yyvsp[(6) - (6)].Else)); ;}
    break;

  case 42:
#line 255 "parser.y"
    {	(yyval.Else) = new elseSt(NULL); ;}
    break;

  case 43:
#line 257 "parser.y"
    {	(yyval.Else) = new elseSt((yyvsp[(2) - (2)].codeBl)); ;}
    break;

  case 44:
#line 261 "parser.y"
    { 	(yyval.For) = new forSt((yyvsp[(2) - (7)].keyword), (yyvsp[(4) - (7)].Exp), (yyvsp[(6) - (7)].Exp), (yyvsp[(7) - (7)].codeBl)); ;}
    break;

  case 45:
#line 265 "parser.y"
    { 	(yyval.Return) = new returnSt((yyvsp[(2) - (3)].Exp)); 		;}
    break;

  case 46:
#line 267 "parser.y"
    {	(yyval.Return) = new returnSt(NULL); 	;}
    break;

  case 47:
#line 271 "parser.y"
    {	(yyval.ter) = new terminalSt("break"); 		;}
    break;

  case 48:
#line 273 "parser.y"
    { 	(yyval.ter) = new terminalSt("continue"); 	;}
    break;

  case 49:
#line 277 "parser.y"
    { 	(yyval.mCSt) = (yyvsp[(1) - (2)].mC); 	;}
    break;

  case 50:
#line 279 "parser.y"
    { 	(yyval.mCSt) = (yyvsp[(1) - (2)].cC); 	;}
    break;

  case 51:
#line 282 "parser.y"
    { 	(yyval.mC) = new methodCall((yyvsp[(3) - (4)].mCArgs)); 	;}
    break;

  case 52:
#line 284 "parser.y"
    { 	(yyval.mC) = new methodCall(NULL);	;}
    break;

  case 53:
#line 288 "parser.y"
    { 
								(yyval.mCArgs) = new methodCallArgs(); 
							  	(yyval.mCArgs)->add((yyvsp[(1) - (1)].Exp)); 
							;}
    break;

  case 54:
#line 293 "parser.y"
    {
								(yyval.mCArgs)->add((yyvsp[(3) - (3)].Exp)); 
							;}
    break;

  case 55:
#line 300 "parser.y"
    { 	(yyval.cC) = new calloutCall((yyvsp[(3) - (4)].stringLit), NULL); ;}
    break;

  case 56:
#line 302 "parser.y"
    { 	(yyval.cC) = new calloutCall((yyvsp[(3) - (6)].stringLit), (yyvsp[(5) - (6)].CArgs)); ;}
    break;

  case 57:
#line 307 "parser.y"
    {
								(yyval.CArgs) = new CalloutArgs(); 
								(yyval.CArgs)->add((yyvsp[(1) - (1)].cArgs)); 
							;}
    break;

  case 58:
#line 312 "parser.y"
    {
								(yyval.CArgs)->add((yyvsp[(3) - (3)].cArgs)); 
							;}
    break;

  case 59:
#line 318 "parser.y"
    { 	(yyval.cArgs) = new calloutArg(NULL, (yyvsp[(1) - (1)].Exp)); ;}
    break;

  case 60:
#line 320 "parser.y"
    { 	(yyval.cArgs) = new calloutArg((yyvsp[(1) - (1)].stringLit), NULL); ;}
    break;

  case 61:
#line 323 "parser.y"
    { (yyval.Exp) = (yyvsp[(1) - (1)].loc); ;}
    break;

  case 62:
#line 324 "parser.y"
    { (yyval.Exp) = (yyvsp[(1) - (1)].mCSt); ;}
    break;

  case 63:
#line 325 "parser.y"
    { (yyval.Exp) = (yyvsp[(1) - (1)].characterLit); ;}
    break;

  case 64:
#line 326 "parser.y"
    { (yyval.Exp) = (yyvsp[(1) - (1)].integerLit); ;}
    break;

  case 65:
#line 327 "parser.y"
    { (yyval.Exp) = (yyvsp[(1) - (1)].booleanLit); ;}
    break;

  case 66:
#line 328 "parser.y"
    { (yyval.Exp) = (yyvsp[(1) - (1)].binExp); ;}
    break;

  case 67:
#line 329 "parser.y"
    { (yyval.Exp) = (yyvsp[(1) - (1)].unExp); ;}
    break;

  case 68:
#line 330 "parser.y"
    { (yyval.Exp) = (yyvsp[(1) - (1)].enExp); ;}
    break;

  case 69:
#line 334 "parser.y"
    { (yyval.binExp) = new binExpr((yyvsp[(1) - (3)].Exp), "+", (yyvsp[(3) - (3)].Exp));;}
    break;

  case 70:
#line 336 "parser.y"
    { (yyval.binExp) = new binExpr((yyvsp[(1) - (3)].Exp), "-", (yyvsp[(3) - (3)].Exp));;}
    break;

  case 71:
#line 338 "parser.y"
    { (yyval.binExp) = new binExpr((yyvsp[(1) - (3)].Exp), "*", (yyvsp[(3) - (3)].Exp));;}
    break;

  case 72:
#line 340 "parser.y"
    { (yyval.binExp) = new binExpr((yyvsp[(1) - (3)].Exp), "/", (yyvsp[(3) - (3)].Exp));;}
    break;

  case 73:
#line 342 "parser.y"
    { (yyval.binExp) = new binExpr((yyvsp[(1) - (3)].Exp), "%", (yyvsp[(3) - (3)].Exp));;}
    break;

  case 74:
#line 344 "parser.y"
    { (yyval.binExp) = new binExpr((yyvsp[(1) - (3)].Exp), ">", (yyvsp[(3) - (3)].Exp));;}
    break;

  case 75:
#line 346 "parser.y"
    { (yyval.binExp) = new binExpr((yyvsp[(1) - (3)].Exp), "<", (yyvsp[(3) - (3)].Exp));;}
    break;

  case 76:
#line 348 "parser.y"
    { (yyval.binExp) = new binExpr((yyvsp[(1) - (3)].Exp), ">=", (yyvsp[(3) - (3)].Exp));;}
    break;

  case 77:
#line 350 "parser.y"
    { (yyval.binExp) = new binExpr((yyvsp[(1) - (3)].Exp), "<=", (yyvsp[(3) - (3)].Exp));;}
    break;

  case 78:
#line 352 "parser.y"
    { (yyval.binExp) = new binExpr((yyvsp[(1) - (3)].Exp), "==", (yyvsp[(3) - (3)].Exp));;}
    break;

  case 79:
#line 354 "parser.y"
    { (yyval.binExp) = new binExpr((yyvsp[(1) - (3)].Exp), "!=", (yyvsp[(3) - (3)].Exp));;}
    break;

  case 80:
#line 356 "parser.y"
    { (yyval.binExp) = new binExpr((yyvsp[(1) - (3)].Exp), "&&", (yyvsp[(3) - (3)].Exp));;}
    break;

  case 81:
#line 358 "parser.y"
    { (yyval.binExp) = new binExpr((yyvsp[(1) - (3)].Exp), "||", (yyvsp[(3) - (3)].Exp));;}
    break;

  case 82:
#line 362 "parser.y"
    { (yyval.enExp) = new enclosedExpr((yyvsp[(2) - (3)].Exp)); ;}
    break;

  case 83:
#line 366 "parser.y"
    { (yyval.unExp) = new unaryExpr("-", (yyvsp[(2) - (2)].Exp)); ;}
    break;

  case 84:
#line 368 "parser.y"
    { (yyval.unExp) = new unaryExpr("!", (yyvsp[(2) - (2)].Exp)); ;}
    break;

  case 85:
#line 373 "parser.y"
    { (yyval.asOp) = new assignOp("="); ;}
    break;

  case 86:
#line 375 "parser.y"
    { (yyval.asOp) = new assignOp("+="); ;}
    break;

  case 87:
#line 377 "parser.y"
    { (yyval.asOp) = new assignOp("-="); ;}
    break;

  case 88:
#line 382 "parser.y"
    { (yyval.characterLit) = new charLiteral((yyvsp[(1) - (1)].strLit)); ;}
    break;

  case 89:
#line 386 "parser.y"
    { (yyval.integerLit) = new intLiteral((yyvsp[(1) - (1)].intLit)); 	;}
    break;

  case 90:
#line 388 "parser.y"
    { (yyval.integerLit) = new intLiteral((yyvsp[(1) - (1)].intLit)); 	;}
    break;

  case 91:
#line 392 "parser.y"
    { (yyval.booleanLit) = new boolLiteral((yyvsp[(1) - (1)].boolLit)); ;}
    break;

  case 92:
#line 394 "parser.y"
    { (yyval.booleanLit) = new boolLiteral((yyvsp[(1) - (1)].boolLit)); ;}
    break;

  case 93:
#line 398 "parser.y"
    { (yyval.stringLit) = new stringLiteral((yyvsp[(1) - (1)].strLit)); ;}
    break;


/* Line 1267 of yacc.c.  */
#line 2099 "parser.tab.c"
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


#line 401 "parser.y"

int main(int argc, char **argv) {
 	Visitor* v = new Visitor(); 
 	yyparse();
 	v->visit(root); 
 	return 0; 
}

void yyerror(const char *s) {
 	fprintf(stderr, "error: %s\n", s);
 	return;
}

