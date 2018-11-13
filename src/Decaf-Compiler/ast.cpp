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

vector < map < string, string > > currVars;  
map < string, pair < string, int > > globalFields; // name: [type, size]
map < string, vector < pair < string, string > > > methodArgs;
map < string, string > returnType;   
string currType, currMethodName; 

void printDetails() {
	// for(auto x: globalFields) {
	// 	cout << x.first << ":" << x.second.first << " " << x.second.second << endl;
	// }
	// for(auto x: returnType) {
	// 	cout << x.first << ": " << x.second << endl;
	// }
	for(auto x: methodArgs) {
		cout << x.first << ": "; 
		for(auto t: x.second) {
			cout << t.first << "-" << t.second << " ";
		}
		cout << endl;
	}
	
}
// Code for Visitor class 
int Visitor::visit(program* p) {
	if (p) {
		visit(p->fieldDecls);
		visit(p->methodDecls);
	}
	printDetails(); 
	return 0;
}
int Visitor::visit(fieldDeclarations* f) {
	if (f) {
		for(auto x: f->list) {
			visit(x); 
		}
	}
	return 0;
}

int Visitor::visit(fieldDeclaration* f) {
	if (f) {
		visit(f->type);
		visit(f->fNames); 
	}
	return 0;
}
int Visitor::visit(varType* v) {
	if (v) {
		currType = v->type; 
	}
	return 0;
}
int Visitor::visit(fieldNames* f) {
	if (f) {
		for(auto x: f->fields) {
			visit(x); 
		}
	}
	return 0; 
}
int Visitor::visit(field* f) {
	if (f) {
		globalFields[f->name] = {currType, f->size ? f->size->value: -1}; 
	}
	return 0;
}

int Visitor::visit(methodDeclarations* m) {
	if (m) {
		for(auto x: m->list) {
			visit(x);
		}
	}
	return 0;
} 
int Visitor::visit(methodDeclaration* m) {
	if (m) {
		visit(m->returnType); 
		currMethodName = m->methodName;
		returnType[currMethodName] = currType;   
		visit(m->params); 
		visit(m->code);
	}
	return 0;
} 
int Visitor::visit(parameterDeclarations* p) {
	if (p) {
		visit(p->nonEmptyParams); 
	}
	return 0;
} 

int Visitor::visit(nonEmptyParDecl* n) {
	if (n) {
		for(auto x: n->listParams) {
			visit(x); 
		}
	}
	return 0;
} 

int Visitor::visit(parameterDeclaration* p) {
	if (p) {
		visit(p->type);
		methodArgs[currMethodName].push_back({p->name, currType});  
	}
	return 0;
} 

int Visitor::visit(codeBlock* c) {
	if (c) {
		visit(c->bl);
	}
	return 0;
} 
int Visitor::visit(block* b) {
	if (b) {
		visit(b->varDecls);
		visit(b->stmts);
	}
	return 0;
} 

int Visitor::visit(varDeclarations* v) {
	if (v) {
		for(auto x: v->list) { 
			visit(x);
		}
	}
	return 0;
}
int Visitor::visit(varDeclaration* v) {
	if (v) {
		visit(v->type); 
		visit(v->names);
	}
	return 0;
}
int Visitor::visit(varNames* v) {
	if (v) {

	}
	return 0;
}

int Visitor::visit(statements* st) {
	if (st) {
		for(auto x: st->list) {
			visit(x); 
		}
	}
	return 0;
}
int Visitor::visit(statement* st) {
	if (st) {

	}
	// do something with the label if you want to? 
	return 0;
}
int Visitor::visit(assignSt* aSt) {
	if (aSt) {
		visit(aSt->loc); 
		visit(aSt->asOp); 
		visit(aSt->exp); 
	}
	return 0;
}
int Visitor::visit(ifSt* iSt) {
	if (iSt) {
		visit(iSt->condition);
		visit(iSt->code);
		visit(iSt->eSt);
	}
	return 0;
}
int Visitor::visit(elseSt* eSt) {
	if (eSt) {
		visit(eSt->bl);
	}
	return 0;
}
int Visitor::visit(forSt* fSt) {
	if (fSt) {
		// do something with the looping var
		visit(fSt->start);
		visit(fSt->end); 
		visit(fSt->bl); 
	}
	return 0;
}
int Visitor::visit(returnSt* rSt) {
	if (rSt) {
		visit(rSt->ret);
	}
	return 0;
}
int Visitor::visit(returnVal* rVal) {
	if (rVal) {
		visit(rVal->ret);
	}
	return 0;
}
int Visitor::visit(terminalSt* tSt) {
	if (tSt) {
		// do something with the name 
	}
	return 0;
}
int Visitor::visit(location* loc) {
	if (loc) {
		// do something with the name 
		visit(loc->exp);
	}
	return 0;
}

int Visitor::visit(methodCallSt* mSt) {
	if (mSt) {
		visit(mSt->call);
	}
	return 0;
}
int Visitor::visit(methodCall* mC) {
	if (mC) {
		// empty class 
	}
	return 0;
}
int Visitor::visit(normalCall* nC) {
	if (nC) {
		visit(nC->args);
	}
	return 0;
}
int Visitor::visit(methodCallArgs* m) {
	if (m) {
		// empty class 
	}
	return 0;
}
int Visitor::visit(nonEmptyCallArgs* n) {
	if (n) {
		for(auto x: n->list) {
			visit(x);
		}
	}
	return 0;
}
int Visitor::visit(calloutCall* c) {
	if (c) {
		visit(c->callName);
		visit(c->args);
	}
	return 0;
}
int Visitor::visit(nonEmptyCalloutArgs* n) {
	if (n) {
		for(auto x: n->list) {
			visit(x);
		}
	}
	return 0;
}
int Visitor::visit(calloutArg* c) {
	if (c) {
		visit(c->argName); 
		visit(c->exp);
	}
	return 0;
}

int Visitor::visit(Expr* e) {
	if (e) {
		// empty class 
	}
	return 0;
}
int Visitor::visit(binExpr* b) {
	if (b) {
		visit(b->exp1); 
		// do something with the op
		visit(b->exp2);
	}
	return 0;
}
int Visitor::visit(unaryExpr* u) {
	if (u) {
		// do something with the op
		visit(u->exp);
	}
	return 0;
}
int Visitor::visit(enclosedExpr* e) {
	if (e) {
		visit(e->exp);
	}
	return 0;
}
int Visitor::visit(assignOp* aOp) {
	if (aOp) {
		// do something with the assign op; 
	}
	return 0;
}

int Visitor::visit(intLiteral* i) {
	if (i) {}
	return 0; 
} 
int Visitor::visit(boolLiteral* b) {
	if (b) {}
	return 0;
} 
int Visitor::visit(charLiteral* c) {
	if (c) {}
	return 0;
} 
int Visitor::visit(stringLiteral* s) {
	if (s) {}
	return 0;
} 