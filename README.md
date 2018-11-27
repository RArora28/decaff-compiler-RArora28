# Decaf Programming Language Compiler

## File Structure
- `ast.h` : Declarations of the AST Node types, Visitor Class.  
- `ast.cpp` : Implements the various AST Nodes. 
- `AcceptMethods.cpp` : Implements the accept functions of AST nodes.  
- `VisitorMethods.cpp` : Implements a simple visitor for the purpose of Semantic Analysis. 
- `codeGen.cpp` : Implements the visitor for the code generation.
- `lexer.l` : Regular expressions for scanner genaration
- `parser.y` : Grammar rules for parsing
- `Sample-Decaf-Codes` : contains sample programs

## Run
1. `make clean`
 - optional
2. `make`
3. `./a.out inputFile.dcf > out`
 - redirect generated code from `stdout` to `out` file
 - errors and warnings are still printed to terminal through `stderr`
 - remove the second line in the out file
4. `lli out`
 - Runs the generated code

The above steps use the config utility `llvm-config`, which must be installed
on the system path and be available without specifying a version number.

This project uses the `clang++` compiler.

## Description
The project combines the `flex` scanner generator and `bison` parser. Parsing leads to generation of the Abstract Syntax Tree. 
The use of C++ allows for design patters such as the visitor pattern to pass
over the AST for debugging and code generations purposes.
