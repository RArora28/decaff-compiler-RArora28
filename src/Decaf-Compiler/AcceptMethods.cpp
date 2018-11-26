#include <bits/stdc++.h>
using namespace std; 

#include "ast.h"


int statement::accept(Visitor *v) {
	return v->visit(this);
}
int assignSt::accept(Visitor *v) {
	return v->visit(this);
}
int ifSt::accept(Visitor *v) {
	return v->visit(this);
}
int elseSt::accept(Visitor *v) {
	return v->visit(this); 
}
int forSt::accept(Visitor *v) {
	return v->visit(this);
}
int terminalSt::accept(Visitor* v) {
	return v->visit(this);
}
int Expr::accept(Visitor *v) {
	return v->visit(this); 
}
int binExpr::accept(Visitor *v) {
	return v->visit(this); 
}
int location::accept(Visitor *v) {
	return v->visit(this);
}