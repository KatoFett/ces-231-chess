#include "bishop.h"
#include "square.h"
#include "game.h"
#include <iostream>
#include <set>

using namespace std;

const char Bishop::NAME = 'B';

set<Square*> Bishop::getBishopMoves(Square* square)
{
	 /*
	 { -1,  1}, {  1,  1}
	 { -1, -1}, { -1, -1}
	 */

	 set<Square*> moves;
	 int deltas[][2] = {
			 {-1,1},
			 {-1, -1},
			 {1,1},
			 {1,-1}
	 };

	 Player& player = square->getPiece()->getPlayer();


	 // For each possible move.
	 for (int* delta : deltas)
	 {
			 // Get the row and col.
			 int row = *delta;
			 int col = *(delta + 1);
			 Square* destination = square->getAdjacent(row, col);

			 // While we can move to the square.
			 while (canMoveToSquare(player, destination))
			 {
					 // Insert the move, then get the next square.
					 moves.insert(destination);
					 destination = destination->getAdjacent(row, col);
			 }
	 }

	 return moves;


}
