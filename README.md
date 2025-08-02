# Sudoku Solver (C)

A simple **C** program that solves standard 9×9 Sudoku puzzles using **recursive backtracking**.  
Takes a puzzle from a `.txt` file (zeros for empty cells, spaces or newlines allowed) and outputs the solved puzzle to the terminal.

---

## Features
- Reads puzzle from a text file
- Handles input with spaces or newlines between numbers
- Validates moves against Sudoku row, column, and 3×3 zone constraints
- Solves puzzles using recursive backtracking
- Prints the original puzzle and the solved puzzle in a clean format

---

## Input Format
- File must contain exactly **81 integers** (0–9), where `0` represents an empty cell.
- Numbers can be separated by spaces or newlines.

Example `sudoku1.txt`:  
0 0 0 4 2 0 0 0 0  
3 0 0 0 0 0 8 0 0  
9 0 0 1 0 8 0 0 5  
0 2 0 0 8 0 0 0 1  
1 0 0 0 0 4 0 2 0  
8 4 0 0 0 0 0 0 0  
4 1 0 0 0 0 0 3 6  
0 0 5 0 0 3 0 0 0  
0 0 6 0 0 0 2 0 0  

---

## Run Instructions

Compile: `make`  
You can run the solver directly: `./sudoku.solver sudoku1.txt`  
Or use the Makefile: `make run sudoku1.txt`  
To remove compiled files: `make clean`  

---

## Example Output

\------------------  
Input sudoku:  
 5 3 0 0 7 0 0 0 0  
 6 0 0 1 9 5 0 0 0  
 0 9 8 0 0 0 0 6 0  
 8 0 0 0 6 0 0 0 3  
 4 0 0 8 0 3 0 0 1  
 7 0 0 0 2 0 0 0 6  
 0 6 0 0 0 0 2 8 0  
 0 0 0 4 1 9 0 0 5  
 0 0 0 0 8 0 0 7 9  
Your output sudoku:  
 5 3 4 6 7 8 9 1 2  
 6 7 2 1 9 5 3 4 8  
 1 9 8 3 4 2 5 6 7  
 8 5 9 7 6 1 4 2 3  
 4 2 6 8 5 3 7 9 1  
 7 1 3 9 2 4 8 5 6  
 9 6 1 5 3 7 2 8 4  
 2 8 7 4 1 9 6 3 5  
 3 4 5 2 8 6 1 7 9  
\------------------  