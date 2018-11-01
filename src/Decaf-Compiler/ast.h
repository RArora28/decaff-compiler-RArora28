#include <bits/stdc++.h>
using namespace std; 

union Node {
	
	int intLit; 
	bool boolLit; 
	char* strLit; 
	char *keyword; 
	
	class program* prog; 
	
	class fieldDeclarations* fieldDecls; 
	class fieldDeclaration* fieldDecl;
	class fieldNames* fieldN; 
	class field* singleField;
	
	class varType* vType; 
	
	class methodDeclarations* meDecls; 
	class methodDeclaration* meDecl; 
	class parameterDeclarations* parDecls; 
	class nonEmptyParDecl* nonEmpParDecl; 
	class parameterDeclaration* parDecl; 
	
	class codeBlock* codeBl; 

	class intLiteral*  integerLit; 
	class boolLiteral* booleanLit; 
	class charLiteral*  characterLit; 
	class stringLiteral*  stringLit; 
}; 

typedef union Node YYSTYPE; 
#define YYSTYPE_IS_DECLARED 1 

class baseAstNode { 
}; 

class program: public baseAstNode {
public:
	class fieldDeclarations* fieldDecls; 
	class methodDeclarations* methodDecls; 
	program(class fieldDeclarations* fieldDecls_, 
			class methodDeclarations* methodDecls_);
};

class varType: public baseAstNode {
public: 
	string type;  
	varType(const string& type_); 
}; 

class fieldDeclarations: public baseAstNode {
public: 
	vector <class fieldDeclaration* > list; 
	fieldDeclarations(); 
	void add(class fieldDeclaration* newFieldDecl); 
}; 

class fieldDeclaration: public baseAstNode {
public:
	class varType* type; 
	class fieldNames* fNames;  
	fieldDeclaration(class varType* type_, 
					 class fieldNames* fNames_);
}; 

class fieldNames: public baseAstNode {
public: 
	vector <class field*> fields; 
	fieldNames(); 
	void add(class field* field_); 
};

class field: public baseAstNode {
public:
	string name; 
	class intLiteral* size;  
	field(const string& name_, 
		  class intLiteral* size_); 
}; 



class methodDeclarations: public baseAstNode {
public:
	vector < class methodDeclaration*> list; 
	methodDeclarations(); 
	void add(class methodDeclaration* methodDecl_); 
}; 
class methodDeclaration: public baseAstNode {
public:
	class varType* returnType; 
	string methodName; 
	class parameterDeclarations* params; 
	class codeBlock* code; 
	methodDeclaration(class varType* returnType_, 
					  const string& methodName_,
					  class parameterDeclarations* params_,
					  class codeBlock* code_); 
}; 
class parameterDeclarations: public baseAstNode {
public: 
	class nonEmptyParDecl* nonEmptyParams; 
	parameterDeclarations(class nonEmptyParDecl* nonEmptyParams_); 
}; 
class nonEmptyParDecl: public baseAstNode {
public:
	vector <class parameterDeclaration*> listParams; 
	nonEmptyParDecl(); 
	void add(class parameterDeclaration* param_);
}; 
class parameterDeclaration: public baseAstNode {
public:
	class varType* type; 
	string name; 
	parameterDeclaration(class varType* type_,
			  const string& name_);
}; 
class codeBlock: public baseAstNode {
public: 
	codeBlock(); 
}; 


class intLiteral: public baseAstNode {
public:
	int value; 
	intLiteral(int value_); 
};
class boolLiteral: public baseAstNode {
public:
	bool value; 
	boolLiteral(bool value_); 
};
class charLiteral: public baseAstNode {
public:
	char* value; 
	charLiteral(char* value_); 
};
class stringLiteral: public baseAstNode {
public:
	char* value; 
	stringLiteral(char* value_); 
};
