%{
    #include "ast.h"
    #include "parser.tab.h"
    #define YY_DECL extern "C" int yylex()
    extern union Node yylval;
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

"void" 					{ return VOID; 				}
"int" 					{ return INT; 				}
"boolean" 				{ return BOOLEAN; 			}
"true" 					{ return TRUE; 				}
"false" 				{ return FALSE; 			}

"break" 				{ return BREAK; 			}
"continue" 				{ return CONTINUE; 			}
"return" 				{ return RETURN; 			}

"for" 					{ return FOR; 				}

"if" 					{ return IF; 				}
"else" 					{ return ELSE;	 			}

{digit}+				{ return NUM; 				}
{alpha}{alpha_num}*   	{ yylval.lit = strdup(yytext); 
						return ID;				 	}
{string}				{ return STRING; 			}
"0x"{hex_digit}+ 		{ return HEX_LITERAL;		}
{character}				{ return CHAR_LITERAL;		}
"+"						{ return ADD; 				}
"-"						{ return SUBTRACT; 			}
"*"						{ return MULTIPLY; 			}
"/"						{ return DIVIDE; 			}
"="						{ return EQUAL; 			}
"+="    				{ return PLUS_EQUAL; 		}
"-="    				{ return MINUS_EQUAL; 		}

"=="    				{ return EQUALITY; 			}
"!="    				{ return NOT_EQUAL; 		}
">="    				{ return GREATER_EQUAL; 	}
"<="    				{ return LESS_EQUAL; 		}
">"     				{ return GREATER; 			}
"<"     				{ return LESS; 				}
"&&"    				{ return CONDITIONAL_AND; 	}
"||"    				{ return CONDITIONAL_OR; 	}
"!"     				{ return NOT; 				}
"|"     				{ return ABSOLUTE; 			}
"%"     				{ return MODULO; 			}

"("     				{ return OPEN;  			}
")"     				{ return CLOSE;	 			}
"{"     				{ return CURLY_OPEN;   		}
"}"     				{ return CURLY_CLOSE;  		}
"["     				{ return SQUARE_OPEN;  		}
"]"     				{ return SQUARE_CLOSE; 		}

";"     				{ return SEMI_COLON; 		}
","     				{ return COMMA; 			}

{delim}    				{}
"//".*					{} 
.						{ printf("Unidentified character %c.\n", *yytext); 	}
%%
