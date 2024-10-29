.PHONY: state_sort state_search clear_state
CC=gcc
CFLAGS=-Wall -Wextra -Werror
INCLUDE=-Ilibs
BUILDDIR=../build/

all: clean state_sort state_search clear_state

state_sort: state_sort.o processing.o
	$(CC) state_sort.o processing.o -o $(BUILDDIR)Quest_1

state_search: state_search.o processing.o
	$(CC) state_search.o processing.o -o $(BUILDDIR)Quest_2

clear_state: clear_state.o processing.o
	$(CC) clear_state.o processing.o -o $(BUILDDIR)Quest_3

state_sort.o:
	$(CC) $(CFLAGS) $(INCLUDE) -c -o state_sort.o quest1/state_sort.c
state_search.o:
	$(CC) $(CFLAGS) $(INCLUDE) -c -o state_search.o quest2/state_search.c
clear_state.o:
	$(CC) $(CFLAGS) $(INCLUDE) -c -o clear_state.o quest3/clear_state.c
processing.o:
	$(CC) $(CFLAGS) $(INCLUDE) -c -o processing.o libs/processing.c

check:
	cp ../materials/linters/CPPLINT.cfg CPPLINT.cfg
	python3 ../materials/linters/cpplint.py --extension=c *.c *.h
	cppcheck --enable=all --suppress=missingIncludeSystem *.c

rebuild: clean all

clean:
	rm -f *.o
	rm -f $(BUILDDIR)Q*
