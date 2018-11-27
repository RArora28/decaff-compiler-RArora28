#include <bits/stdc++.h>
#include "decafExceptions.cpp"
using namespace std; 

#include "ast.h"

#define TRACE 
#ifdef  TRACE
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
	template <typename Arg1>
	void __f(const char* name, Arg1&& arg1){
		cerr << name << " : " << arg1 << endl;
	}
	template <typename Arg1, typename... Args>
	void __f(const char* names, Arg1&& arg1, Args&&... args){
		const char* comma = strchr(names + 1, ','); 
		cerr.write(names, comma - names) << " : " << arg1 << " | ";
		__f(comma + 1, args...);
	}
#else
#define trace(...)
#endif

vector < map < string, string > > Vars;
map < string, string > currVars;
map < string, string > currMethodArgs;    
map < string, pair < string, int > > globalFields; // name: [type, size]
map < string, vector < pair < string, string > > > methodArgs;
map < string, string > returnType;   
vector < string > arith_op 	= {"+", "-", "*", "/", "%"}; 
vector < string > rel_op 	= {"<", ">", "<=", ">="}; 
vector < string > cond_op 	= {"&&", "||"};
vector < string > eq_op  	= {"==", "!="}; 
string currType, currMethodName, currVarName; 
bool Main = false, inFor = false; 

void printDetails() {
	// for(auto x: globalFields) {
	// 	cout << x.first << ":" << x.second.first << " " << x.second.second << endl;
	// }
	// for(auto x: returnType) {
	// 	cout << x.first << ": " << x.second << endl;
	// }
	// for(auto x: methodArgs) {
	// 	cout << x.first << ": "; 
	// 	for(auto t: x.second) {
	// 		cout << t.first << "-" << t.second << " ";
	// 	}
	// 	cout << endl;
	// }
	// cout << Vars.size() << endl;
	// for(auto t: Vars) {
	// 	for(auto x: t) {
	// 		cout << x.first << ": " << x.second << endl;
	// 	}
	// }
}

// Code for Visitor class 
int Visitor::visit(program* p) {
	if (p) {
		visit(p->fieldDecls);
		visit(p->methodDecls);
		if (!Main) {
			cout << "Compilation terminated due to absence of main function." << endl; 
			exit(0); 
		} 
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
		if (globalFields.count(f->name)) {
			cout << "Compilation terminated due to repeated variable declaration in the same scope." << endl; 
			exit(0);
		} else if (f->size && f->size->value <= 0) {
			cout << "Compilation terminated as non-positive array size is not allowed." << endl; 
			exit(0); 
		}
		globalFields[f->name] = {currType, f->size ? f->size->value: -1}; 
	}
	return 0;
}

int Visitor::visit(methodDeclarations* m) {
	if (m) {
		for(auto x: m->list) {
			currMethodArgs.clear(); 
			visit(x);
		}
	}
	return 0;
} 
int Visitor::visit(methodDeclaration* m) {
	if (m) {
		if (Main || m->methodName == "main") {
			visit(m->returnType); 
			currMethodName = m->methodName;
			returnType[currMethodName] = currType;
			if (currMethodName == "main") {
				Main = true; 
				if (m->params) {
					cout << "Compilation terminated as method arguments are not allowed in the main function." << endl; 
					exit(0); 
				}
			}  
			methodArgs[currMethodName];
			visit(m->params); 
			visit(m->code);
		}
	}
	return 0;
} 
int Visitor::visit(parameterDeclarations* p) {
	if (p) {
		for(auto x: p->listParams) {
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
		currVars.clear(); 
		if (inFor) {
			currVars[currVarName] = currType;
		}
		visit(c->bl);
		if (currVars.size()) Vars.pop_back();
	}
	return 0;
} 
int Visitor::visit(block* b) {
	if (b) {
		visit(b->varDecls);
		if (currVars.size()) {
			Vars.push_back(currVars);
		}
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
		for(auto x: v->names) {
			if (currVars.count(x)) {
				cout << "Compilation terminated due to repeated variable declaration in the same scope." << endl; 
				exit(0); 
			}
			currVars[x] = currType; 
		}
	}
	return 0;
}

int Visitor::visit(statements* st) {
	if (st) {
		for(auto x: st->list) {
			x->accept(this); 
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
		aSt->exp->accept(this);
		visit(aSt->asOp); 
		visit(aSt->loc); 
		string op = aSt->asOp->op; 
		if (op == "=") {
			if (aSt->exp->type != aSt->loc->type) {
				cout << "Invalid = statement." << endl;
				exit(0); 
			}
		} else {
			if (aSt->exp->type != "int" || aSt->loc->type != "int") {
				cout << "Invalid " << op << " statement."<< endl; 
				exit(0);
			}
		}
	}
	return 0;
}
int Visitor::visit(ifSt* iSt) {
	if (iSt) {
		iSt->condition->accept(this); 
		if (iSt->condition->type != "boolean") {
			cout << "Compilation terminated due to invalid type of condition in if statment." << endl; 
			exit(0); 
		}
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
		inFor = true;  
		currVarName = fSt->var; 
		currType = "int"; 
		visit(fSt->bl);
		inFor = false;  
	}
	return 0;
}
int Visitor::visit(returnSt* rSt) {
	if (rSt) {
		visit(rSt->ret);
	}
	return 0;
}

int Visitor::visit(terminalSt* tSt) {
	if (tSt) {
		//tSt->name is either break / continue 
		if (!inFor) {
			auto error_msg = (tSt->name == "break") ?  
			"Compilation terminated as break statement should be within a for loop.": 
			"Compilation terminated as continue statement should be within a for loop."; 
			cout << error_msg << endl; 
			exit(0); 
		}
	}
	return 0;
}
int Visitor::visit(location* loc) {
	if (loc) {
		auto name = loc->name; 
		if (loc->exp) {
			if (!globalFields.count(name) ||
				globalFields.count(name) && globalFields[name].second == -1) {
					cout << "Compilation terminated due to use of an undeclared array." << endl;
					exit(0); 
			}
			loc->exp->accept(this); 
			if (loc->exp->type != "int") {
				cout << "Compilation terminated due to use of an invalid array subscript." << endl;
				exit(0); 
			}
			return 0; 
		}
		for(int i = Vars.size() - 1; i >= 0; --i) {
			if (Vars[i].count(name)) {
				loc->type = Vars[i][name];
				return 0; 
			}
		}
		if (globalFields.count(name) && globalFields[name].second == -1) {
			loc->type = globalFields[name].first;
			return 0;
		}
		cout << "Compilation terminated due to use of an undeclared variable." << endl; 
		exit(0);  
	} 
	return 0;
}

int Visitor::visit(methodCallSt* mSt) {
	if (mSt) {
		// do something if you want. 
	}
	return 0;
}

int Visitor::visit(methodCall* mC) {
	if (mC) {
		visit(mC->args);
	}
	return 0;
}

int Visitor::visit(methodCallArgs* m) {
	if (m) {
		for(auto x: m->list) {
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
int Visitor::visit(CalloutArgs* n) {
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

// vector < string > arith_op 	= {"+", "-", "*", "/", "%"}; 
// vector < string > rel_op 	= {"<", ">", "<=", ">="}; 
// vector < string > cond_op 	= {"&&", "||"};
// vector < string > eq_op  	= {"==", "!="}; 


int Visitor::visit(binExpr* b) {
	if (b) {
		b->exp1->accept(this);
		b->exp2->accept(this);
		string op = b->op;
		
		if (find(arith_op.begin(), arith_op.end(), op) != arith_op.end()) {
	    	if (b->exp1->type != "int" || b->exp2->type != "int") {
	    		cout << "Invalid type error" << endl; 
	    		exit(0); 
	    	}
	    	b->type = "int"; 
	    	return 0;
	    }

	    if (find(rel_op.begin(), rel_op.end(), op) != cond_op.end()) {
	    	if (b->exp1->type != "int" || b->exp2->type != "int") {
				cout << "Invalid type error" << endl; 
	    		exit(0); 
	    	}
	    	b->type = "boolean"; 
	    	return 0;
	    }

	    if (find(cond_op.begin(), cond_op.end(), op) != rel_op.end()) {
	    	if (b->exp1->type != "boolean" || b->exp2->type  != "boolean") {
				cout << "Invalid type error" << endl; 
	    		exit(0); 
	    	}
	    	b->type = "boolean"; 
	    	return 0;
		}

		if (find(eq_op.begin(), eq_op.end(), op) != eq_op.end()) {
			if (b->exp1->type != b->exp2->type) {
				cout << "Invalid type error" << endl; 
	    		exit(0); 
			}
			b->type = "boolean"; 
			return 0;
		}
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
	if (i) {
		i->type = "int";
	}
	return 0; 
} 
int Visitor::visit(boolLiteral* b) {
	if (b) {
		b->type = "boolean";
	}
	return 0;
} 
int Visitor::visit(charLiteral* c) {
	if (c) {
		c->type = "char"; 
	}
	return 0;
} 
int Visitor::visit(stringLiteral* s) {
	if (s) {
		s->type = "string";
	}
	return 0;
} 