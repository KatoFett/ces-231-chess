#pragma once

#include "board.h"
#include "square.h"
#include <string>

/*
* NOTATION INDEXER
* Returns the square that is referred to by the provided notation (e.g. "A1")
* Does NOT allow out of bounds, is usually used for testing.
*/
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

/*
* INDEX INDEXER
* Returns the square at the provided index.
* Does NOT allow out of bounds.
*/
Square* Board::operator[](const int index) const
{
   return squares[index];
}

/*
* ADD SQUARE
* Appends the square to the internal list.
*/
void Board::addSquare(Square* square)
{
   squares[squareCount] = square;
   square->setIndex(squareCount++);
}

/*
* GET SQUARE
* Gets the square at the provided row and column.
* Allows for invalid inputs for robustness, and will return nullptr if the square doesn't exist.
*/
Square* Board::getSquare(int row, int col) const
{
   if (row < 0 || row >= width) return nullptr;
   if (col < 0 || col >= height) return nullptr;

   int index = getIndexFromRowCol(row, col);
   
   return squares[index];
}