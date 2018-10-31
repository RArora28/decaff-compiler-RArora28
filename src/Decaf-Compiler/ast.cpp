#include <bits/stdc++.h>
using namespace std; 

#include "ast.h"

program::program(class fieldDeclarations* fieldDecl_) {
	fieldDecl = fieldDecl_;
}

fieldDeclarations::fieldDeclarations() {}
void fieldDeclarations::add(class fieldDeclaration* newFieldDecl) {
	list.push_back(newFieldDecl);
}

fieldDeclaration::fieldDeclaration(class varType* type_) {
	type = type_;
}
void add(class fieldName* field) {
	list.push_back(field);
}

varType::varType(const string& type_) {
	type = type_; 
}

fieldName::fieldName(const string& name_, int arraySize_) {
	name = name_; 
	arraySize = arraySize_;
}