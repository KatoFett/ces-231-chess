#include "rook.h"
#include "game.h"
#include  "board.h"
#include "square.h"
#include <set>

using namespace std;

const char Rook::NAME = 'R';

set<Square*> Rook::getRookMoves(Square* square)
{
	/*
			{0,1}
	   {-1,0} R {1,0}
			{0,-1}
	*/

	set<Square*> moves;
	int deltas[][2] = {
			{0,1},
			{0,-1},
			{-1,0},
			{1,0}
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
				 destination = nullptr;
			}
		}
	}

	return moves;


}
