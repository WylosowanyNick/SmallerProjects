#include <iostream>
#include "SudokuSolver/SudokuSolver.h"

int main()
{
  char sudoku[9][9] =
  {{5, 3, 0, 0, 7, 0, 0, 0, 0},
   {6, 0, 0, 1, 9, 5, 0, 0, 0},
   {0, 9, 8, 0, 0, 0, 0, 6, 0},
   {8, 0, 0, 0, 6, 0, 0, 0, 3},
   {4, 0, 0, 8, 0, 3, 0, 0, 1},
   {7, 0, 0, 0, 2, 0, 0, 0, 6},
   {0, 6, 0, 0, 0, 0, 2, 8, 0},
   {0, 0, 0, 4, 1, 9, 0, 0, 5},
   {0, 0, 0, 0, 8, 0, 0, 7, 9}};

  // Printing the sudoku to solve
  std::cout << "To solve: \n";
  for(char i=0; i<9; i++)
  {
    for(char j=0; j<9; j++)
      std::cout << (int)sudoku[i][j] << ' ';

    std::cout << '\n';
  }
  std::cout << '\n';

  Sudoku* result;
  {
    SudokuSolver sudokuSolver(sudoku);
    sudokuSolver.Run();
    // sudokuSolver.PrintSudoku(); // The result is printed later
    result = sudokuSolver.GetSudoku();
  }

  std::cout << "Result: \n";
  result->PrintSudoku();
  delete result;
}