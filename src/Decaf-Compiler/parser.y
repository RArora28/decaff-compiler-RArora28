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
						| 	method_call_statment 
						| 	if_statement 			{ $$ = $1; }
						|   for_statement 			{ $$ = $1; } 
						| 	return_statement  		{ $$ = $1; } 
						| 	terminal_statement 		{ $$ = $1; } 
						/* | 	code_block				{ $$ = $1; } */ 
						; 

assign_statement		: 	location assign_op expr SEMI_COLON
							{ $$ = new assignSt($1); } /* Fix 2nd, 3rd arg */ 
						; 

location				: 	ID 
							{ $$ = new location($1); }
						| 	ID SQUARE_OPEN expr SQUARE_CLOSE 
							{ $$ = new location($1); } /* Fix 2nd arg */
						; 

method_call_statment 	: 	method_call SEMI_COLON
						; 

if_statement 			: 	IF OPEN expr CLOSE code_block else_statement 
							{ $$ = new ifSt($5, $6); }
							/* Fix 1st arg */ 
						; 

else_statement			:  	/* Epsilon */ 
							{$$ = new elseSt(NULL); }
						| 	ELSE code_block
							{$$ = new elseSt($2); } // confirm this. 
						;

for_statement 			: 	FOR ID EQUAL expr COMMA expr code_block
							{ $$ = new forSt($2, $7); } 
						; 

return_statement 		: 	RETURN return_value SEMI_COLON
							{ $$ = new returnSt($2)}
						
						/* fix return val */ 
return_value			: 	/* Epsilon */ 
							{ $$ = new returnVal(); }
						| 	expr
							{ $$ = new returnVal(); }
						;

terminal_statement	 	: 	BREAK SEMI_COLON
							{ $$ = new terminalSt("break");}
						| 	CONTINUE SEMI_COLON
							{ $$ = new terminalSt("continue"); }
						; 


/* General Method Call */ 
method_call 			: 	ID OPEN method_call_args CLOSE 
						| 	CALLOUT OPEN string_literal CLOSE 
						| 	CALLOUT OPEN string_literal COMMA 						non_empty_callout_args CLOSE
						; 

method_call_args 		: 	/* Epsilon */ 
						| 	non_empty_method_call_args
						;

non_empty_method_call_args
						: 	method_call_arg 
						| 	non_empty_method_call_args COMMA method_call_arg
						;

method_call_arg 		: 	expr
						; 

non_empty_callout_args 	: 	callout_arg 
						| 	non_empty_callout_args COMMA callout_arg
						;

callout_arg 			: 	expr 
						| 	string_literal
						;

expr					: 	location  
						| 	method_call 
						| 	literal 
						| 	expr bin_op expr 
						| 	SUBTRACT expr 
						| 	NOT expr 
						| 	OPEN expr CLOSE 
						; 


/* All operations in the grammar */ 
assign_op				:	EQUAL 
						| 	PLUS_EQUAL 
						|	MINUS_EQUAL
						;

bin_op					: 	arith_op 
						| 	rel_op 
						| 	eq_op 
						| 	cond_op
						;

arith_op 				: 	ADD 
						| 	SUBTRACT 
						| 	MULTIPLY 
						| 	DIVIDE 
						| 	MODULO
						;

rel_op 					: 	GREATER 
						| 	LESS 
						| 	GREATER_EQUAL
						| 	LESS_EQUAL
						;

eq_op					: 	EQUALITY 
						| 	NOT_EQUAL
						; 

cond_op					: 	CONDITIONAL_AND 
						| 	CONDITIONAL_OR
						; 


/* All literals in the grammar */ 
literal 				: 	char_literal 
						| 	bool_literal 
						| 	int_literal
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
