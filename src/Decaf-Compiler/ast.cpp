#include <bits/stdc++.h>
using namespace std; 

#include "ast.h"

program::program(class fieldDeclarations* fieldDecls_,
				 class methodDeclarations* methodDecls_) {
	fieldDecls = fieldDecls_;
	methodDecls = methodDecls_; 
}


varType::varType(const string& type_) {
	type = type_; 
}


fieldDeclarations::fieldDeclarations() {}
void fieldDeclarations::add(class fieldDeclaration* newFieldDecl) {
	list.push_back(newFieldDecl);
	return; 
}
// Single field Declaration of the type "int x, y, z;"
fieldDeclaration::fieldDeclaration(class varType* type_,
								   class fieldNames* fNames_) {
	type = type_;
	fNames = fNames_;
}

fieldNames::fieldNames() {}
void fieldNames::add(class field* field_) {
	fields.push_back(field_);
	return; 
}

field::field(const string& name_, class intLiteral* size_) {
	name = name_;  
	size = size_;
}

methodDeclarations::methodDeclarations() {}
void methodDeclarations::add(class methodDeclaration* methodDecl_) {
	list.push_back(methodDecl_);
	return; 
}
methodDeclaration::methodDeclaration(class varType* returnType_, 
					  const string& methodName_,
					  class parameterDeclarations* params_,
					  class codeBlock* code_) {
	returnType = returnType_; 
	methodName = methodName_; 
	params     = params_; 
	code 	   = code_; 
}
parameterDeclarations::parameterDeclarations(class nonEmptyParDecl* nonEmptyParams_) {
	nonEmptyParams = nonEmptyParams_; 
}
nonEmptyParDecl::nonEmptyParDecl() {} 
void nonEmptyParDecl::add(class parameterDeclaration* param_) {
	listParams.push_back(param_);
	return; 
}
parameterDeclaration::parameterDeclaration( class varType* type_,	
											const string& name_) {
	type = type_; 
	name = name_;
}


codeBlock::codeBlock(class block* bl_) {
	bl = bl_; 
}
block::block(varDeclarations* varDecls_, 
		  	 statements* stmts_) {
	varDecls = varDecls_; 
	stmts 	 = stmts_; 
}
varDeclarations::varDeclarations() {}
void varDeclarations::add(class varDeclaration* decl_) {
	list.push_back(decl_);
}
varDeclaration::varDeclaration(	class varType* type_, 
				  	 			class varNames* names_) {
	type 	= type_; 
	names 	= names_; 
}
varNames::varNames() {}
void varNames::add(const string& name_) {
	names.push_back(name_);
}

statements::statements() {} 
void statements::add(class statement* st_) {
	list.push_back(st_);
}

location::location(const string& name_,
				   class Expr* exp_) {
	name = name_;
	exp = exp_;
}
 
assignSt::assignSt(class location* loc_,
				   class assignOp* asOp_,
				   class Expr* exp_) {
	loc = loc_;
	asOp = asOp_; 
	exp = exp_;
}
 
ifSt::ifSt(	class Expr* condition_, 
		 	class codeBlock* code_, 
		 	class elseSt* eSt_) {
	condition = condition_;
	code = code_; 
	eSt = eSt_;
}

elseSt::elseSt(class codeBlock* bl_) {
	bl = bl_;
}

forSt::forSt(const string& var_,
			 class Expr* start_,
			 class Expr* end_,
		 	 class codeBlock* bl_) {
	var = var_; 
	start = start_; 
	end = end_;
	bl = bl_;
}
 
returnSt::returnSt(class returnVal* ret_) {
	ret = ret_; 
}
returnVal::returnVal(class Expr* ret_) {
	ret = ret_;
}

terminalSt::terminalSt(const string& name_) {
	name = name_;
}


methodCallSt::methodCallSt(class methodCall* call_) {
	call = call_; 
} 

normalCall::normalCall(class methodCallArgs* args_) {
	args = args_; 
}


methodCallArgs::methodCallArgs(class nonEmptyCallArgs* args_) {
	args = args_;
}
nonEmptyCallArgs::nonEmptyCallArgs() {}
void nonEmptyCallArgs::add(class Expr* exp) {
	list.push_back(exp);
}

calloutCall::calloutCall(class stringLiteral* callName_,
				class nonEmptyCalloutArgs* args_) {
	callName = callName_; 
	args = args_;
}

nonEmptyCalloutArgs::nonEmptyCalloutArgs() {}
void nonEmptyCalloutArgs::add(class calloutArg* arg_) {
	list.push_back(arg_);
}
 
calloutArg::calloutArg (class stringLiteral* argName_,
			   			class Expr* exp_) {
	argName = argName_; 
	exp = exp_;
}

unaryExpr::unaryExpr (const string& op_, 
					  class Expr* exp_) {
	op = op_; 
	exp = exp_; 
}

binExpr::binExpr (class Expr* exp1_,
				  const string& op_,
				  class Expr* exp2_) {
	exp1 = exp1_; 
	op = op_;
	exp2 = exp2_; 
}
enclosedExpr::enclosedExpr(class Expr* exp_) {
	exp = exp_; 
}

assignOp::assignOp(const string& op_) {
	op = op_;
}

intLiteral::intLiteral(int value_) {
	value = value_;
}
boolLiteral::boolLiteral(bool value_) {
	value = value_;
}
charLiteral::charLiteral(char* value_) {
	value = strdup(value_);
}
stringLiteral::stringLiteral(char* value_) {
	value = strdup(value_);
}



