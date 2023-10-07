#include "testKing.h"
#include "square.h"
#include "game.h"
#include "king.h"
#include "pawn.h"
#include "queen.h"
#include <cassert>
#include <vector>

using namespace std;

bool containsSquare(vector<Square>& squares, const char* square) {
	for (Square& element : squares) {
		if (element.getNotation() == square) {
			return true;
		}
	}

	return false;
}

bool squaresMatch(vector<Square>& squares1, const char* squares2[], int moveLength) {
	if (squares1.size() != moveLength) {
		return false;
	}

	for (int i = 0; i < moveLength; i++)
	{
		if (!containsSquare(squares1, squares2[i])) {
			return false;
		}
	}

	return true;
}


void testKing::testKingPieceinFront()
{
	//Set Up
	Game game;
	game.initDefault(false);
	Board board = game.getBoard();
	Player player = game.getPlayer(0);


	King king(board["D1", player]);
	Pawn Pawn(board["D2", player]);

	//Exercise
	set<Square> moves = king.getMoves();


	//Verify
	assert(moves.size() == 4);


	//Tear down
}

void testKing::testKingGetCastelMoves()
{

}

void testKing::testKingMove()
{
	//Set Up
	Game game;
	game.initDefault(false);
	Board board = game.getBoard();
	Player player = game.getPlayer(0);


	King king(board["D2", player]);

	//Exercise
	set<Square> moves = king.getMoves();


	//Verify
	assert(moves.size() == 8);


	//Tear down
}

void testKing::testKingPieceGetMoves()
{

}