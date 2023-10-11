#include "bishop.h"
#include "square.h"
#include "game.h"
#include <iostream>
#include <set>

using namespace std;

const char* Bishop::NAME = "BISHOP";

set<Square*> Bishop::getMoves() const
{
	 /*
	 { -1,  1}, {  1,  1}
	 { -1, -1}, { -1, -1}
	 */

	 set<Square*> moves;
	 Board board = Game::getInstance().getBoard();
	 Direction direction = player.getDirection();

	 // All diagonal moves.
	 Square* upRight = board.getSquare(square->getRow() + 1, square->getCol() + 1);
	 Square* upLeft = board.getSquare(square->getRow() - 1, square->getCol() + 1);
	 Square* downRight = board.getSquare(square->getRow() + 1, square->getCol() - 1);
	 Square* downLeft = board.getSquare(square->getRow() - 1, square->getCol() - 1);

	 /*********************************************************
	 * Until we hit another piece or the edge of the board, the move is possible.
	 * Accounts for all possible directions for the bishop.
	 * After adding the move, increment to the next move in the direction.
	 **********************************************************/
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

	 return moves;


}
