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

program_declaration: 
	CLASS PROGRAM CURLY_OPEN field_declarations method_declarations CURLY_CLOSE 
	; 

return_type: 
	VOID | var_type
	; 

var_type: 
	INT | BOOLEAN 
	; 

field_declarations: 
	| field_declarations field_declaration SEMI_COLON 
	; 

field_declaration: 
	var_type field_names 
	; 

field_names: 
	ID | ID SQUARE_OPEN SQUARE_CLOSE | field_names COMMA ID
	; 

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

code_block: 
	CURLY_OPEN var_declarations statements CURLY_CLOSE 
	{ printf("code block ke andar ghusa\n"); }
	; 

var_declarations: 
	| var_declaration | var_declarations var_declaration 
	;

var_declaration: 
	var_type ID SEMI_COLON
	; 

statements: 
	| location assign_op expr SEMI_COLON 
	{ printf("statement ke andar ghusa\n"); }
	; 

assign_op: 
	EQUAL | PLUS_EQUAL | MINUS_EQUAL 
	; 

location: 
	ID | ID SQUARE_OPEN expr SQUARE_CLOSE 
	; 

method_call: 
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

literal: 
	  int_literal 
	/*| char_literal */ 
	| bool_literal 
	; 

int_literal: NUM; 

bool_literal: 
	  TRUE
	| FALSE
	; 

%%
int main(int argc, char **argv) {
 	yyparse();
 	return 0; 
}

int yyerror(char *s) {
 	fprintf(stderr, "error: %s\n", s);
 	return 0;
}
