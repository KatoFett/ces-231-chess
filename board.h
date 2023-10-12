#pragma once

#include "testGame.h"
#include <vector>

using namespace std;

class Square;

class Board
{
   friend TestGame;

private:
   vector<Square*> squares;   // Can't be an array because size is determined during runtime.
   int squareCount;
   int width;
   int height;

public:
   Board(int width, int height) :
      squares(width * height), squareCount(0), width(width), height(height)
   {}

   Square* operator [](const char* notation) const;
   Square* operator [](const int index) const;

   Square* getSquare(int row, int col) const;
   int getIndexFromRowCol(int row, int col) const { return row * width + col; }
   int getWidth() const { return width; }
   int getHeight()const { return height; }

   void addSquare(Square* square);
};