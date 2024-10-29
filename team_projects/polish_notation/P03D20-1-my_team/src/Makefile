.PHONY: all rebuild clean
CC=gcc
CFLAGS=-c
LDFLAGS=-Wall -Wextra -Werror 

default: all

all: clean graph_module

graph_module: clean graph.o parser.o plot.o stack.o polish_notation.o 
	$(CC) $(LDFLAGS) -o ../build/graph graph.o parser.o plot.o stack.o polish_notation.o
	rm -rf *.o *.out
graph.o:
	$(CC) $(CFLAGS) -o graph.o graph.c
polish_notation.o:
	$(CC) $(CFLAGS) -o polish_notation.o data_polish/polish_notation.c
parser.o:
	$(CC) $(CFLAGS) -o parser.o data_parser/parser.c
plot.o:
	$(CC) $(CFLAGS) -o plot.o data_plot/plot.c
stack.o:
	$(CC) $(CFLAGS) -o stack.o data_stack/stack.c

check:
	cp ../materials/linters/CPPLINT.cfg CPPLINT.cfg
	python3 ../materials/linters/cpplint.py --extension=c *.c *.h
	cppcheck --enable=all --suppress=missingIncludeSystem *.c
	rm -rf *.o *.out *.cfg
	leaks --atExit -- ../build/graph

clean:
	rm -rf ../build/* *.o *.out
rebuild: clean all

