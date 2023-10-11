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

		// All the diagonal moves.
		Square* upRight = board.getSquare(square->getRow() + 1, square->getCol() + 1);
		Square* upLeft = board.getSquare(square->getRow() - 1, square->getCol() + 1);
		Square* downRight = board.getSquare(square->getRow() + 1, square->getCol() - 1);
		Square* downLeft = board.getSquare(square->getRow() - 1, square->getCol() - 1);

		// All the straight moves.
		Square* up = square->getUp(direction);
		Square* left = square->getLeft(direction);
		Square* down = square->getDown(direction);
		Square* right = square->getRight(direction);

		/****************************************************************************************
		* Until we reach the edge of the board, or hit another peice, add the moves to the list.
		* After we add the move, increment to the next spot for the respective move.
		****************************************************************************************/
		while (upRight != nullptr && upRight->getPiece() == nullptr)
		{
				moves.insert(upRight);
				upRight = board.getSquare(upRight->getRow() + 1, upRight->getCol() + 1);
		}
		
		// If the color of my piece is diffrent from the piece on the square im moving to, we can move there.
		if (upRight != nullptr && player.getColor() != upRight->getPiece()->getPlayer().getColor())
		{
				moves.insert(upRight);
		}

		while (upLeft != nullptr && upLeft->getPiece() == nullptr)
		{
				moves.insert(upLeft);
				upLeft = board.getSquare(upLeft->getRow() - 1, upLeft->getCol() + 1);
		}

		// If the color of my piece is diffrent from the piece on the square im moving to, we can move there.
		if (upLeft != nullptr && player.getColor() != upLeft->getPiece()->getPlayer().getColor())
		{
				moves.insert(upLeft);
		}

		while (downRight != nullptr && downRight->getPiece() == nullptr)
		{
				moves.insert(downRight);
				downRight = board.getSquare(downRight->getRow() + 1, downRight->getCol() + 1);
		}

		// If the color of my piece is diffrent from the piece on the square im moving to, we can move there.
		if (downRight != nullptr && player.getColor() != downRight->getPiece()->getPlayer().getColor())
		{
				moves.insert(downRight);
		}

		while (downLeft != nullptr && downLeft->getPiece() == nullptr)
		{
				moves.insert(downLeft);
				downLeft = board.getSquare(downLeft->getRow() - 1, downLeft->getCol() + 1);
		}

		// If the color of my piece is diffrent from the piece on the square im moving to, we can move there.
		if (downLeft != nullptr && player.getColor() != downLeft->getPiece()->getPlayer().getColor())
		{
				moves.insert(downLeft);
		}

		while (up != nullptr && up->getPiece() == nullptr)
		{
				moves.insert(up);
				up = square->getUp(direction);
		}

		// If the color of my piece is diffrent from the piece on the square im moving to, we can move there.
		if (up != nullptr && player.getColor() != up->getPiece()->getPlayer().getColor())
		{
				moves.insert(up);
		}

		while (down != nullptr && down->getPiece() == nullptr)
		{
				moves.insert(down);
				down = square->getDown(direction);
		}

		// If the color of my piece is diffrent from the piece on the square im moving to, we can move there.
		if (down != nullptr && player.getColor() != down->getPiece()->getPlayer().getColor())
		{
				moves.insert(down);
		}

		while (left != nullptr && left->getPiece() == nullptr)
		{
				moves.insert(left);
				left = square->getLeft(direction);
		}

		// If the color of my piece is diffrent from the piece on the square im moving to, we can move there.
		if (left != nullptr && player.getColor() != left->getPiece()->getPlayer().getColor())
		{
				moves.insert(left);
		}

		while (right != nullptr && right->getPiece() == nullptr)
		{
				moves.insert(right);
				right = square->getRight(direction);
		}

		// If the color of my piece is diffrent from the piece on the square im moving to, we can move there.
		if (right != nullptr && player.getColor() != right->getPiece()->getPlayer().getColor())
		{
				moves.insert(right);
		}

		return moves;
}