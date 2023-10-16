#pragma once

#include "testGame.h"
#include <vector>

using namespace std;

class Square;

/*
* BOARD
* The chess board.
*/
class Board
{
   friend TestGame;

private:
   vector<Square*> squares;   // Can't be an array because size is determined during runtime.
   int squareCount;           // Total number of squares, including null squares.
   int width;                 // Width of the board in squares.
   int height;                // Height of the board in squares.

public:
   // Constructors
   Board(int width, int height) :
      squares(width * height), squareCount(0), width(width), height(height)
   {}

   // Operators
   Square* operator [](const char* notation) const;   // Access a square by algebraic notation, e.g. B3.
   Square* operator [](const int index) const;        // Access a square by index.

   // Getters
   Square* getSquare(int row, int col) const;         // Gets a square from row and column. Allows out of range inputs and can return null.
   int getIndexFromRowCol(int row, int col) const { return row * width + col; }  // Translates row and column to index.
   int getWidth() const { return width; }
   int getHeight()const { return height; }

   // Operations
   void addSquare(Square* square);     // Appends a square to the internal list.
};