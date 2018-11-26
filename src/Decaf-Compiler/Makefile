TARGET=mycomp
all=$(TARGET)
CC=g++
CFLAGS = -lfl `llvm-config-6.0 --cxxflags --cppflags mcjit native --ldflags --libs core` -ltinfo -lpthread -ldl
FLAGS =-w -Wno-deprecated -g -std=c++11
all: $(TARGET)
$(TARGET): lex.yy.c parser.tab.c ast.cpp ast.h AcceptMethods.cpp VisitorMethods.cpp codeGen.cpp 
	$(CC) $(FLAGS) lex.yy.c parser.tab.c ast.cpp ast.h AcceptMethods.cpp VisitorMethods.cpp codeGen.cpp $(CFLAGS)
lex.yy.c: lexer.l
	flex lexer.l
parser.tab.c: parser.y
	bison -vd -Wconflicts-rr parser.y
clean:
	rm -f *.c parser.tab.h *.output llout a.out
veryclean:
	rm -f *.c parser.tab.h a.out XML_* *.output
