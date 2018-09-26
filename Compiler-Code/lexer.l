%{
	#include "parser.tab.h"
%}

digit [0-9]


%% 

"program"   { return PROGRAM; 	}
"class" 	{ return CLASS; 	}

"callout" 	{ return CALLOUT; }

"void" 		{ return VOID; }
"int" 		{ return INT; }
"boolean" 	{ return BOOLEAN; }
"true" 		{ return TRUE; }
"false" 	{ return FALSE; }

"break" 	{ return BREAK; }
"continue" 	{ return CONTINUE; }
"return" 	{ return RETURN; }

"for" 	{ return FOR; }

"if" 	{ return IF; }
"else" 	{ return ELSE; }

[0-9]+		{ yylval = atoi(yytext); return NUM; }
[A-Za-z]+   { return ID;}

"+"		{ return ADD; }
"-"		{ return SUBTRACT; }
"*"		{ return MULTIPLY; }
"/"		{ return DIVIDE; }

"="		{ return EQUAL; }
"+="    { return PLUS_EQUAL; }
"-="    { return MINUS_EQUAL; }
"=="    { return EQUALITY; }
"!="    { return NOT_EQUAL; }
">="    { return GREATER_EQUAL; }
"<="    { return LESS_EQUAL; }
">"     { return GREATER; }
"<"     { return LESS; }
"&&"    { return CONDITIONAL_AND; }
"||"    { return CONDITIONAL_OR; }
"!"     { return NOT; }
"|"     { return ABSOLUTE; }
"%"     { return MODULO; }

"("     { return NORMAL_OPEN;  }
")"     { return NORMAL_CLOSE; }
"{"     { return CURLY_OPEN;   }
"}"     { return CURLY_CLOSE;  }
"["     { return SQUARE_OPEN;  }
"]"     { return SQUARE_CLOSE; }

";"     { return SEMI_COLON; }
","     { return COMMA; }

\n      {}
[ \t]+  { /* abcd */ }
.	{ printf("Unidentified character %c.\n", *yytext); }
%%
