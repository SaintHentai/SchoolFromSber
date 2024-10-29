CC=gcc
CFLAGS=-c -Wall -Wextra -Werror
SOURCES=polish.c graph.c
OBJECTS=$(SOURCES:.c=.o)
EXECUTABLE=../../build/graph

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $^ -o $@

.c.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -rf $(OBJECTS) $(EXECUTABLE)

rebuild: clean all

stylecheck:
	cp ../../materials/linters/CPPLINT.cfg .
	python3 ../../materials/linters/cpplint.py --extensions=c $(SOURCES)

cppcheck:
	cppcheck --enable=all --suppress=missingIncludeSystem $(SOURCES)
