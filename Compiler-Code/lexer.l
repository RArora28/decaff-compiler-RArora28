{%

%}

digit [0-9]
alpha [a-zA-Z]
hex_digit [0-9a-fA-F]
delim [ \t+]
char [ -~] // isko theek kar 
character \'{char}'\
string '{char}*'

%%
"class" { return CLASS; }

"callout" { return CALLOUT; }

"void" {  VOID; }
"int" { return INT }
"boolean" { return BOOLEAN }
"true" { return TRUE; }
"false" { return FALSE; }

"break" { return BREAK; }
"continue" { return CONTINUE; }
"return" { return RETURN; }

"for" { return FOR; }

"if" { return IF; }
"else" { return ELSE; }

[0-9]+	{ yylval = atoi(yytext); return NUM; }
[A-Za-z]+ { return ID;}

"+"	{ return ADD; }
"-"	{ return SUBTRACT; }
"*"	{ return MULTIPLY; }
"/"	{ return DIVIDE; }

"="     { return EQUAL; }
"+="     { return PLUS_EQUAL; }
"-="     { return MINUS_EQUAL; }
"=="     { return EQUALITY; }
"!="     { return NOT_EQUAL; }
">="     { return GREATER_EQUAL; }
"<="     { return LESS_EQUAL; }
">"     { return GREATER; }
"<"     { return LESS; }
"&&"     { return CONDITIONAL_AND; }
"||"     { return CONDITIONAL_OR; }
"!"     { return NOT; }
"|"     { return ABSOLUTE; }
"%"     { return MODULO; }

"{"     { return CURLY_OPEN; }
"}"     { return CURLY_CLOSE; }
"["     { return SQUARE_OPEN; }
"]"     { return SQUARE_CLOSE; }
"("     { return NORMAL_OPEN; }
")"     { return NORMAL_CLOSE; }

";"     { return SEMI_COLON; }
","     { return COMMA; }

\n      {}
[ \t]+   { /* */ }
.	{ printf("Character is: %c\n", *yytext); }
%%
