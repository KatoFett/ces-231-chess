#include <iostream>
#include "King.h"
#include "square.h"
#include "game.h"
#include "move.h"
#include "rook.h"
#include <set>


set<Square> King::getMoves()
{
	/*
		{-1, 1} ,{0, 1},{1, 1},
		{-1, 0},{1, 0},
		{-1, -1},{0, -1},{1, -1]
	*/


	set<Square> moves;
	Player* player;
	Square& oneAhead = square.getUp();
	Square& oneBack = square.getDown();
	Square& oneLeft = square.getLeft();
	Square& oneRight = square.getRight();

	//[0,1]
	if (oneAhead.getPiece() == nullptr)
		moves.insert(oneAhead);
	//[-1,1]
	if (oneAhead.getLeft().getPiece() == nullptr)
		moves.insert(oneAhead.getLeft());
	//[1,1]
	if (oneAhead.getRight().getPiece() == nullptr)
		moves.insert(oneAhead.getRight());
	//[0,-1]
	if (oneBack.getPiece() == nullptr)
		moves.insert(oneBack);
	//[-1,-1]
	if (oneBack.getLeft().getPiece() == nullptr)
		moves.insert(oneBack.getLeft());
	//[1,-1]
	if (oneBack.getRight().getPiece() == nullptr)
		moves.insert(oneBack.getRight());
	//[-1,0]
	if (oneLeft.getPiece() == nullptr)
		moves.insert(oneLeft);
	//[1,0]
	if (oneRight.getPiece() == nullptr)
		moves.insert(oneRight);

	return moves;
}

set<Square> King::getCastleMoves()
{
	set<Square> moves;

	Rook rook;

	if (!hasMoved)
	{
		// Check left rook.
		Square rookSquare = square.getLeft();
		while (rookSquare != nullptr && rookSquare.getPiece() == NULL)
		{
			rookSquare = square.getLeft();
		}

		if (rookSquare != nullptr && rookSquare.getPiece() == rook && !rook.getHasMoved())
		{
			moves.insert(rookSquare);
		}

		// Check right rook.
		rookSquare = square.getRight();
		while (rookSquare != nullptr && rookSquare.getPiece() == NULL)
		{
			rookSquare = square.getRight();
		}

		if (rookSquare != nullptr && rookSquare.getPiece() == rook && !rook.getHasMoved())
		{
			moves.insert(rookSquare);
		}

		return moves;
	}
}

