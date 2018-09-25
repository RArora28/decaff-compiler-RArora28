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
"break" { return BREAK; }
"continue" { return CONTINUE; }
"return" { return RETURN; }
"for" { return FOR; }
"if" { return IF; }
"else" { return ELSE; }
"true" { return TRUE; }
"false" { return FALSE; }
[0-9]+	{ yylval = atoi(yytext); return Num; }
[A-Za-z]+ { return Id;}

"+"	{ return ADD; }
"-"	{ return SUBTRACT; }
"*"	{ return MULTIPLY; }
"/"	{ return DIVIDE; }

"="     { return EQUAL; }
"+="     { return PLUSEQUAL; }
"-="     { return MINUSEQUAL; }
"=="     { return EQUALITY; }
"!="     { return NOTEQUAL; }
">="     { return GREATEREQUAL; }
"<="     { return LESSEQUAL; }
">"     { return GREATER; }
"<"     { return LESS; }
"&&"     { return CONDITIONALAND; }
"||"     { return CONDITIONALOR; }
"!"     { return NOT; }
"|"     { return ABSOLUTE; }
"%"     { return MODULO; }

"{"     { return CURLYOPEN; }
"}"     { return CURLYCLOSE; }
"["     { return SQUAREOPEN; }
"]"     { return SQUARECLOSE; }
"("     { return NORMALOPEN; }
")"     { return NORMALCLOSE; }

";"     { return SEMICOLON; }
","     { return COMMA; }

\n      {}
[ \t]+   { /* */ }
.	{ printf("Character is: %c\n", *yytext); }
%%
