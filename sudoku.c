#include "sudoku.h"

/* 
 * The is_val_in_row function checks whether a given input val already exists in a given row i in
 * a given sudoku board. The function asserts that the given row index is within the 9x9 bounds of
 * the sudoku board. If it is, then it iterates through each column j in the given row and checks if
 * the value at that loation is equal to the input value. If they are equal, that means that the
 * given value already exists in the ith row of the given sudoku, and the function will return 1.
 * If no match was found throughout the row, then the function returns 0, signifying the value does
 * not already exist in the ith row of the given sudoku.
 * 
 * The is_val_in_col function checks whether a given input val already exists in a given column j
 * in a given sudoku board. The function asserts that the given column index is within the 9x9 bounds
 * of the sudoku board. If it is, then it iterates through each row i in the given column and checks if
 * the value at that location is equal to the input value. If they are equal, that means that the
 * given value already exists in the jth column of the given sudoku, and the function will return 1.
 * If no match was found throughout the column, then the function returns 0, signifying the value does
 * not already exist in the jth column of the given sudoku.
 * 
 * The is_val_in_3x3_zone function checks whether a given input val already exists within its 3x3
 * zone in a given sudoku board. The function asserts that the given row and column index are within
 * the 9x9 bounds of the sudoku board. If they are, then computes an "new row" and "new column" in
 * newrow and newcol using the expression i % 3 and j % 3 respectively. newrow and newcol represent
 * the row and column index of a given position in its 3x3 zone. If newrow = 0, (i, j) lies on the top 
 * row in its 3x3 zone. If newrow = 1, (i, j) lies on the middle row in its 3x3 zone. If newrow = 2, 
 * (i, j) lies on the bottom row in its 3x3 zone. If new col = 0, (i, j) lies on the left column in its 
 * 3x3 zone. If new col = 1, (i, j) lies on the middle column in its 3x3 zone. If new col = 2, (i, j) 
 * lies on the right column in its 3x3 zone. The values of newrow and newcol are used to set the bounds
 * for iterating through the 3x3 zone. The lower bound for both row and column is computed using the 
 * formula i - newrow and j - newcol respectively. The upper bound for both row and column is computed
 * using the formula i + 3 - newrow and j + 3 - newcol respectively. As it iterates through each cell
 * in the 3x3 zone, the function checks if the value at that location is equal to the input value.
 * If they are equal, that means that the given value already exists in the 3x3 zone, and the function
 * will return 1. If no match was found throughout the 3x3 zone, then the function returns 0, signifying 
 * the value does not already exist in the 3x3 zone.
 * 
 * The is_val_valid function solves a given sudoku board. The function first declares variables row, col,
 * and is_filled, which indicates whether sudoku is filled (1 for filled and 0 for unfilled). The function
 * iterates through each cell in the sudoku and looks for an empty (0) cell. Once it finds the first 
 * empty cell, is_filled is set to 0, row is set to the row index of the empty cell, col is set to the 
 * column index of the empty cell, and the function breaks out of the iteration. If no empty cell was
 * found, that means the sudoku board is filled, and the function returns 1. This is the base case
 * of the recursive function. If an empty cell was found, then the function iterates through each 
 * possible value 1-9 and checks if that value is valid at (row, col) using the is_val_valid function.
 * If it is valid, then the value will be placed at (row, col) on the sudoku board, and the function
 * uses recursion to check if that move solves the sudoku. If it does, then the function returns 1. 
 * If not, the function returns 0 and backtracks. 
*/

// Function: is_val_in_row
// Return true if "val" already existed in ith row of array sudoku.
int is_val_in_row(const int val, const int i, const int sudoku[9][9]) {

  assert(i>=0 && i<9);

  /* for each column of the ith row */
  for (int j = 0; j < 9; j++) {

    /* check if val already existed in the ith row */
    if (sudoku[i][j] == val) {
      return 1;
    }
  }

  return 0;
}

// Function: is_val_in_col
// Return true if "val" already existed in jth column of array sudoku.
int is_val_in_col(const int val, const int j, const int sudoku[9][9]) {

  assert(j>=0 && j<9);

  /* for each row of the jth column */
  for (int i = 0; i < 9; i++) {

    /* check if val already existed in the jth column */
    if (sudoku[i][j] == val) {
      return 1;
    }
  }
  
  return 0;
}

// Function: is_val_in_3x3_zone
// Return true if val already existed in the 3x3 zone corresponding to (i, j)
int is_val_in_3x3_zone(const int val, const int i, const int j, const int sudoku[9][9]) {
   
  assert(i>=0 && i<9 && j>=0 && j<9);
  
  int newrow = i % 3; // the row index within the 3x3 zone, used to set bounds for row iteration
  int newcol = j % 3; // the column index within the 3x3 zone, used to set bounds for column iteration

  /* 
   * if newrow = 0, (i, j) lies on the top row in its 3x3 zone
   * if newrow = 1, (i, j) lies on the middle row in its 3x3 zone
   * if newrow = 2, (i, j) lies on the bottom row in its 3x3 zone
   * if new col = 0, (i, j) lies on the left column in its 3x3 zone
   * if new col = 1, (i, j) lies on the middle column in its 3x3 zone
   * if new col = 2, (i, j) lies on the right column in its 3x3 zone
   */

  for (int r = (i - newrow); r < (i + 3 - newrow); r++) {
    for (int c = (j - newcol); c < (j + 3 - newcol); c++) {
      if (sudoku[r][c] == val) {
        return 1;
      }
    }
  }
  
  return 0;
}

// Function: is_val_valid
// Return true if the val is can be filled in the given entry.
int is_val_valid(const int val, const int i, const int j, const int sudoku[9][9]) {

  assert(i>=0 && i<9 && j>=0 && j<9);

  /* check if val already exists in the row, column, and 3x3 zone */
  if (is_val_in_row(val, i, sudoku) || is_val_in_col(val, j, sudoku) || is_val_in_3x3_zone(val, i, j, sudoku)) {
    return 0;
  }

  return 1;
}

// Procedure: solve_sudoku
// Solve the given sudoku instance.
int solve_sudoku(int sudoku[9][9]) {

  int row; // stores row
  int col; // stores column
  int is_filled = 1; // indicates whether sudoku is filled; 1 for filled, 0 for unfilled

  /* for each cell in the sudoku*/
  for (int i = 0; i < 9; i++) {
    for (int j = 0; j < 9; j++) {
      
      /* check if empty cell is found */
      if (sudoku[i][j] == 0) {
        is_filled = 0; // set is_filled to 0
        row = i; // set row to row index of empty cell
        col = j; // set col to column index of empty cell
        break; // break out of inner loop
      }
    }

    if (!is_filled) {
      break; // break out of outer loop if empty cell was found
    }
  }

  /* base case: if sudoku is filled */
  if (is_filled) {
    return 1;
  }
  /* recursive case: if sudoku is not filled */
  else {

    /* iterate through each possible value */
    for (int val = 1; val <= 9; val++) {

      /* check if val is valid at empty cell */
      if (is_val_valid(val, row, col, sudoku)) {

        /* place val at cell */
        sudoku[row][col] = val;

        /* check if solve_sudoku solves the sudoku */
        if (solve_sudoku(sudoku)) {
          return 1;
        }
        
        /* if sudoku is not solved, zero the cell */
        sudoku[row][col] = 0; // backtrack
      }
    }
  }

  return 0; // backtrack
}

// Procedure: print_sudoku
void print_sudoku(int sudoku[9][9])
{
  int i, j;
  for(i=0; i<9; i++) {
    for(j=0; j<9; j++) {
      printf("%2d", sudoku[i][j]);
    }
    printf("\n");
  }
}

// Procedure: parse_sudoku
void parse_sudoku(const char fpath[], int sudoku[9][9]) {
  FILE *reader = fopen(fpath, "r");
  assert(reader != NULL);
  int i, j;
  for(i=0; i<9; i++) {
    for(j=0; j<9; j++) {
      fscanf(reader, "%d", &sudoku[i][j]);
    }
  }
  fclose(reader);
}