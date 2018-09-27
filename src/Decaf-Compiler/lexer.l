%{
	#include "parser.tab.h"
%}

digit 		[0-9]
alpha 		[a-zA-Z]
alpha_num 	[0-9a-zA-Z]
hex_alpha 	[0-9a-fA-F]
char 		[ -!]|[#-&]|[(-\[]|[\]-~]|[\\"]|[\\']|[\\\\]|[\t]|[\n]
character 	\'{char}\'
delim 		[ \t\n]+

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

digit+					{ return NUM; 				}
{alpha}{alpha_num}*   	{ return ID;				}
{char}* 				{ return STRING; 			}

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
.						{ printf("Unidentified character %c.\n", *yytext); }

%%
