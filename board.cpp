#pragma once

#include "board.h"
#include "square.h"
#include <string>

Square* Board::operator[](const char* notation) const
{
   if (strlen(notation) != 2) throw "Invalid notation.";

   int col = notation[0] - 97;
   if (col < 0 || col >= width) throw "Column does not exist.";

   int row = notation[1] - 49;
   if (row < 0 || row >= height) throw "Row does not exist.";

   int index = getIndexFromRowCol(row, col);

   return squares[index];
}

void Board::addSquare(Square* square)
{
   squares[squareCount] = square;
   square->setIndex(squareCount++);
}

Square* Board::getSquare(int row, int col) const
{
   if (row < 0 || row >= width) return nullptr;
   if (col < 0 || col >= height) return nullptr;

   int index = getIndexFromRowCol(row, col);
   
   return squares[index];
}