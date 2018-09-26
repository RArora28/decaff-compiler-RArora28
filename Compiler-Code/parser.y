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
%token NORMAL_OPEN NORMAL_CLOSE 
%token SEMI_COLON COMMA 

%%

program_declaration: 
	CLASS ID CURLY_OPEN field_declarations method_declarations CURLY_CLOSE 
	; 

return_type: 
	VOID | INT | BOOLEAN 
	; 

var_type: 
	INT | BOOLEAN 

field_declarations: 
	| field_declaration SEMI_COLON field_declarations 
	; 

field_declaration: 
	var_type field_names
	; 

field_names: 
	ID | ID SQUARE_OPEN SQUARE_CLOSE | field_names COMMA ID
	; 

method_declarations: 
	| method_declaration method_declarations
	; 

method_declaration: 
	return_type ID NORMAL_OPEN parameter_declarations NORMAL_CLOSE
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

%%
int main(int argc, char **argv) {
 	yyparse();
 	printf("Code compiled successfully\n"); 
 	return 0; 
}

int yyerror(char *s) {
 	fprintf(stderr, "error: %s\n", s);
 	return 0;
}
