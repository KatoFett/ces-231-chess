#include "king.h"
#include "square.h"
#include "game.h"
#include "move.h"
#include "rook.h"
#include "player.h"
#include <set>

const char King::NAME = 'K';

set<Square*> King::getMoves() const
{
	/*
		{-1,  1}, {0,  1},  {1,  1},
		{-1,  0},          {1,  0},
		{-1, -1}, {0, -1}, {1, -1}
	*/

	set<Square*> moves;

	Player& player = square->getPiece()->getPlayer();


	int cols[] = { -1, 0, 1 };
	int rows[] = { -1, 0, 1 };
	for (int col : cols)
	{
		for (int row : rows)
		{
			Square* destination = square->getAdjacent(col, row);
			if (canMoveToSquare(player, destination)) moves.insert(destination);
		}
	}

	// This will give us moves if castling is possible.
	set<Square*> castleMoves = getCastleMoves();

	for each (Square* move in castleMoves)
	{
		moves.insert(move);
	}

	return moves;
}

set<Square*> King::getCastleMoves() const
{
	set<Square*> moves;
	Direction direction = player.getDirection();

	if (!hasMoved)
	{
		// Check left rook.
		Square* rookSquare = square->getLeft(direction);
		while (rookSquare != nullptr && rookSquare->getPiece() == nullptr)
		{
			rookSquare = rookSquare->getLeft(direction);
		}

		if (rookSquare != nullptr && rookSquare->getPiece()->getName() == Rook::NAME && !rookSquare->getPiece()->getHasMoved())
		{
			// This is where the king will end up.
			moves.insert(rookSquare->getRight(direction)->getRight(direction));
		}

		// Check right rook.
		rookSquare = square->getRight(direction);
		while (rookSquare != nullptr && rookSquare->getPiece() == nullptr)
		{
			rookSquare = rookSquare->getRight(direction);
		}

		if (rookSquare != nullptr && rookSquare->getPiece()->getName() == Rook::NAME && !rookSquare->getPiece()->getHasMoved())
		{
			//This is where the king will end up.
			moves.insert(rookSquare->getLeft(direction));
		}
	}

	return moves;
}

