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
   
    if (RetVal) {
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
    Value *V = nullptr; 
    if (varDecls) {
    	V = varDecls->codegen();
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

// Value* ifSt::codegen() {
//     // cout << "I WANNNA GOOOOOO" << endl; 
//      /* Generate code for the condition */
//     if (cond == nullptr) {
//         //compilerConstructs->errors++;
//         auto error_msg = "Invalid Expression in the IF";
//         cout << error_msg << endl; 
//         return nullptr; 
//     }
//     /* Create blocks for if, else and next part of the code */
//     Function *TheFunction = Builder.GetInsertBlock()->getParent();
//     BasicBlock *ifBlock = BasicBlock::Create(Context, "if", TheFunction);
//     BasicBlock *elseBlock = BasicBlock::Create(Context, "else");
//     BasicBlock *nextBlock = BasicBlock::Create(Context, "ifcont");
//     BasicBlock *otherBlock = elseBlock;
//     bool ret_if = false, ret_else = false; 
//     // bool ret_if = if_block->has_return(), ret_else = false;
//     /// Create a conditional break and an insert point
//     if (eSt == nullptr) {
//         otherBlock = nextBlock;
//     }
    
//     Builder.CreateCondBr(cond, ifBlock, otherBlock);
//     Builder.SetInsertPoint(ifBlock);
//     /// generate the code for if block
//     Value *if_val = code->codegen();
//     if (if_val == nullptr) {
//         return nullptr;
//     }
//     /// Create a break for next part of the code after else block

//     if (!ret_if) {
//         Builder.CreateBr(nextBlock);
//     }

//     ifBlock = Builder.GetInsertBlock();
//     /// Create insert point for else block

//     Value *else_val = nullptr;
//     // cout << "heloooooooooo" << endl; 
//     // cout << (eSt->bl == nullptr) << endl; 
//     if (eSt->bl != nullptr) {
//         /// Generate code for else block
//         TheFunction->getBasicBlockList().push_back(elseBlock);
//         Builder.SetInsertPoint(elseBlock);
//         else_val = eSt->bl->codegen();
//         if (else_val == nullptr) {
//             return nullptr;
//         }
//         ret_else = false; 
//         if (!ret_else)
//             Builder.CreateBr(nextBlock);
//     }

//     // Create a break for the next part of the code
//     TheFunction->getBasicBlockList().push_back(nextBlock);
//     Builder.SetInsertPoint(nextBlock);
//     if (ret_else && ret_if) {
//         // if both if and else block have a return statement create a dummy instruction to hold a next block
//         Type *retType = Builder.GetInsertBlock()->getParent()->getReturnType();
//         if (retType == Type::getVoidTy(Context))
//             Builder.CreateRetVoid();
//         else {
//             Builder.CreateRet(ConstantInt::get(Context, APInt(32, 0)));
//         }
//     }
//     Value *V = ConstantInt::get(Context, APInt(32, 0));
//     return V;
// } 

Value* ifSt::codegen() {
    Value *cond = condition->codegen();
    // if (cond == nullptr) {
    //     errors++;
    //     return reportError("Invalid Expression in the IF");
    // }

    /* Create blocks for if, else and next part of the code */
    auto TheFunction = Builder.GetInsertBlock()->getParent();
    auto if_Block = BasicBlock::Create(Context, "if", TheFunction);
    auto else_Block = BasicBlock::Create(Context, "else");
    auto next_Block = BasicBlock::Create(Context, "ifcont");
    /// Create a conditional break and an insert point
    Builder.CreateCondBr(cond, if_Block, else_Block);
    Builder.SetInsertPoint(if_Block);
    /// generate the code for if block
    Value *if_val = code->codegen();
    if (if_val == nullptr) {
        return nullptr;
    }
    /// Create a break for next part of the code after else block
    Builder.CreateBr(next_Block);
    if_Block = Builder.GetInsertBlock();

    /// Create insert point for else block
    TheFunction->getBasicBlockList().push_back(else_Block);
    Builder.SetInsertPoint(else_Block);
    Value *else_val = nullptr;

    if (eSt->bl) {
        /// Generate code for else block
        else_val = eSt->bl->codegen();
        // if (else_val == nullptr) {
        //     return nullptr;
        // }
    }
    // Create a break for the next part of the code
    Builder.CreateBr(next_Block);
    else_Block = Builder.GetInsertBlock();
    TheFunction->getBasicBlockList().push_back(next_Block);
    Builder.SetInsertPoint(next_Block);

    /// Create phi nodes for if and else blocks if they have return value
    bool phi_if = false, phi_else = false;
    // printf("Has ret = %b\n",ifBlock->has_return);
    // if (ifBlock->has_return) {
    //     // printf("HAS Ret\n");
    //     phi_if = true;
    // }
    // if (elseBlock && elseBlock->has_return) {
    //     phi_else = true;
    // }
    // if (phi_if || phi_else) {
    //     PHINode *PN = Builder.CreatePHI(Type::getInt32Ty(Context), 2, "iftmp");
    //     if (phi_if)
    //         PN->addIncoming(if_val, if_Block);
    //     if (phi_else) {
    //         PN->addIncoming(else_val, else_Block);
    //     }
    //     return PN;
    // }

    Value *V = ConstantInt::get(Context, APInt(32, 0));
    return V;
}
// done 
Value* elseSt::codegen() {} 

Value* forSt::codegen() {
    Value *St = start->codegen();
    if (St == nullptr) {
        return nullptr;
    }
    if (start->form == exprType::loca) {
        St = Builder.CreateLoad(St);
    }
    /* Get the parent method of this for loop */
    Function *TheFunction = Builder.GetInsertBlock()->getParent();
    
    /* Create memory for the loop variable */
    AllocaInst *Alloca = CreateEntryBlockAlloca(TheFunction, var, string("int"));
    Builder.CreateStore(St, Alloca);

    Value *step_val = ConstantInt::get(Context, APInt(32, 1));
    BasicBlock *pre_header_basic_block = Builder.GetInsertBlock();
    BasicBlock *loop_body = BasicBlock::Create(Context, "loop", TheFunction);
    BasicBlock *afterBB = BasicBlock::Create(Context, "afterloop", TheFunction);
    Builder.CreateBr(loop_body);
    Builder.SetInsertPoint(loop_body);

    PHINode *Variable = Builder.CreatePHI(Type::getInt32Ty(Context), 2, var);
    Variable->addIncoming(St, pre_header_basic_block);
    /* Store the old value */
    Value *cond = end->codegen();
    if (cond == nullptr) {
        //compilerConstructs->errors++;
        auto error_msg = "Invalid Condition";
        cout << error_msg << endl; 
    }

    // Check if condition is a location
    if (end->form == exprType::loca) {
        cond = Builder.CreateLoad(cond);
    }
    /* Fix for break and return */ 
    //loops->push(new loopInfo(afterBB, loop_body, cond, var, Variable));
    llvm::AllocaInst *OldVal = NamedValues[var];
    NamedValues[var] = Alloca;
    /* Generate the code for the body */
    if (bl->codegen() == nullptr) {
        return nullptr;
    }

    Value *cur = Builder.CreateLoad(Alloca, var);
    Value *next_val = Builder.CreateAdd(cur, step_val, "NextVal");
    Builder.CreateStore(next_val, Alloca);
    cond = Builder.CreateICmpSLT(next_val, cond, "loopcondition");
    BasicBlock *loopEndBlock = Builder.GetInsertBlock();
    Builder.CreateCondBr(cond, loop_body, afterBB);
    Builder.SetInsertPoint(afterBB);
    Variable->addIncoming(next_val, loopEndBlock);

    if (OldVal) {
        NamedValues[var] = OldVal;
    } else {
        NamedValues.erase(var);
    }
    llvm::Value *V = ConstantInt::get(Context, APInt(32, 1));
    return V;
} 
Value* returnSt::codegen() {
    Value *V = nullptr;
    if (ret != nullptr) {
        V = ret->codegen();
        if (ret->form == exprType::loca) {
            V = Builder.CreateLoad(V);
        }
        Builder.CreateRet(V);
        return V;
    }
    return Builder.CreateRetVoid();
}


Value* terminalSt::codegen() {} 

Value* methodCallSt::codegen() {} 
// fix the right recursive part in this 
Value* methodCall::codegen() {
    // return ConstantInt::get(Context, llvm::APInt(32, 1));
     
     /* Get reference to the function that is to be called */
    Function *calle = TheModule->getFunction(methodName);
    //Function *calle = TheModule->getFunction(methodName);
   
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

Value* calloutCall::codegen() {
    vector<Type *> argTypes;
    vector<Value *> Args;
    // vector<class calloutArgument *> args_list = args->getArgsList();
    /**
     * Iterate through the arguments and generate the code required for each one of them
     */
    for (auto &arg : args->list) {
        Value *V = arg->codegen();
        if (V == nullptr) {
            return V;
        }
        Args.push_back(V);
        argTypes.push_back(V->getType());
    }
    /* Generate the code for the function execution */
    ArrayRef<Type *> argsRef(argTypes);
    ArrayRef<Value *> funcargs(Args);
    FunctionType *FType = FunctionType::get(Type::getInt32Ty(Context), argsRef, false);
    char *p = new char[1000];
    int i; 
    for(i=1;callName->value[i]!='"';i++)
    {
        // cout<<S[i];
        p[i-1] = callName->value[i];
        // printf("%c %c\n",S[i],p[i-1]);
    }
    p[i-1] = '\0';
    Constant *func = TheModule->getOrInsertFunction(p, FType);
    if (!func) {
        // return reportError("Error in inbuilt function. Unknown Function name " + method_name);
        printf("Error in inbuilt function. Unknown Function name\n");
        return nullptr;
    }
    Value *v = Builder.CreateCall(func, funcargs);
    return v;
}

Value* CalloutArgs::codegen() {} 
Value* calloutArg::codegen() {
    if (exp) {
        Value *V = exp->codegen();
        if (exp->form == exprType::loca) {
            V = Builder.CreateLoad(V);
        }
    return V;
    } 
    return Builder.CreateGlobalStringPtr(argName->value);
} 

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
    return ConstantInt::get(Context, APInt(32, static_cast<uint64_t>(value)));
} 

Value* boolLiteral::codegen() {
    // check for error (?)
    return ConstantInt::get(Context, llvm::APInt(1, value));
} 

Value* charLiteral::codegen() {} 

Value* stringLiteral::codegen() {} 