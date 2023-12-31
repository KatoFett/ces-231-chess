#include "knight.h"
#include "square.h"
#include "game.h"
#include "move.h"
#include "player.h"
#include <set>

const char Knight::NAME = 'N';

/*
* GET MOVES
* Returns all the possible moves for this instance of a knight.
*/
set<Square*> Knight::getMoves() const
{
   /*
            {-1,  2},  {1,  2},
      {-2,  1},			     {2,  1},


      {-2,  -1},				 {2,  -1},

            {-1, -2},	{1, -2}
   */

   set<Square*> moves;

   // All possible squares
   int deltas[][2] = {
      {-1,  2},
      { 1,  2},
      {-1, -2},
      { 1, -2},
      {-2,  1},
      { 2,  1},
      {-2, -1},
      { 2, -1},
   };

   for (int* delta : deltas)
   {
      int row = *delta;
      int col = *(delta + 1);
      Square* destination = square->getAdjacent(row, col);
      if (canMoveToSquare(player, destination)) moves.insert(destination);
   }

   return moves;
}