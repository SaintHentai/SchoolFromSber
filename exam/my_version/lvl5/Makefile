CC=gcc
CFLAGS=-Wall -Wextra -Werror

default: all

all: check e1 e2 e3 e4

e1: e1.c
	$(CC) $(CFLAGS) -o e1 e1.c

e2: e2.c
	$(CC) $(CFLAGS) -o e2 e2.c

e3: e3.c
	$(CC) $(CFLAGS) -o e3 e3.c

e4: e4.c
	$(CC) $(CFLAGS) -o e4 e4.c


clean:
	rm -f *.o *.exe

rebuild: clean all

check:
	clang-format -n *.c
	clang-format -i *.c
	#cppcheck --enable=all --suppress=missingIncludeSystem *.c
