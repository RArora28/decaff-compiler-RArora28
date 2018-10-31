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
%token TRUE FALSE 
%token BREAK CONTINUE RETURN 
%token FOR 
%token IF ELSE 
%token NUM
%token HEX_LITERAL
%token CHAR_LITERAL
%token STRING 
%token <lit> 	ID
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
%type <fieldDecls> 		field_declarations; 
%type <fieldDecl> 		field_declaration; 
%type <vType> 			var_type; 
%type <fieldN> 			field_names; 
%type <singleField> 	field_name;		
%%

/* Outermost Match */ 
program_declaration		: 	CLASS PROGRAM CURLY_OPEN field_declarations 									method_declarations CURLY_CLOSE
							{ $$ = new program($4); }

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
							{ 
								$$->add($3); 
							}
						
						;

field_name 				: 	ID 
						  	{ $$ = new field($1); }
						| 	ID SQUARE_OPEN literal SQUARE_CLOSE
							{ $$ = new field($1); }
						; 

/* Declaration for a method */ 
method_declarations		: 	/* Epsilon */
						| 	method_declaration method_declarations
						; 

method_declaration 		: 	VOID ID OPEN parameter_declarations CLOSE code_block 
						| 	var_type ID OPEN parameter_declarations CLOSE 			code_block   
						; 

parameter_declarations	: 	/* Epsilon */ 
						| 	non_empty_parameter_declaration
						;

non_empty_parameter_declaration
						: 	parameter_declaration 
						| 	parameter_declaration COMMA 							non_empty_parameter_declaration 
						; 

parameter_declaration 	: 	var_type ID
						; 


/* Block of code inside a method */ 
code_block				: 	CURLY_OPEN block CURLY_CLOSE
						; 

block 					: 	/* Epsilon */ 
						| 	var_declarations statements
						; 


/* Variable Declarations inside a code block */ 
var_declarations		:  	/* Epsilon */ 
						| 	var_declarations var_declaration SEMI_COLON 
						;

var_declaration 		: 	var_type var_names 
						;

var_names				: 	ID 
						| 	ID COMMA var_names 
						; 


/* Set of statements in a code block */ 
statements				: 	/* Epsilon */
						| 	statement statements
						; 

statement 				:	location assign_op expr SEMI_COLON 
						| 	method_call SEMI_COLON  
						| 	IF OPEN expr CLOSE code_block possible_else 	
						| 	FOR ID EQUAL expr COMMA expr code_block 
						| 	RETURN return_value SEMI_COLON
						| 	BREAK SEMI_COLON
						| 	CONTINUE SEMI_COLON
						| 	code_block /* Redudant rule */ 
						; 

possible_else			:  	/* Epsilon */ 
						| 	ELSE code_block
						;

return_value			: 	/* Epsilon */ 
						| 	expr
						;

location				: 	ID 
						| 	ID SQUARE_OPEN expr SQUARE_CLOSE 
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

char_literal 			: 	CHAR_LITERAL;

int_literal 			: 	NUM 
						| 	HEX_LITERAL
						;

bool_literal 			:	TRUE 
						| 	FALSE
						;

string_literal 			: 	STRING
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
