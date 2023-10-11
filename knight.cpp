#include "knight.h"
#include "square.h"
#include "game.h"
#include "move.h"
#include "player.h"
#include <set>

const char* Knight::NAME = "Knight";

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
	

	if (upTwoLeftOne != nullptr )
		moves.insert(upTwoLeftOne);

	if (upOneLeftTwo != nullptr )
		moves.insert(upOneLeftTwo);

	if (downTwoLeftOne != nullptr)
		moves.insert(downTwoLeftOne);

	if (downOneLeftTwo != nullptr )
		moves.insert(downOneLeftTwo);

	if (upTwoRightOne != nullptr)
		moves.insert(upTwoRightOne);

	if (upOneRightTwo != nullptr)
		moves.insert(upOneRightTwo);

	if (downTwoRightOne != nullptr)
		moves.insert(downTwoRightOne);

	if (downOneRightTwo != nullptr)
		moves.insert(downOneRightTwo);


	return moves;
}