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
	cout << "# methods: " << list.size() << endl;
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
	cout << "methodName: " << methodName << endl;
}
parameterDeclarations::parameterDeclarations(class nonEmptyParDecl* nonEmptyParams_) {
	nonEmptyParams = nonEmptyParams_; 
}
nonEmptyParDecl::nonEmptyParDecl() {} 
void nonEmptyParDecl::add(class parameterDeclaration* param_) {
	listParams.push_back(param_);
	cout << "#params: " << listParams.size() << endl; 
	return; 
}
parameterDeclaration::parameterDeclaration( class varType* type_,	
											const string& name_) {
	type = type_; 
	name = name_;
	cout << "type: " << type->type << ' ' << "name: " << name_ << endl;
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
	cout << type->type << endl; 
}
varNames::varNames() {}
void varNames::add(const string& name_) {
	names.push_back(name_);
	cout << name_ << endl; 
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



