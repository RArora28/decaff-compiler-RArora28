%{
	#include <bits/stdc++.h>	
	#include "ast.h"
	extern "C" int yylex();
	extern "C" int yyparse();
	extern "C" void yyerror(const char *s);
	extern union Node yylval;
%} 

/* token declaration */ 
%token PROGRAM 
%token CLASS 
%token CALLOUT
%token VOID INT BOOLEAN 
%token <boolLit> TRUE 
%token <boolLit> FALSE 
%token BREAK CONTINUE RETURN 
%token FOR 
%token IF ELSE 
%token <intLit> NUM
%token <intLit> HEX_LITERAL
%token <strLit> CHAR_LITERAL
%token <strLit> STRING 
%token <keyword> ID
%token ADD SUBTRACT MULTIPLY DIVIDE 
%token EQUAL PLUS_EQUAL MINUS_EQUAL EQUALITY 
%token NOT_EQUAL GREATER_EQUAL LESS_EQUAL GREATER LESS 
%token CONDITIONAL_AND CONDITIONAL_OR
%token NOT ABSOLUTE MODULO 
%token CURLY_OPEN CURLY_CLOSE 
%token SQUARE_OPEN SQUARE_CLOSE 
%token OPEN CLOSE 
%token SEMI_COLON COMMA 


%type <prog> 			program_declaration;
%type <vType> 			var_type; 

%type <fieldDecls> 		field_declarations; 
%type <fieldDecl> 		field_declaration; 
%type <fieldN> 			field_names; 
%type <singleField> 	field_name;	

%type <meDecls> method_declarations; 
%type <meDecl> method_declaration; 
%type <parDecls> parameter_declarations; 
%type <nonEmpParDecl> non_empty_parameter_declaration; 
%type <parDecl> parameter_declaration; 

%type <codeBl> code_block; 
%type <Bl> block; 

%type <varDecls> var_declarations;  
%type <varDecl> var_declaration; 
%type <varN> var_names; 
%type <stmts> statements; 

%type <stmt> statement; 
%type <Assign> assign_statement; 
%type <If> if_statement; 
%type <Else> else_statement;
%type <For> for_statement; 
%type <Return> return_statement; 
%type <retVal> return_value; 
%type <ter> terminal_statement; 
%type <loc> location; 

%type <mCSt> method_call_statment; 
%type <mC> method_call; 
%type <nC> normal_call; 
%type <mCArgs> method_call_args; 
%type <nECArgs> non_empty_method_call_args; 

%type <cC> callout_call; 
%type <nECalloutArgs> non_empty_callout_args; 
%type <cArgs> callout_arg; 

%type <Exp> expr; 
%type <binExp> binary_expr; 
%type <unExp> unary_expr; 
%type <enExp> enclosed_expr; 

%type <asOp> assign_op; 
%type <integerLit> 		int_literal;	
%type <booleanLit> 		bool_literal;
%type <characterLit> 	char_literal;		
%type <stringLit> 		string_literal;	

%%

/* Outermost Match */ 
program_declaration		: 	CLASS PROGRAM CURLY_OPEN field_declarations 									method_declarations CURLY_CLOSE
							{ $$ = new program($4, $5); }

						; 
/* Data types in grammar */ 
var_type				: 	INT  	
							{ $$ = new varType("int"); }
						| 	BOOLEAN
							{ $$ = new varType("boolean"); }
						; 


/* Field Declaration */ 
field_declarations		: 	/* Epsilon */ 	
							{ $$ = new fieldDeclarations(); }
						| 	field_declarations field_declaration SEMI_COLON
							{ $$->add($2); }
						;

field_declaration 		: 	var_type field_names
							{ $$ = new fieldDeclaration($1, $2); }
						;

field_names				: 	field_name 
							{ 
								$$ = new fieldNames(); 
								$$->add($1); 
							}
						| 	field_names COMMA field_name
							{ $$->add($3); }
						;

field_name 				: 	ID 
						  	{
						  		class intLiteral* temp = new intLiteral(int(-1));  
						  		$$ = new field($1, temp); 
						  	}
						| 	ID SQUARE_OPEN int_literal SQUARE_CLOSE
							{ $$ = new field($1, $3); }
						; 

/* Declaration for a method */ 
method_declarations		: 	/* Epsilon */
							{ $$ = new methodDeclarations(); }
						| 	method_declarations method_declaration
							{ $$->add($2); }
						; 

method_declaration 		: 	VOID ID OPEN parameter_declarations CLOSE code_block 
							{
								class varType* temp = new varType("void");
								$$ = new methodDeclaration(temp, $2, $4, $6); 
							}
						| 	var_type ID OPEN parameter_declarations CLOSE 			code_block   
							{	
								$$ = new methodDeclaration($1, $2, $4, $6); 	
							}
						; 

parameter_declarations	: 	/* Epsilon */ 
							{ $$ = new parameterDeclarations(NULL); }
						| 	non_empty_parameter_declaration
							{ $$ = new parameterDeclarations($1); }
						;

non_empty_parameter_declaration
						: 	parameter_declaration 
							{ 
								$$ = new nonEmptyParDecl(); 
								$$->add($1); 
							}
						| 	non_empty_parameter_declaration COMMA 
							parameter_declaration
							{
								$$->add($3);  
							}
						; 

parameter_declaration 	: 	var_type ID
							{	
								$$ = new parameterDeclaration($1, $2); 
							}
						; 


/* Block of code inside a method */ 
code_block				: 	CURLY_OPEN block CURLY_CLOSE
							{ $$ = new codeBlock($2); }
						; 

block 					: 	/* Epsilon */ 
							{ $$ = new block(NULL, NULL); }
						| 	var_declarations statements
							{ $$ = new block($1, NULL); }
						; 


/* Variable Declarations inside a code block */ 
var_declarations		:  	/* Epsilon */ 
							{ $$ = new varDeclarations(); }
						| 	var_declarations var_declaration SEMI_COLON 
							{ $$->add($2); }
						;

var_declaration 		: 	var_type var_names 
							{ $$ = new varDeclaration($1, $2); }
						;

var_names				: 	ID 
							{ 
								$$ = new varNames(); 
								$$->add($1); 
							}
						| 	var_names COMMA ID 
							{ $$->add($3); }
						; 


/* Set of statements in a code block */ 
statements				: 	/* Epsilon */
							{ $$ = new statements() }
						| 	statements statement
							{ $$->add($2); }
						; 

statement 				: 	assign_statement 		{ $$ = $1; }	
						| 	method_call_statment 	{ $$ = $1; }
						| 	if_statement 			{ $$ = $1; }
						|   for_statement 			{ $$ = $1; } 
						| 	return_statement  		{ $$ = $1; } 
						| 	terminal_statement 		{ $$ = $1; } 
						| 	code_block				{ $$ = $1; }  
						; 

assign_statement		: 	location assign_op expr SEMI_COLON
							{ $$ = new assignSt($1, $2, $3); }
						; 

location				: 	ID 
							{ $$ = new location($1, NULL); }
						| 	ID SQUARE_OPEN expr SQUARE_CLOSE 
							{ $$ = new location($1, $3); } 
						; 

if_statement 			: 	IF OPEN expr CLOSE code_block else_statement 
							{ $$ = new ifSt($3, $5, $6); }
						; 

else_statement			:  	/* Epsilon */ 	
							{$$ = new elseSt(NULL); }
						| 	ELSE code_block
							{$$ = new elseSt($2); } 
						;

for_statement 			: 	FOR ID EQUAL expr COMMA expr code_block
							{ $$ = new forSt($2, $4, $6, $7); 	} 
						; 

return_statement 		: 	RETURN return_value SEMI_COLON
							{ $$ = new returnSt($2)}
						
return_value			: 	/* Epsilon */ 
							{ $$ = new returnVal(NULL); 	  	}
						| 	expr
							{ $$ = new returnVal($1); 			}
						;

terminal_statement	 	: 	BREAK SEMI_COLON
							{ $$ = new terminalSt("break"); 	}
						| 	CONTINUE SEMI_COLON
							{ $$ = new terminalSt("continue"); 	}
						; 


method_call_statment 	: 	method_call SEMI_COLON
							{ new methodCallSt($1); }
						; 

method_call 			: 	normal_call
							{ $$ = $1; }  
						| 	callout_call
							{ $$ = $1; }  
						; 

normal_call 			: 	ID OPEN method_call_args CLOSE
							{ $$ = new normalCall($3); }
						; 

method_call_args 		: 	/* Epsilon */ 
							{ $$ = NULL }  
						| 	non_empty_method_call_args
							{ $$ = $1; 	}
						;

non_empty_method_call_args
						: 	expr
							{ 
								$$ = new nonEmptyCallArgs(); 
							  	$$->add($1); 
							}
						| 	non_empty_method_call_args COMMA expr
							{
								$$->add($3); 
							}
						;
						
/* General Method Call */ 
callout_call			: 	CALLOUT OPEN string_literal CLOSE 
							{ $$ = new calloutCall($3, NULL); }
						| 	CALLOUT OPEN string_literal COMMA 						non_empty_callout_args CLOSE
							{ $$ = new calloutCall($3, $5); }
						; 


non_empty_callout_args 	: 	callout_arg 
							{
								$$ = new nonEmptyCalloutArgs(); 
								$$->add($1); 
							}
						| 	non_empty_callout_args COMMA callout_arg
							{
								$$->add($3); 
							}
						;

callout_arg 			: 	expr
							{ $$ = new calloutArg(NULL, $1); }
						| 	string_literal
							{ $$ = new calloutArg($1, NULL); }
						;

expr					: 	location				{ $$ = $1; }
						| 	method_call 			{ $$ = $1; }
						| 	char_literal 			{ $$ = $1; }
						|	int_literal				{ $$ = $1; }
						| 	bool_literal			{ $$ = $1; }
						| 	binary_expr				{ $$ = $1; }
						|	unary_expr 				{ $$ = $1; }
						| 	enclosed_expr 			{ $$ = $1; }
						; 

binary_expr				: 	expr ADD expr 		
							{ $$ = new binExpr($1, "+", $3);}
						| 	expr SUBTRACT expr
							{ $$ = new binExpr($1, "-", $3);}
						| 	expr MULTIPLY expr
							{ $$ = new binExpr($1, "*", $3);}
						| 	expr DIVIDE expr
							{ $$ = new binExpr($1, "/", $3);}
						| 	expr MODULO expr
							{ $$ = new binExpr($1, "%", $3);}
						| 	expr GREATER expr
							{ $$ = new binExpr($1, ">", $3);}
						|	expr LESS expr
							{ $$ = new binExpr($1, "<", $3);}
						| 	expr GREATER_EQUAL expr
							{ $$ = new binExpr($1, ">=", $3);}
						| 	expr LESS_EQUAL expr
							{ $$ = new binExpr($1, "<=", $3);}
						|	expr EQUALITY expr
							{ $$ = new binExpr($1, "==", $3);}
						| 	expr NOT_EQUAL expr
							{ $$ = new binExpr($1, "!=", $3);}
						| 	expr CONDITIONAL_AND expr
							{ $$ = new binExpr($1, "&&", $3);}
						| 	expr CONDITIONAL_OR expr
							{ $$ = new binExpr($1, "||", $3);}
						; 

enclosed_expr 			: 	OPEN expr CLOSE
							{ $$ = new enclosedExpr($2); }
						; 

unary_expr 				: 	SUBTRACT expr
							{ $$ = new unaryExpr("-", $2); }
						| 	NOT expr 
							{ $$ = new unaryExpr("!", $2); }
						; 

/* All operations in the grammar */ 
assign_op				:	EQUAL
							{ $$ = new assignOp("="); } 
						| 	PLUS_EQUAL 
							{ $$ = new assignOp("+="); }
						|	MINUS_EQUAL
							{ $$ = new assignOp("-="); }
						;


char_literal 			: 	CHAR_LITERAL
							{ $$ = new charLiteral($1); }
						;

int_literal 			: 	NUM
							{ $$ = new intLiteral($1); 	} 
						| 	HEX_LITERAL
							{ $$ = new intLiteral($1); 	}
						;

bool_literal 			:	TRUE 
							{ $$ = new boolLiteral($1); }
						| 	FALSE
							{ $$ = new boolLiteral($1); }
						;

string_literal 			: 	STRING
							{ $$ = new stringLiteral($1); }
						; 

%%

int main(int argc, char **argv) {
 	yyparse();
 	return 0; 
}

void yyerror(const char *s) {
 	fprintf(stderr, "error: %s\n", s);
 	return;
}
