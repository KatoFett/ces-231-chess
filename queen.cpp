#include "queen.h"
#include "square.h"
#include "bishop.h"
#include "rook.h"
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

		Board board = Game::getInstance().getBoard();
		Direction direction = player.getDirection();

		set<Square*> moves = Bishop::getBishopMoves(this->square);
		set<Square*> rookMoves = Rook::getRookMoves(this->square);

		
		for (Square* move : rookMoves)
		{
				moves.insert(move);
		}


		return moves;
}