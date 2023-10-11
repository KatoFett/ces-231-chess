#include "queen.h"
#include "square.h"
#include "game.h"
#include <set>

using namespace std;

const char* Queen::NAME = "QUEEN";

set<Square*> Queen::getMoves() const
{
		/*
		{ -1,  1}, {  0,  1}, {  1,  1},
		{ -1,  0},            {  1,  0},
		{ -1, -1}, {  0, -1}, {  1, -1}
	*/

		set<Square*> moves;
		Board board = Game::getInstance().getBoard();
		Direction direction = player.getDirection();

		Square* upRight = board.getSquare(square->getRow() + 1, square->getCol() + 1);
		Square* upLeft = board.getSquare(square->getRow() - 1, square->getCol() + 1);
		Square* downRight = board.getSquare(square->getRow() + 1, square->getCol() - 1);
		Square* downLeft = board.getSquare(square->getRow() - 1, square->getCol() - 1);

		Square* up = square->getUp(direction);
		Square* left = square->getLeft(direction);
		Square* down = square->getDown(direction);
		Square* right = square->getRight(direction);

		while (upRight != nullptr && upRight->getPiece() == nullptr)
		{
				moves.insert(upRight);
				upRight = board.getSquare(upRight->getRow() + 1, upRight->getCol() + 1);
		}

		while (upLeft != nullptr && upLeft->getPiece() == nullptr)
		{
				moves.insert(upLeft);
				upLeft = board.getSquare(upLeft->getRow() - 1, upLeft->getCol() + 1);
		}

		while (downRight != nullptr && downRight->getPiece() == nullptr)
		{
				moves.insert(downRight);
				downRight = board.getSquare(downRight->getRow() + 1, downRight->getCol() + 1);
		}

		while (downLeft != nullptr && downLeft->getPiece() == nullptr)
		{
				moves.insert(downLeft);
				downLeft = board.getSquare(downLeft->getRow() - 1, downLeft->getCol() + 1);
		}

		while (up != nullptr && up->getPiece() == nullptr)
		{
				moves.insert(up);
				up = square->getUp(direction);
		}

		while (down != nullptr && down->getPiece() == nullptr)
		{
				moves.insert(down);
				down = square->getDown(direction);
		}

		while (left != nullptr && left->getPiece() == nullptr)
		{
				moves.insert(left);
				left = square->getLeft(direction);
		}

		while (right != nullptr && right->getPiece() == nullptr)
		{
				moves.insert(right);
				right = square->getRight(direction);
		}

		return moves;
   return set<Square*>();
}