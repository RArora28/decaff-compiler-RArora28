#include "ast.h"

using namespace std; 
using namespace llvm; 

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

static LLVMContext Context;
static Module *TheModule = new Module("decaf Compiler", Context);
static IRBuilder<> Builder(Context);
static map<string, AllocaInst*> NamedValues;
static map <string, AllocaInst*> Old_vals;

AllocaInst* CreateEntryBlockAlloca(Function *TheFunction, const string& VarName, const string& type) {
    IRBuilder<> TmpB(&TheFunction->getEntryBlock(), TheFunction->getEntryBlock().begin());
    AllocaInst *alloca_instruction = nullptr;
    if (type == "int") {
        alloca_instruction = TmpB.CreateAlloca(Type::getInt32Ty(Context), 0, VarName);
    } else if (type == "boolean") {
        alloca_instruction = TmpB.CreateAlloca(Type::getInt1Ty(Context),  0, VarName);
    }
    return alloca_instruction;
}

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
    if (params) {
	    for (auto param: params->listParams) {
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
	        args.push_back(make_pair(arg_name, arg_type)); 
	    }
	}

    Type *retType;
 	if (returnType->type == "int") {
        retType = Type::getInt32Ty(Context);
    } else if (returnType->type == "boolean") {
        retType = Type::getInt1Ty(Context);
    } else if (returnType->type == "void") {
        retType = Type::getVoidTy(Context);
    } else {
        //errors++;
        string error_msg = "Invalid Return Type for " + methodName + ". Return Type can only be int or boolean or bool";
        cout << error_msg << endl; 
        return nullptr;
	}
    
    /* Get the function type and create a Function */
    FunctionType *FT = llvm::FunctionType::get(retType, arguments, false);
    Function *F = llvm::Function::Create(FT, Function::ExternalLinkage, methodName, TheModule);

    /* Iterate through arguments and set the Names for them */
    int Idx = 0, arg_size = args.size();
  
    for (Function::arg_iterator AI = F->arg_begin(); Idx != arg_size; ++AI, ++Idx) {
        AI->setName(args[Idx].first);
    }

    /* Create a New block for this Function */
    BasicBlock *BB = BasicBlock::Create(Context, "entry", F);
    Builder.SetInsertPoint(BB);
    Idx = 0;

    /* Allocate memory for the arguments passed */
    for (auto &Arg : F->args()) {
        AllocaInst *Alloca = CreateEntryBlockAlloca(F, args[Idx].first, args[Idx].second);
        Builder.CreateStore(&Arg, Alloca);
        NamedValues[args[Idx].first] = Alloca;
        Idx++;
    }

    Value *RetVal = code->codegen();
    // if (RetVal) {
    //     /* make this the return value */
    //     if (returnType->type != "void")
    //         Builder.CreateRet(RetVal);
    //     else
    //         Builder.CreateRetVoid();
    //     cout << "called" << endl; 
    //     return F;
    // }
   
    trace(RetVal == nullptr); 
    if (RetVal) {
    	Builder.CreateRetVoid(); 
    	return F;
    } 
    /* In case of errors remove the function */
    F->eraseFromParent();
	return nullptr;
} 

Value* parameterDeclarations::codegen() {} 
Value* parameterDeclaration::codegen() {} 

Value* codeBlock::codegen() {
	Value *V = nullptr; 
	if (bl) {
		V = bl->codegen(); 
	}	
	return V; 
} 
Value* block::codegen() {
	Old_vals.clear(); 
    Value *V; 
    
    if (varDecls) {
    	V = varDecls->codegen();
    } 
    if (V == nullptr) {
        return V;
    }
    if (stmts) {
    	V = stmts->codegen();
    }
    if (V == nullptr) {
    	return V; 
    }

    // Adjust the values back to old values 
    for (auto it = Old_vals.begin(); it != Old_vals.end(); it++) {
        NamedValues[it->first] = Old_vals[it->first];
    }
    trace(V == nullptr);
    return V;
}

Value* varDeclarations::codegen() {
	Value *V = ConstantInt::get(Context, APInt(32, 1));
    if (list.size()) {
       for (auto &x : list) {
	        /// Generate the code for each declaration
	        if (x) {
	        	V = x->codegen();
	        } 
	        if (V == nullptr) {
	            return V;
	        }
	    }
	} else {
		V = nullptr; 
	}
    return V;
} 
Value* varDeclaration::codegen() {
    Function *TheFunction = Builder.GetInsertBlock()->getParent();
    for (const auto &var : names->names) {
        Value *initval = nullptr;
        AllocaInst *Alloca = nullptr;
        if (type->type == "int") {
            initval = ConstantInt::get(Context, APInt(32, 0));
            Alloca  = CreateEntryBlockAlloca(TheFunction, var, "int");
        } else if (type->type == "boolean") {
            initval = ConstantInt::get(Context, APInt(1, 0));
            Alloca = CreateEntryBlockAlloca(TheFunction, var, "boolean");
        }
        Builder.CreateStore(initval, Alloca);
        /* Store the old value to old_vals and new value to named values */
        Old_vals[var] = NamedValues[var];
        NamedValues[var] = Alloca;
    }
    Value *V = ConstantInt::get(Context, APInt(32, 1));
    return V;
} 

Value* varNames::codegen() {} 

Value* statements::codegen() {
    Value *V = ConstantInt::get(Context, llvm::APInt(32, 1));
    for (auto &stmt : list) {
        V = stmt->codegen();
        if (V == nullptr) {
            return V; 
        }
    }
    return V;
} 

Value* statement::codegen() {}

Value* assignSt::codegen() {
    auto name = loc->name; 
    Value *curr = NamedValues[name];
    if (curr == nullptr) {
        curr = TheModule->getGlobalVariable(name);
    }
    if (curr == nullptr) {
        // compilerConstructs->errors++;
        auto error_msg = "Unknown Variable Name " + name; 
        cout << error_msg << endl; 
        // return curr; (?) 
    }

    Value *val = exp->codegen();
    if (exp->form == exprType::loca) {
        val = Builder.CreateLoad(val);
    }

    Value *lhs = loc->codegen();
    curr = Builder.CreateLoad(lhs);

    if (val == nullptr) {
        // compilerConstructs->errors++;
        auto error_msg = "Error in right hand side of the Assignment";
        cout << error_msg << endl; 
    }
    if (asOp->op == "+=") {
        val = Builder.CreateAdd(curr, val, "addEqualToTmp");
    } else if (asOp->op == "-=") {
        val = Builder.CreateSub(curr, val, "subEqualToTmp");
    }
    return Builder.CreateStore(val, lhs);
}

Value* ifSt::codegen() {
     /* Generate code for the condition */

    Value *cond = condition->codegen();
    if (cond == nullptr) {
        //compilerConstructs->errors++;
        auto error_msg = "Invalid Expression in the IF";
        cout << error_msg << endl; 
        return nullptr; 
    }

    /* Create blocks for if, else and next part of the code */
    Function *TheFunction = Builder->GetInsertBlock()->getParent();
    BasicBlock *ifBlock = BasicBlock::Create(Context, "if", TheFunction);
    BasicBlock *elseBlock = BasicBlock::Create(Context, "else");
    BasicBlock *nextBlock = BasicBlock::Create(Context, "ifcont");
    BasicBlock *otherBlock = elseBlock;
    bool ret_if = true, ret_else = false; 
    // bool ret_if = if_block->has_return(), ret_else = false;
    /// Create a conditional break and an insert point
    if (else_block == nullptr) {
        otherBlock = nextBlock;
    }
    Builder.CreateCondBr(cond, ifBlock, otherBlock);
    Builder.SetInsertPoint(ifBlock);
    /// generate the code for if block
    Value *if_val = code->codegen();
    if (if_val == nullptr) {
        return nullptr;
    }
    /// Create a break for next part of the code after else block

    if (!ret_if) {
        Builder.CreateBr(nextBlock);
    }

    ifBlock = Builder.GetInsertBlock();
    /// Create insert point for else block

    Value *else_val = nullptr;

    if (eSt != nullptr) {
        /// Generate code for else block
        TheFunction->getBasicBlockList().push_back(elseBlock);
        Builder.SetInsertPoint(elseBlock);
        else_val = eSt->codegen();
        if (else_val == nullptr) {
            return nullptr;
        }
        ret_else = true; 
        if (!ret_else)
            Builder.CreateBr(nextBlock);
    }

    // Create a break for the next part of the code
    TheFunction->getBasicBlockList().push_back(nextBlock);
    Builder.SetInsertPoint(nextBlock);
    if (ret_else && ret_if) {
        // if both if and else block have a return statement create a dummy instruction to hold a next block
        Type *retType = Builder.GetInsertBlock()->getParent()->getReturnType();
        if (retType == Type::getVoidTy(Context))
            Builder.CreateRetVoid();
        else {
            Builder,CreateRet(ConstantInt::get(Context, APInt(32, 0)));
        }
    }
    Value *V = ConstantInt::get(Context, APInt(32, 0));
    return V;
} 

Value* elseSt::codegen() {} 
Value* forSt::codegen() {} 
Value* returnSt::codegen() {} 
Value* terminalSt::codegen() {} 

Value* methodCallSt::codegen() {} 
// fix the right recursive part in this 
Value* methodCall::codegen() {
    // return ConstantInt::get(Context, llvm::APInt(32, 1));
     
     /* Get reference to the function that is to be called */
    cout << "iske andar aaya? " << endl; 
    Function *calle = TheModule->getFunction(methodName);
    //Function *calle = TheModule->getFunction(methodName);
   
    trace(calle == nullptr, methodName);
    if (calle == nullptr) {
        // compilerConstructs->errors++;
        auto error_msg = "Unknown Function name " + methodName;
        cout << error_msg << endl; 
        return nullptr;
    }
    /* Check if required number of parameters are passed */
    if (calle->arg_size() != args->list.size()) {
        // compilerConstructs->errors++;
        auto error_msg = "Incorrect Number of Parameters Passed";
        cout << error_msg << endl; 
        return nullptr; 
    }
    /// Generate the code for the arguments
    vector<Value *> Args;
    for (auto &arg : args->list) {
        Value *argVal = arg->codegen();
        if (arg->form == exprType::loca) {
            argVal = Builder.CreateLoad(argVal);
        }
        if (argVal == nullptr) {
            // compilerConstructs->errors++;
            auto error_msg = "Argument is not valid";
            cout << error_msg << endl; 
            return nullptr;
        }
        Args.push_back(argVal);
    }
    // Reverse the order of arguments as the parser parses in the reverse order
    reverse(Args.begin(), Args.end());
    // Generate the code for the function call
    Value *V = Builder.CreateCall(calle, Args);
    return V;
} 

Value* methodCallArgs::codegen() {} 

Value* calloutCall::codegen() {} 
Value* CalloutArgs::codegen() {} 
Value* calloutArg::codegen() {} 

Value* Expr::codegen() {}
Value* location::codegen() {
     /* Try to get the value of the variable */
    Value *V = NamedValues[name];
    if (V == nullptr) {
        V = TheModule->getNamedGlobal(name);
    }
    if (V == nullptr) {
        //compilerConstructs->errors++;
        auto error_msg = "Unknown Variable name " + name;
        cout << error_msg << endl; 
    }
    /* If location is variable return the code generated */
    if (!exp) {
        return V;
    }

    /* Generate the code for index of the array */
    Value *index = exp->codegen();
    if (exp->form == exprType::loca) {
        index = Builder.CreateLoad(index);
    }
    /* If index is invalid then report error */
    if (index == nullptr) {
        auto error_msg = "Invalid Array Index"; 
        cout << error_msg << endl; 
        return index; 
    }
    /* Generate the code required for accessing the array at the given index */
    vector<Value *> array_index;
    array_index.push_back(Builder.getInt32(0));
    array_index.push_back(index);
    V = Builder.CreateGEP(V, array_index, name + "_Index");
    return V;
} 

Value* binExpr::codegen() {
    Value *left = nullptr, *right = nullptr; 
    if (exp1->form == exprType::enclExpr) {
        left = exp1->codegen(); 
    }
    if (exp2->form == exprType::enclExpr) {
        right = exp2->codegen(); 
    }
    if (!left) {
        left = exp1->codegen();
    }
    if (!right) {
        right = exp2->codegen();
    }
    if (exp1->form == exprType::loca) {
        left = Builder.CreateLoad(left);
    }
    if (exp2->form == exprType::loca) {
        right = Builder.CreateLoad(right);
    }
    if (left == 0) {
        //errors++;
        auto error_msg = "Error in left operand of " + op;
        return nullptr; 
    } else if (right == 0) {
        //errors++;
        auto error_msg = "Error in right operand of " + op;
        return nullptr; 
    }
    Value *V = nullptr;
    if (op == "+") {
        V = Builder.CreateAdd(left, right, "add");
    } else if (op == "-") {
        V = Builder.CreateSub(left, right, "sub");
    } else if (op == "*") {
        V = Builder.CreateMul(left, right, "mult");
    } else if (op == "/") {
        V = Builder.CreateSDiv(left, right, "div");
    } else if (op == "%") {
        V = Builder.CreateSRem(left, right, "mod");
    } else if (op == "<") {
        V = Builder.CreateICmpSLT(left, right, "lt");
    } else if (op == ">") {
        V = Builder.CreateICmpSGT(left, right, "gt");
    } else if (op == "<=") {
        V = Builder.CreateICmpSLE(left, right, "le");
    } else if (op == ">=") {
        V = Builder.CreateICmpSGE(left, right, "ge");
    } else if (op == "==") {
        V = Builder.CreateICmpEQ(left, right, "equality");
    } else if (op == "!=") {
        V = Builder.CreateICmpNE(left, right, "inequality");
    }    
    return V; 
} 

Value* unaryExpr::codegen() {
    /// Generate IR for body of the expression
    Value *V = exp->codegen();
    if (exp->form == exprType::loca) {
        V = Builder.CreateLoad(V);
    }
    /// Generate the code for operation based on the operator
    if (op == "-") {
        return Builder.CreateNeg(V, "neg");
    } else if (op == "!") {
        return Builder.CreateNot(V, "not");
    }
    return nullptr; 
} 
Value* enclosedExpr::codegen() {
    return (exp == nullptr) ? nullptr: exp->codegen(); 
} 

// useless 
Value* assignOp::codegen() {} 

Value* intLiteral::codegen() {
    return ConstantInt::get(Context, llvm::APInt(32, static_cast<uint64_t>(value)));
} 

Value* boolLiteral::codegen() {
    // check for error (?)
    return ConstantInt::get(Context, llvm::APInt(1, value));
} 

Value* charLiteral::codegen() {} 

Value* stringLiteral::codegen() {} 