#include "king.h"
#include "square.h"
#include "game.h"
#include "move.h"
#include "rook.h"
#include "player.h"
#include <set>

const char* King::NAME = "KING";

set<Square> King::getMoves() const
{
	/*
		{-1,  1}, {0,  1},  {1,  1},
		{-1,  0},          {1,  0},
		{-1, -1}, {0, -1}, {1, -1}
	*/

	set<Square> moves;
	Direction direction = player.getDirection();
	Square* oneAhead = square.getUp(direction);
	Square* oneBack = square.getDown(direction);
	Square* oneLeft = square.getLeft(direction);
	Square* oneRight = square.getRight(direction);

	//[0,1]
	if (oneAhead != nullptr && oneAhead->getPiece() == nullptr)
		moves.insert(*oneAhead);
	//[-1,1]
	if (oneAhead->getLeft(direction)->getPiece() == nullptr)
		moves.insert(*oneAhead->getLeft(direction));
	//[1,1]
	if (oneAhead->getRight(direction)->getPiece() == nullptr)
		moves.insert(*oneAhead->getRight(direction));
	//[0,-1]
	if (oneBack->getPiece() == nullptr)
		moves.insert(*oneBack);
	//[-1,-1]
	if (oneBack->getLeft(direction)->getPiece() == nullptr)
		moves.insert(*oneBack->getLeft(direction));
	//[1,-1]
	if (oneBack->getRight(direction)->getPiece() == nullptr)
		moves.insert(*oneBack->getRight(direction));
	//[-1,0]
	if (oneLeft->getPiece() == nullptr)
		moves.insert(*oneLeft);
	//[1,0]
	if (oneRight->getPiece() == nullptr)
		moves.insert(*oneRight);

	return moves;
}

set<Square> King::getCastleMoves() const
{
	set<Square> moves;
	Direction direction = player.getDirection();

	if (!hasMoved)
	{
		// Check left rook.
		Square* rookSquare = square.getLeft(direction);
		while (rookSquare != nullptr && rookSquare->getPiece() == nullptr)
		{
			rookSquare = square.getLeft(direction);
		}

		if (rookSquare != nullptr && rookSquare->getPiece()->getName() == Rook::NAME && !rookSquare->getPiece()->getHasMoved())
		{
			moves.insert(*rookSquare);
		}

		// Check right rook.
		rookSquare = square.getRight(direction);
		while (rookSquare != nullptr && rookSquare->getPiece() == nullptr)
		{
			rookSquare = square.getRight(direction);
		}

		if (rookSquare != nullptr && rookSquare->getPiece()->getName() == Rook::NAME && !rookSquare->getPiece()->getHasMoved())
		{
			moves.insert(*rookSquare);
		}
	}

	return moves;
}

