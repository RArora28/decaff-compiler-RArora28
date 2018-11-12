#include <bits/stdc++.h>
using namespace std; 

class A {
public:
	void hello() {
		cout << "hi" << endl;
	}
}; 

class B: public A {
public:
	void hello() {
		cout << "hello" << endl;
	}
}; 

class visitor {
public:
	void visit(class A* a) {
		a->hello();
	}
	void visit(class B* b) {

	}
}; 

int main() {
	A* a; 
	B* b = new B();
	a = b;
	visitor v; 	
	v.visit(a);
	char *t = "rishabh"; 
	char *u = "hot";
	if (*t == *u) {
		cout << "hello" << endl;
	}
	return 0;
}