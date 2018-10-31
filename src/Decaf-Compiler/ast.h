#include <bits/stdc++.h>
using namespace std; 

union Node {
	int num; 
	char *lit; 
	class program* prog; 
	class fieldDeclarations* fieldDecls; 
	class fieldDeclaration* field
}; 

typedef union Node YYSTYPE; 
#define YYSTYPE_IS_DECLARED 1 

class baseAstNode {
}; 

class program: public baseAstNode {
public:
	class fieldDeclarations* fieldDecl; 
	program(class fieldDeclarations* fieldDecl_);
};

class fieldDeclarations: public baseAstNode {
public: 
	vector <class fieldDeclaration* > list; 
	fieldDeclarations(); 
	void add(class fieldDeclaration* newFieldDecl); 
}; 

class fieldDeclaration: public baseAstNode {
public:
	class *varType type; 
	vector < class *fieldName > list; 
	fieldDeclaration(class varType* type_);
	add(class *fieldName field);  
}

class varType: public baseAstNode {
public: 
	string type;  
	varType(const string& type_); 
}

class fieldName: public baseAstNode {
public:
	string name; 
	int arraySize; 
	fieldName(const string& name_, int arraySize_ = -1); 
}
