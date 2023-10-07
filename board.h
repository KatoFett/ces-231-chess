#pragma once

#include "testGame.h"
#include "square.h"
#include <vector>

using namespace std;

class Board
{
   friend TestGame;

private:
   vector<vector<Square*>> squares;

public:
   Board() :
      squares()
   {}

   void addSquare(int row, Square* square);
   Square* getSquare(int row, int col);
};