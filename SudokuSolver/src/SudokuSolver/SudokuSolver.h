# pragma once
#include <bitset>

// This class allows to solve (standard) sudoku. To use this class:
// ----------------------------------------------------------------
// 1. This class should be instantiated using one, of two possible
// constructors:
// SudokuSolver(const char sudoku[81])
// or
// SudokuSolver(const char sudoku[][9])
//
// Empty fields should be marked as (char) 0. The class assumes
// solvability and correctness of sudoku supposed to be solved.
//
// 2. Once instantiated, Run() method should be called.
// The solution is held in the class field: char sudoku[9][9].
// ----------------------------------------------------------------
// Example of usage:
// #include <iostream>
// #include "SudokuSolver/SudokuSolver.h"
//
// int main()
// {
//   char sudoku[9][9] =
//   {{5, 3, 0, 0, 7, 0, 0, 0, 0},
//    {6, 0, 0, 1, 9, 5, 0, 0, 0},
//    {0, 9, 8, 0, 0, 0, 0, 6, 0},
//    {8, 0, 0, 0, 6, 0, 0, 0, 3},
//    {4, 0, 0, 8, 0, 3, 0, 0, 1},
//    {7, 0, 0, 0, 2, 0, 0, 0, 6},
//    {0, 6, 0, 0, 0, 0, 2, 8, 0},
//    {0, 0, 0, 4, 1, 9, 0, 0, 5},
//    {0, 0, 0, 0, 8, 0, 0, 7, 9}};
//
//   // Printing the sudoku to solve
//   std::cout << "To solve: \n";
//   for(char i=0; i<9; i++)
//   {
//     for(char j=0; j<9; j++)
//       std::cout << (int)sudoku[i][j] << ' ';
//
//     std::cout << '\n';
//   }
//   std::cout << '\n';
//
//   Sudoku* result;
//   {
//     SudokuSolver sudokuSolver(sudoku);
//     sudokuSolver.Run();
//     // sudokuSolver.PrintSudoku(); // The result is printed later
//     result = sudokuSolver.GetSudoku();
//   }
//
//   std::cout << "Result: \n";
//   result->PrintSudoku();
//   delete result;
// }

class Sudoku
{
private:
  char** sudoku;

public:
  Sudoku();
  Sudoku(const char sudoku[][9]);
  ~Sudoku();

  inline char& Get(char row, char col) { return sudoku[row][col]; }
  void PrintSudoku();
};

class SudokuSolver
{
public:
  char sudoku[9][9];

private:
  struct Coord { char row, col; };

  // Bit fields that store unfinished numbers in the rows,
  // columns and grids (by default all fields are set to 0).
  std::bitset<9> rows[9], cols[9], grids[9];

public:
  SudokuSolver(const char sudoku[81]);
  SudokuSolver(const char sudoku[][9]);

  void Run();
  void PrintSudoku() const;
  Sudoku* GetSudoku() const;

private:
  bool Solve(Coord startCoord = {0, 0});
  Coord FindUnset(Coord startCoord = {0, 0}) const;
  void InitBitset();
  inline char GetGrid(char row, char col) const;
};