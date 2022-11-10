#include "SudokuSolver.h"
#include <iostream>

// Class Sudoku
Sudoku::Sudoku()
  : sudoku(nullptr)
{}

Sudoku::Sudoku(const char sudoku[][9])
{
  this->sudoku = new char*[9];
  for(char i=0; i<9; i++)
    this->sudoku[i] = new char[9];

  for(char i=0; i<9; i++)
    for(char j=0; j<9; j++)
      this->Get(i, j) = sudoku[i][j];
}

Sudoku::~Sudoku()
{
  for(char i=0; i<9; i++)
    delete[] this->sudoku[i];

  delete[] this->sudoku;
}

void Sudoku::PrintSudoku()
{
  for(char i=0; i<9; i++)
  {
    for(char j=0; j<9; j++)
      std::cout << (int)sudoku[i][j] << ' ';

    std::cout << '\n';
  }

  std::cout << '\n';
}

// Class SudokuSolver
// Public:
  SudokuSolver::SudokuSolver(const char sudoku[81])
  {
    for(char i=0; i<9; i++)
      for(char j=0; j<9; j++)
        this->sudoku[i][j] = sudoku[9*i + j]-1;

    InitBitset();
  }

  SudokuSolver::SudokuSolver(const char sudoku[][9])
  {
    for(char i=0; i<9; i++)
      for(char j=0; j<9; j++)
        this->sudoku[i][j] = sudoku[i][j]-1;

    InitBitset();
  }

  void SudokuSolver::Run()
  {
    Solve();
  }

  void SudokuSolver::PrintSudoku() const
  {
    for(char i=0; i<9; i++)
    {
      for(char j=0; j<9; j++)
        std::cout << (int)sudoku[i][j]+1 << ' ';

      std::cout << '\n';
    }

    std::cout << '\n';
  }

  Sudoku* SudokuSolver::GetSudoku() const
  {
    char tab[9][9];
    for(char i=0; i<9; i++)
      for(char j=0; j<9; j++)
        tab[i][j] = this->sudoku[i][j]+1;

    Sudoku* sudoku = new Sudoku(tab);

    return sudoku;
  }

// Private:
  bool SudokuSolver::Solve(Coord startCoord /*= {0, 0} */)
  {
    Coord coord = FindUnset(startCoord); // Find first, unset value on the board
    if(coord.row < 0) // The end of the board was reached (success)
      return true;

    // There are blank fields needed to be filled. So possible
    // (impossible) numbers to fill these blank fields should be found.
    std::bitset<9> impossibleNums;
    impossibleNums |= rows[coord.row];
    impossibleNums |= cols[coord.col];
    impossibleNums |= grids[GetGrid(coord.row, coord.col)];

    for(char i=0; i<9; i++)
    {
      if(impossibleNums.test(i)) continue;

      // Sudoku can be filled with the value 'i' in the 'coord' position
      sudoku[coord.row][coord.col] = i;
      rows[coord.row].set(i);
      cols[coord.col].set(i);
      grids[GetGrid(coord.row, coord.col)].set(i);

      // And the Solve function can be called to solve for the next position
      if(Solve(coord))
      { // Sudoku was successfully solved
        return true;
      }
      else
      { // SudokuSolver assumption was incorrect.
        // The assumed number for this iteration was incorrect. It's value
        // was 'i'. The assumptions should be took back and next possible
        // value should be found (if possible).

        // Revocation of the assumptions
        sudoku[coord.row][coord.col] = -1;
        rows[coord.row].reset(i);
        cols[coord.col].reset(i);
        grids[GetGrid(coord.row, coord.col)].reset(i);
      }

      // Finding the next possible number in the next iteration of
      // the for loop.
    }

    // It is not possible to complete the field. The earlier assumptions
    // were incorrect.
    return false;
  }

  SudokuSolver::Coord SudokuSolver::FindUnset(Coord startCoord /*= {0, 0} */) const
  {
    // Completing search in the given row
    for(char i=startCoord.col; i<9; i++)
      if(sudoku[startCoord.row][i]<0)
        return {startCoord.row, i};

    // Searching sequentially in the following rows
    for(char i=startCoord.row+1; i<9; i++)
      for(char j=0; j<9; j++)
        if(sudoku[i][j]<0)
          return {i, j};

    return {-1, -1}; // The end of the board was reached (success)
  }

  void SudokuSolver::InitBitset()
  {
    // Initialization of bit fields holding information about
    // unfinished numbers in rows, columns, and grids
    for(char i=0; i<9; i++)
      for(char j=0; j<9; j++)
      {
        if(sudoku[i][j] >= 0)
        {
          rows[i].set(sudoku[i][j]);
          cols[j].set(sudoku[i][j]);
          grids[GetGrid(i, j)].set(sudoku[i][j]);
        }
      }
  }

  inline char SudokuSolver::GetGrid(char row, char col) const
  {
    return 3*(row/3) + col/3;
  }
