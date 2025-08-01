#include "sudoku.h"

int main(int argc, char **argv) {

  int sudoku[9][9];

  if(argc != 2) {
    return 1;
  }

  printf("------------------\n");
  parse_sudoku(argv[1], sudoku);
  printf("Input sudoku:\n");
  print_sudoku(sudoku);
  
  solve_sudoku(sudoku);
  printf("Your output sudoku:\n");
  print_sudoku(sudoku);
  printf("------------------\n");


  return 0;
}