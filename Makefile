# Makefile for Sudoku Solver with positional puzzle file
CC = gcc
CFLAGS = -std=c11 -Wall -Wextra -O2
TARGET = sudoku_solver
SRCS = main.c sudoku.c
OBJS = $(SRCS:.c=.o)

.PHONY: all run clean

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $(OBJS)

%.o: %.c sudoku.h
	$(CC) $(CFLAGS) -c $<

# Usage: make run puzzle.txt
run: $(TARGET)
ifneq ($(filter-out run,$(MAKECMDGOALS)),)
	@./$(TARGET) $(filter-out run,$(MAKECMDGOALS))
else
	@echo "Usage: make run <puzzle-file>"
endif

# Prevent make from trying to interpret the puzzle filename as a real target
%:
	@:
	
clean:
	rm -f $(OBJS) $(TARGET)
