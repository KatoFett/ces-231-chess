#include "bishop.h"
#include "square.h"
#include "game.h"
#include <iostream>
#include <set>

using namespace std;

const char Bishop::NAME = 'B';

/*
* This will gather all the moves for the bishop piece. 
* It will calculate the sliding of the bishop as well.
*/
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
					 if (destination->getPiece() == nullptr)
					 {
						  destination = destination->getAdjacent(row, col);
					 }
					 else
					 {
						 // This will stop the slide if we hit another players piece.
						  destination = nullptr;
					 }
			 }
	 }

	 return moves;


}
