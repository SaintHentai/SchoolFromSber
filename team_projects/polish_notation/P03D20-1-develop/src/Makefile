CC = gcc
CFLAGS = -Wall -Wextra -Werror -std=c11

SRC = graph.c lexer.c parser.c evaluator.c drawer.c math_ops.c stack.c
OBJ = $(SRC:.c=.o)
TARGET = ../build/graph

all: $(TARGET)

$(TARGET): $(OBJ)
	mkdir -p ../build
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJ)
	rm *.o

clean:
	rm -rf ../build $(OBJ)

.PHONY: all clean
