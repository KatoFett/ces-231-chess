#include "knight.h"
#include "square.h"
#include "game.h"
#include "move.h"
#include "player.h"
#include <set>

const char Knight::NAME = 'N';

set<Square*> Knight::getMoves() const
{
	/*
				{-1,  2},  {1,  2},
		{-2,  1},			     {2,  1},
		

		{-2,  -1},				 {2,  -1},
		
				{-1, -2},	{1, -2}
	*/

	set<Square*> moves;
	Board board = Game::getInstance().getBoard();
	Direction direction = player.getDirection();

	Square* upTwoLeftOne = board.getSquare(square->getRow() + 2, square->getCol() - 1);
	Square* upOneLeftTwo = board.getSquare(square->getRow() + 1, square->getCol() - 2);

	Square* downTwoLeftOne = board.getSquare(square->getRow() - 2, square->getCol() - 1);
	Square* downOneLeftTwo = board.getSquare(square->getRow() - 1, square->getCol() - 2);

	Square* upTwoRightOne = board.getSquare(square->getRow() + 2, square->getCol() + 1);
	Square* upOneRightTwo = board.getSquare(square->getRow() + 1, square->getCol() + 2);

	Square* downTwoRightOne = board.getSquare(square->getRow() - 2, square->getCol() + 1);
	Square* downOneRightTwo = board.getSquare(square->getRow() - 1, square->getCol() + 2);
	

	if (upTwoLeftOne != nullptr  && upTwoLeftOne->getPiece()->getPlayer().getColor() != player.getColor())
		moves.insert(upTwoLeftOne);

	if (upOneLeftTwo != nullptr && upOneLeftTwo->getPiece()->getPlayer().getColor() != player.getColor())
		moves.insert(upOneLeftTwo);

	if (downTwoLeftOne != nullptr && downTwoLeftOne->getPiece()->getPlayer().getColor() != player.getColor())
		moves.insert(downTwoLeftOne);

	if (downOneLeftTwo != nullptr && downOneLeftTwo->getPiece()->getPlayer().getColor() != player.getColor())
		moves.insert(downOneLeftTwo);

	if (upTwoRightOne != nullptr && upTwoRightOne->getPiece()->getPlayer().getColor() != player.getColor())
		moves.insert(upTwoRightOne);

	if (upOneRightTwo != nullptr && upOneRightTwo->getPiece()->getPlayer().getColor() != player.getColor())
		moves.insert(upOneRightTwo);

	if (downTwoRightOne != nullptr && downTwoRightOne->getPiece()->getPlayer().getColor() != player.getColor())
		moves.insert(downTwoRightOne);

	if (downOneRightTwo != nullptr && downOneRightTwo->getPiece()->getPlayer().getColor() != player.getColor())
		moves.insert(downOneRightTwo);


	return moves;
}