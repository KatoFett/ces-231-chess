#pragma once

#include "testGame.h"
#include <vector>

using namespace std;

class Square;

class Board
{
   friend TestGame;

private:
   vector<vector<Square*>> squares;
   int squareCount;

public:
   Board() :
      squares(), squareCount(0)
   {}

   Square* operator [](const char* notation) const;

   void addSquare(int row, Square* square);
   Square* getSquare(int row, int col) const;
};