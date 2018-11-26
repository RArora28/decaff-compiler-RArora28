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
	vector<pair < string, string > > args; 
    vector<Type *> arguments;
    auto arg_size = args.size();
    for (auto param: listParams) {
        /* Iterate over the arguments and get the types of them in llvm */
        auto arg_type = param->type->type;
        auto arg_name = param->name;
        if (arg_type == "int") {
            arguments.push_back(Type::getInt32Ty(Context));
        } else if (arg_type == "boolean") {
            arguments.push_back(Type::getInt1Ty(Context));
        } else {
            //errors++;
            cout << "Arguments can only be int or boolean" << endl;
            return nullptr;
        }
        args.push_back({arg_name, arg_type}); 
    }

    Type *retType;
    switch (returnType->type) {
    	case "int":		retType = Type::getInt32Ty(Context);
		case "boolean":	retType = Type::getInt1Ty(Context);
    	case "void":	retType = Type::getVoidTy(Context);
    	default:    	{ // errors++;
        	auto msg = "Invalid Return Type for " + methodName + ". Return Type can only be int or boolean";
        	cout << msg << endl; 
        	return nullptr;
    	}
    }
    
    /* Get the function type and create a Function */
    FunctionType *FT = llvm::FunctionType::get(retType, arguments, false);
    Function *F = llvm::Function::Create(FT, Function::ExternalLinkage, methodName, TheModule);

    /* Iterate through arguments and set the Names for them */
    int Idx = 0;
    for (Function::arg_iterator AI = F->arg_begin(); Idx != arg_size; ++AI, ++Idx) {
        AI->setName(argNames[Idx]);
    }

    /* Create a New block for this Function */
    BasicBlock *BB = BasicBlock::Create(compilerConstructs->Context, "entry", F);
    compilerConstructs->Builder->SetInsertPoint(BB);
    Idx = 0;

    /* Allocate memory for the arguments passed */
    for (auto &Arg : F->args()) {
        AllocaInst *Alloca = compilerConstructs->CreateEntryBlockAlloca(F, argNames[Idx], argTypes[Idx]);
        compilerConstructs->Builder->CreateStore(&Arg, Alloca);
        compilerConstructs->NamedValues[argNames[Idx]] = Alloca;
        Idx++;
    }

    Value *RetVal = body->generateCode(compilerConstructs);
    if (RetVal) {
        /* make this the return value */
        if (return_type != "void")
            compilerConstructs->Builder->CreateRet(RetVal);
        else
            compilerConstructs->Builder->CreateRetVoid();
        /// Iterate through each basic block in this function and remove any dead code
        for (auto &basicBlock : *F) {
            BasicBlock *block = &basicBlock;
            removeDeadCode(block);
        }
        /* Verify the function */
        verifyFunction(*F);
        compilerConstructs->TheFPM->run(*F);
        return F;
    }

    /* In case of errors remove the function */
    F->eraseFromParent();
	return nullptr;
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