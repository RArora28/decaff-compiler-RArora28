#include <bits/stdc++.h>
using namespace std; 

#include "ast.h"

program::program(class fieldDeclarations* fieldDecls_) {
	fieldDecls = fieldDecls_;
}

varType::varType(const string& type_) {
	type = type_; 
}

fieldDeclarations::fieldDeclarations() {}
void fieldDeclarations::add(class fieldDeclaration* newFieldDecl) {
	list.push_back(newFieldDecl);
	cout << "field Declaration ka size bad ke hogya hai: " << list.size() << endl;
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
	// cout << "fields ka size bad ke hogya hai: " << fields.size() << endl;
	return; 
}

field::field(string name_) {
	name = name_; 
}