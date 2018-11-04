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
	class block* Bl; 

	class varDeclarations* varDecls; 
	class varDeclaration* varDecl; 
	class varNames* varN; 

	class statements* stmts;
	class statement* stmt; 
	class assignSt* Assign; 
	class ifSt* If; 
	class elseSt* Else; 
	class forSt* For; 
	class returnSt* Return; 
	class returnVal* retVal; 
	class terminalSt* ter; 
	class location* loc; 	

	class methodCallSt* mCSt; 
	class methodCall* mC; 
	class normalCall* nC; 
	class methodCallArgs* mCArgs; 
	class nonEmptyCallArgs* nECArgs; 
	
	class calloutCall* cC; 
	class nonEmptyCalloutArgs* nECalloutArgs; 
	class calloutArg* cArgs; 

	class Expr* Exp; 
	class binExpr* binExp; 
	class unaryExpr* unExp; 
	class enclosedExpr* enExp; 

	class assignOp* asOp; 

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

class codeBlock: public statement {
public: 
	class block* bl; 
	codeBlock(class block* bl_); 
}; 
class block: public baseAstNode {
public:
	class varDeclarations* varDecls; 
	class statements* stmts;  
	block(class varDeclarations* varDecls_, 
		  class statements* stmts_); 
}; 

class varDeclarations: public baseAstNode {
public: 
	vector <class varDeclaration*> list; 
	varDeclarations(); 
	void add(class varDeclaration* decl_); 
}; 
class varDeclaration: public baseAstNode {
public:
	class varType* type; 
	class varNames* names; 
	varDeclaration(class varType* type_, 
				   class varNames* names_); 
};
class varNames: public baseAstNode {
public:
	vector < string > names; 
	varNames(); 
	void add(const string& name_); 
};


class statements: public baseAstNode {
public: 
	vector <class statement*> list; 
	statements(); 
	void add(class statement* st_); 
}; 

class statement: public baseAstNode {
public:
	string label; 
}; 


class Expr: public baseAstNode {	
}; 

class location: public Expr {
public: 
	string name; 
	class Expr* exp;
	location(const string& name_,
			 class Expr* exp_); 
};

class assignSt: public statement {
public:
	class location* loc; 
	class assignOp* asOp; 
	class Expr* exp; 
	assignSt(class location* loc_,
			 class assignOp* asOp_,
			 class Expr* exp_);
};

class ifSt: public statement {
public:
	class Expr* condition;
	class codeBlock* code;  
	class elseSt* eSt; 
	ifSt(class Expr* condition_, 
		 class codeBlock* code_, 
		 class elseSt* eSt_); 
}; 
class elseSt: public baseAstNode {
public: 
	class codeBlock* bl; 
	elseSt(class codeBlock* bl_);
}; 

class forSt: public statement {
public:
	string var; 
	class Expr* start; 
	class Expr* end; 
	class codeBlock* bl;
	forSt(const string& var_,
		  class Expr* start_, 
		  class Expr* end_, 
		  class codeBlock* bl_); 
}; 

class returnSt: public statement {
public:
	class returnVal* ret; 
	returnSt(class returnVal* ret_); 
};
class terminalSt: public statement {
public:
	string name; 
	terminalSt(const string& name_); 
}; 

class returnVal: public baseAstNode {
public:
	class Expr* ret; 
	returnVal(class Expr* ret_);
};

class methodCallSt: public statement {
public:
	class methodCall* call; 
	methodCallSt(class methodCall* call_); 
}; 
class methodCall: public Expr {

}; 

class normalCall: public methodCall {
public:
	class methodCallArgs* args; 
	normalCall(class methodCallArgs* args_); 
}; 

class methodCallArgs: public baseAstNode {
};
class nonEmptyCallArgs: public methodCallArgs {
public:
	vector < class Expr* > list; 
	nonEmptyCallArgs();
	void add(class Expr* exp);
}; 

class calloutCall: public methodCall {
public:
	class stringLiteral *callName; 
	class nonEmptyCalloutArgs* args; 
	calloutCall(class stringLiteral* callName_,
				class nonEmptyCalloutArgs* args_); 
}; 

class nonEmptyCalloutArgs: public baseAstNode {
public:
	vector < class calloutArg* > list;  
	nonEmptyCalloutArgs();
	void add(class calloutArg* arg_);
}; 

class calloutArg: public baseAstNode {
public:
	class stringLiteral* argName; 
	class Expr* exp; 
	calloutArg(class stringLiteral* argName_,
			   class Expr* exp_); 
}; 

class unaryExpr: public Expr {
public:
	string op; 
	class Expr* exp; 
	unaryExpr(const string& op_, 
			  class Expr* exp);
}; 

class binExpr: public Expr {
public:
	class Expr* exp1; 
	string op; 
	class Expr* exp2; 
	binExpr(class Expr* exp1_,
			const string& op_, 
			class Expr* exp2_); 
}; 

class enclosedExpr: public Expr {
public:
	class Expr* exp; 
	enclosedExpr(class Expr* exp_); 
}; 
	
class assignOp: public baseAstNode {
public:
	string op; 
	assignOp(const string& op_); 
};

class intLiteral: public Expr {
public:
	int value; 
	intLiteral(int value_); 
};
class boolLiteral: public Expr {
public:
	bool value; 
	boolLiteral(bool value_); 
};
class charLiteral: public Expr {
public:
	char* value; 
	charLiteral(char* value_); 
};
class stringLiteral: public baseAstNode {
public:
	char* value; 
	stringLiteral(char* value_); 
};
