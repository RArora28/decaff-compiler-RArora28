#include "ast.h"

using namespace std; 
using namespace llvm; 

static LLVMContext Context;
static Module *TheModule = new Module("Compiler for decaf", Context);
static IRBuilder<> Builder(Context);
static std::map<std::string, AllocaInst *> NamedValues;

void program::generateCode() {
    TheModule->print(llvm::outs(), nullptr);
}

Value* program::codegen() {
	Value *V; 
	V = fieldDecls->codegen();
    if (V == nullptr) {
        cout << "Invalid Field Declarations" << endl; 
        return nullptr;
	}
	V = methodDecls->codegen(); 
	if (V == nullptr) {
		cout << "Invalid Method Declarations" << endl; 
		return nullptr; 
	}
	return V; 
}

Value* fieldDeclarations::codegen() {
    Value *V = ConstantInt::get(Context, APInt(32, 1));
	for (auto x: list) {
        V = x->codegen();
    	if (V == nullptr) {
    		return V; 
    	}
    }
	return V;
}

Value* fieldDeclaration::codegen() {
	Type *ty = (type->type == "int") ? Type::getInt32Ty(Context): Type::getInt1Ty(Context); 
	for(auto x: fNames->fields) {
		if (x->size) { // array
			ArrayType *arrType = ArrayType::get(ty, x->size->value);
            GlobalVariable *gv = new GlobalVariable(*TheModule, arrType, false,
                                                    GlobalValue::ExternalLinkage, nullptr,
                                                    x->name);
			gv->setInitializer(ConstantAggregateZero::get(arrType));
		} else {
            GlobalVariable *gv = new GlobalVariable(*TheModule, ty, false,
                                                    GlobalValue::ExternalLinkage, nullptr,
                                                    x->name);
            gv->setInitializer(Constant::getNullValue(ty));
        }
	}
	Value *V = ConstantInt::get(Context, APInt(32, 1));
	return V;
} 

Value* fieldNames::codegen() {} 
Value* field::codegen() {} 
Value* varType::codegen() {}

Value* methodDeclarations::codegen() {
	Value *V = ConstantInt::get(Context, APInt(32, 0));
    for (auto x : list) {
        V = x->codegen();
        if (V == nullptr) {
        	return V;
    	}
    }
	return V;
} 

Value* methodDeclaration::codegen() {
	
} 
Value* parameterDeclarations::codegen() {} 
Value* parameterDeclaration::codegen() {} 

Value* codeBlock::codegen() {} 
Value* block::codegen() {} 

Value* varDeclarations::codegen() {} 
Value* varDeclaration::codegen() {} 
Value* varNames::codegen() {} 

Value* statements::codegen() {} 
Value* statement::codegen() {} 
Value* assignSt::codegen() {} 
Value* ifSt::codegen() {} 
Value* elseSt::codegen() {} 
Value* forSt::codegen() {} 
Value* returnSt::codegen() {} 
Value* terminalSt::codegen() {} 
Value* location::codegen() {} 

Value* methodCallSt::codegen() {} 
Value* methodCall::codegen() {} 
Value* methodCallArgs::codegen() {} 

Value* calloutCall::codegen() {} 
Value* CalloutArgs::codegen() {} 
Value* calloutArg::codegen() {} 

Value* Expr::codegen() {}
Value* binExpr::codegen() {} 
Value* unaryExpr::codegen() {} 
Value* enclosedExpr::codegen() {} 
Value* assignOp::codegen() {} 

Value* intLiteral::codegen() {} 
Value* boolLiteral::codegen() {} 
Value* charLiteral::codegen() {} 
Value* stringLiteral::codegen() {} 