#include "king.h"
#include "square.h"
#include "game.h"
#include "move.h"
#include "rook.h"
#include "player.h"
#include <set>

const char* King::NAME = "KING";

set<Square*> King::getMoves() const
{
	/*
		{-1,  1}, {0,  1},  {1,  1},
		{-1,  0},          {1,  0},
		{-1, -1}, {0, -1}, {1, -1}
	*/

	set<Square*> moves;
	Direction direction = player.getDirection();
	Square* oneAhead = square->getUp(direction);
	Square* oneBack = square->getDown(direction);
	Square* oneLeft = square->getLeft(direction);
	Square* oneRight = square->getRight(direction);

	//[0,1]
	if (oneAhead != nullptr && oneAhead->getPiece() == nullptr)
	{
		moves.insert(oneAhead);
		//[-1,1]
		if (oneAhead->getLeft(direction) != nullptr && oneAhead->getLeft(direction)->getPiece() == nullptr)
			moves.insert(oneAhead->getLeft(direction));
		//[1,1]
		if (oneAhead->getRight(direction) != nullptr && oneAhead->getRight(direction)->getPiece() == nullptr)
			moves.insert(oneAhead->getRight(direction));
	}
	//[0,-1]
	if (oneBack != nullptr && oneBack->getPiece() == nullptr)
	{
		moves.insert(oneBack);
		//[-1,-1]
		if (oneBack->getLeft(direction) != nullptr && oneBack->getLeft(direction)->getPiece() == nullptr)
			moves.insert(oneBack->getLeft(direction));
		//[1,-1]
		if (oneBack->getRight(direction) != nullptr && oneBack->getRight(direction)->getPiece() == nullptr)
			moves.insert(oneBack->getRight(direction));
	}
	//[-1,0]
	if (oneLeft != nullptr && oneLeft->getPiece() == nullptr)
	{
		moves.insert(oneLeft);
		if (oneLeft->getDown(direction) != nullptr && oneLeft->getDown(direction)->getPiece() == nullptr && !(oneBack != nullptr && oneBack->getPiece() == nullptr))
		{
			//[-1,-1]
			moves.insert(oneLeft->getDown(direction));
		}
		//[-1,1]
		if (oneLeft->getUp(direction) != nullptr && oneLeft->getUp(direction)->getPiece() == nullptr && !(oneAhead != nullptr && oneAhead->getPiece() == nullptr))
			moves.insert(oneLeft->getUp(direction));
	}
	//[1,0]
	if (oneRight != nullptr && oneRight->getPiece() == nullptr)
	{
		moves.insert(oneRight);
		//[-1,-1]
		if (oneRight->getDown(direction) != nullptr && oneRight->getDown(direction)->getPiece() == nullptr && !(oneBack != nullptr && oneBack->getPiece() == nullptr))
			moves.insert(oneRight->getDown(direction));
		//[1,1]
		if (oneRight->getUp(direction) != nullptr && oneRight->getUp(direction)->getPiece() == nullptr && !(oneAhead != nullptr && oneAhead->getPiece() == nullptr))
			moves.insert(oneRight->getUp(direction));
	}

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
			moves.insert(rookSquare);
		}

		// Check right rook.
		rookSquare = square->getRight(direction);
		while (rookSquare != nullptr && rookSquare->getPiece() == nullptr)
		{
			rookSquare = rookSquare->getRight(direction);
		}

		if (rookSquare != nullptr && rookSquare->getPiece()->getName() == Rook::NAME && !rookSquare->getPiece()->getHasMoved())
		{
			moves.insert(rookSquare);
		}
	}

	return moves;
}

