%{
	#include "parser.tab.h"
%}

digit [0-9]
alpha [a-zA-Z]
alpha_num [0-9a-zA-Z]
hex_digit [0-9a-fA-F]
single [\x20\x21\x23-\x26\x28-\x5b\x5d-\x7e]
addons \\[nt\'\"\\]
char {single}|{addons}
character \'{char}\'
string \"{char}*\"
delim [ \t\n]+

%% 

"Program"   			{ return PROGRAM; 			}
"class" 				{ return CLASS; 			}

"callout" 				{ return CALLOUT; 			}

"void" 					{ printf("%s ", yytext); return VOID; 				}
"int" 					{ printf("%s ", yytext); return INT; 				}
"boolean" 				{ printf("%s ", yytext); return BOOLEAN; 			}
"true" 					{ printf("%s ", yytext); return TRUE; 				}
"false" 				{ printf("%s ", yytext); return FALSE; 			}

"break" 				{ printf("%s ", yytext); return BREAK; 			}
"continue" 				{ printf("%s ", yytext); return CONTINUE; 			}
"return" 				{ printf("%s ", yytext); return RETURN; 			}

"for" 					{ printf("%s ", yytext); return FOR; 				}

"if" 					{ printf("%s ", yytext); return IF; 				}
"else" 					{ printf("%s ", yytext); return ELSE;	 			}

{digit}+				{ printf("%s ", yytext); return NUM; 				}
{alpha}{alpha_num}*   	{ printf("%s ", yytext); return ID;				}
{string}				{ printf("%s ", yytext); return STRING; 			}
"0x"{hex_digit}+ 		{ printf("%s ", yytext); return HEX_LITERAL;			}
{character}				{ printf("%s ", yytext); return CHAR_LITERAL;			}
"+"						{ printf("%s ", yytext); return ADD; 				}
"-"						{ printf("%s ", yytext); return SUBTRACT; 			}
"*"						{ printf("%s ", yytext); return MULTIPLY; 			}
"/"						{ printf("%s ", yytext); return DIVIDE; 			}
"="						{ printf("%s ", yytext); return EQUAL; 			}
"+="    				{ printf("%s ", yytext); return PLUS_EQUAL; 		}
"-="    				{ printf("%s ", yytext); return MINUS_EQUAL; 		}

"=="    				{ printf("%s ", yytext); return EQUALITY; 			}
"!="    				{ printf("%s ", yytext); return NOT_EQUAL; 		}
">="    				{ printf("%s ", yytext); return GREATER_EQUAL; 	}
"<="    				{ printf("%s ", yytext); return LESS_EQUAL; 		}
">"     				{ printf("%s ", yytext); return GREATER; 			}
"<"     				{ printf("%s ", yytext); return LESS; 				}
"&&"    				{ printf("%s ", yytext); return CONDITIONAL_AND; 	}
"||"    				{ printf("%s ", yytext); return CONDITIONAL_OR; 	}
"!"     				{ printf("%s ", yytext); return NOT; 				}
"|"     				{ printf("%s ", yytext); return ABSOLUTE; 			}
"%"     				{ printf("%s ", yytext); return MODULO; 			}

"("     				{ printf("%s ", yytext); return OPEN;  			}
")"     				{ printf("%s ", yytext); return CLOSE;	 			}
"{"     				{ printf("%s ", yytext); return CURLY_OPEN;   		}
"}"     				{ printf("%s ", yytext); return CURLY_CLOSE;  		}
"["     				{ printf("%s ", yytext); return SQUARE_OPEN;  		}
"]"     				{ printf("%s ", yytext); return SQUARE_CLOSE; 		}

";"     				{ printf("%s ", yytext); return SEMI_COLON; 		}
","     				{ printf("%s ", yytext); return COMMA; 			}

{delim}    				{}
"//".*					{} 
.						{ printf("Unidentified character %c.\n", *yytext); }
%%
