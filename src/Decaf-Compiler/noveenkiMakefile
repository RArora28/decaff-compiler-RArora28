TARGET=decaf
all=$(TARGET)
CC = g++
CFLAGS = -lfl `llvm-config-6.0 --cxxflags --cppflags mcjit native --ldflags --libs core` -ltinfo -lpthread -ldl
FLAGS = -w -Wno-deprecated -g --std=c++14
all: $(TARGET)
$(TARGET): lex.yy.c parser.tab.c class.cpp class_definition.h visitor.cpp semantic.cpp codegen.cpp
	$(CC) $(FLAGS) -o $@ lex.yy.c parser.tab.c class.cpp visitor.cpp semantic.cpp codegen.cpp $(CFLAGS)
lex.yy.c: scanner.l
	flex scanner.l
parser.tab.c: parser.y
	bison -vd parser.y
clean:
	rm -f *.c parser.tab.h *.output llout decaf
veryclean:
	rm -f *.c parser.tab.h decaf XML_* *.output
