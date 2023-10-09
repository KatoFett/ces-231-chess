#pragma once

#include "board.h"
#include "square.h"
#include <string>

Square* Board::operator[](const char* notation) const
{
   if (strlen(notation) != 2) throw "Invalid notation.";

   int col = notation[0] - 97;
   if (col < 0 || col > squares.size()) throw "Column does not exist.";

   int row = notation[1] - 49;
   if (row < 0 || row > squares[col].size()) throw "Row does not exist.";

   return squares[row][col];
}

void Board::addSquare(int row, Square* square)
{
   if (row > squares.size())
      throw "Skipped one or more rows while initializing squares.";

   if (row == squares.size())
      squares.push_back(vector<Square*>());

   square->setIndex(squareCount++);

   squares[row].push_back(square);
}

Square* Board::getSquare(int row, int col) const
{
   if (row < 0 || row >= squares.size()) return nullptr;
   if (col < 0 || col >= squares[row].size()) return nullptr;

   return squares[row][col];
}