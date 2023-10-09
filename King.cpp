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
	Board board = Game::getInstance().getBoard();
	Direction direction = player.getDirection();
	Square* oneAhead = square->getUp(direction);
	Square* topLeft = board.getSquare(square->getRow() + 1, square->getCol() - 1);
	Square* topRight = board.getSquare(square->getRow() + 1, square->getCol() + 1);
	Square* oneBack = square->getDown(direction);
	Square* bottomLeft = board.getSquare(square->getRow() - 1, square->getCol() - 1);
	Square* bottomRight = board.getSquare(square->getRow() - 1, square->getCol() + 1);
	Square* oneLeft = square->getLeft(direction);
	Square* oneRight = square->getRight(direction);

	//[0,1]
	if (oneAhead != nullptr && oneAhead->getPiece() == nullptr)
		moves.insert(oneAhead);

	 //[-1,1]
	 if (topLeft != nullptr && topLeft->getPiece() == nullptr)
		  moves.insert(topLeft);

	 //[1,1]
	 if (topRight != nullptr && topRight->getPiece() == nullptr)
		  moves.insert(topRight);
	
	//[0,-1]
	if (oneBack != nullptr && oneBack->getPiece() == nullptr)
		moves.insert(oneBack);
	
	 //[-1,-1]
	 if (bottomLeft != nullptr && bottomLeft->getPiece() == nullptr)
		  moves.insert(bottomLeft);

	 //[1,-1]
	 if (bottomRight != nullptr && bottomRight->getPiece() == nullptr)
		  moves.insert(bottomRight);
	
	//[-1,0]
	if (oneLeft != nullptr && oneLeft->getPiece() == nullptr)
		moves.insert(oneLeft);
	
	//[1,0]
	if (oneRight != nullptr && oneRight->getPiece() == nullptr)
		moves.insert(oneRight);

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

