#include "board.h"
#include "square.h"

void Board::addSquare(int row, Square* square)
{
   if (row > squares.size())
      throw "Skipped one or more rows while initializing squares.";

   if (row == squares.size())
      squares.push_back(vector<Square*>());

   squares[row].push_back(square);
}