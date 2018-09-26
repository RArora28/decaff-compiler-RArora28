%{
	#include <stdio.h>	
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
%token STRING 
%token ID 
%token ADD SUBTRACT MULTIPLY DIVIDE 
%token EQUAL PLUS_EQUAL MINUS_EQUAL EQUALITY 
%token NOT_EQUAL GREATER_EQUAL LESS_EQUAL GREATER LESS 
%token CONDITIONAL_AND CONDITIONAL_OR
%token NOT ABSOLUTE MODULO 
%token CURLY_OPEN CURLY_CLOSE 
%token SQUARE_OPEN SQUARE_CLOSE 
%token OPEN CLOSE 
%token SEMI_COLON COMMA 

%%

/* Outermost Match */ 
program_declaration: 
	CLASS PROGRAM CURLY_OPEN field_declarations method_declarations CURLY_CLOSE 
	; 
/* Data types in grammar */ 
var_type: 
	INT | BOOLEAN 
	; 

/* Field Declaration */ 
field_declarations: 
	| field_declarations field_declaration SEMI_COLON 
	; 
field_declaration: 
	var_type field_names 
	; 
field_names: 
	ID | ID SQUARE_OPEN SQUARE_CLOSE | field_names COMMA ID
	; 

/* Declaration for a method */ 
method_declarations: 
	| method_declarations method_declaration
	; 
method_declaration: 
	VOID ID OPEN parameter_declarations CLOSE code_block 
	| var_type ID OPEN parameter_declarations CLOSE code_block   
	; 
parameter_declarations: 
	| non_empty_parameter_declaration
	;
non_empty_parameter_declaration: 
	parameter_declaration | non_empty_parameter_declaration COMMA parameter_declaration 
	; 
parameter_declaration: 
	var_type ID 
	; 

/* Block of code inside a method */ 
code_block: 
	CURLY_OPEN block CURLY_CLOSE
	; 
block: 
	| var_declarations statements
	; 

/* Variable Declarations inside a code block */ 
var_declarations: 
	| var_declarations var_declaration SEMI_COLON 
	; 
var_declaration: 
	var_type var_names 
	; 
var_names: 
	ID | var_names COMMA ID
	; 

/* Set of statements in a code block */ 
statements: 
	| statement statements 
	; 
statement:
	location assign_op expr SEMI_COLON 
	/* | method_call SEMI_COLON */ 
	| IF OPEN expr CLOSE code_block possible_else 	
	| FOR ID EQUAL expr COMMA expr code_block 
	| RETURN return_value SEMI_COLON
	| BREAK SEMI_COLON
	| CONTINUE SEMI_COLON
	| code_block /* Redudant rule */ 
	; 
possible_else: 
	| ELSE code_block
	; 
return_value: 
	| expr
	; 

location: 
	ID | ID SQUARE_OPEN expr SQUARE_CLOSE 
	; 

method_call: 
	method_name OPEN method_call_args CLOSE 
	| CALLOUT OPEN string_literal callout_args CLOSE 
	; 
method_call_args: 
	| non_empty_method_call_args
	;
non_empty_call_args: 
	method_call_arg | non_empty_call_args COMMA method_call_arg
	; 
method_call_arg: 
	expr
	; 
callout_args: 
	expr
	| string_literal 
	;

expr: 
	  location  
	| method_call 
	| literal 
	| expr bin_op expr 
	| SUBTRACT expr 
	| NOT expr 
	| OPEN expr CLOSE 
	; 

/* All operations in the grammar */ 
assign_op: 
	EQUAL | PLUS_EQUAL | MINUS_EQUAL 
	; 
bin_op: 
	  arith_op 
	| rel_op 
	| eq_op 
	| cond_op 
	; 
arith_op: 
 	  ADD
 	| SUBTRACT
 	| MULTIPLY
 	| DIVIDE
 	| MODULO
 	; 
rel_op: 
	  GREATER
	| LESS
	| GREATER_EQUAL
	| LESS_EQUAL
	; 
eq_op: 
	  EQUALITY
	| NOT_EQUAL
	; 
cond_op: 
	  CONDITIONAL_AND
	| CONDITIONAL_OR
	; 

/* All literals in the grammar */ 
literal: 
	  int_literal 
	| bool_literal 
	; 
int_literal: 
	NUM
	; 
bool_literal: 
	  TRUE
	| FALSE
	; 
string_literal: 
	
%%

int main(int argc, char **argv) {
 	yyparse();
 	return 0; 
}

int yyerror(char *s) {
 	fprintf(stderr, "error: %s\n", s);
 	return 0;
}
