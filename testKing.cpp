#include "testKing.h"
#include "square.h"
#include "game.h"
#include "king.h"
#include "player.h"
#include "pawn.h"
#include "rook.h"
#include <cassert>
#include <vector>

using namespace std;

void TestKing::run()
{
	testKingInFront();
	testKingGetCastleMoves();
	testKingMove();
	testKingGetMoves();
}

void TestKing::testKingInFront()
{
	//Set Up
	Game game;
	game.initDefault(false);
	Board board = game.getBoard();
	Player player = game.getPlayer(0);


	Pawn Pawn(board["d2"], player);
	King king(board["d1"], player);

	//Exercise
	set<Square*> moves = king.getMoves();


	//Verify
	assert(moves.size() == 4); //Pawn blocks the 5th


	//Tear down
}

void TestKing::testKingGetCastleMoves()
{
	//Set Up
	Game game;
	game.initDefault(false);
	Board board = game.getBoard();
	Player player = game.getPlayer(0);


	Rook rook(board["a1"], player);
	King king(board["d1"], player);

	//Exercise
	set<Square*> moves = king.getMoves();


	//Verify
	assert(king.getHasMoved() == false);
	assert(rook.getHasMoved() == false);
	assert(moves.size() == 6); //5 for around the king, 1 for the castle;
}

void TestKing::testKingMove()
{
	//Set Up
	Game game;
	game.initDefault(false);
	Board board = game.getBoard();
	Player player = game.getPlayer(0);


	King king(board["d2"], player);
	string startLocation = king.getSquare()->getNotation();

	game.setSelectedPiece(&king);


	//Exercise
	game.move(board["d3"]);


	//Verify
	assert(startLocation == "d2"); //Start location.
	assert(king.getSquare()->getNotation() == "d3"); //End location.


	//Tear down
}

void TestKing::testKingGetMoves()
{
	//Set Up
	Game game;
	game.initDefault(false);
	Board board = game.getBoard();
	Player player = game.getPlayer(0);


	King king(board["d1"], player);
	Pawn pawn1(board["c1"], player);
	Pawn pawn2(board["c2"], player);
	Pawn pawn3(board["e2"], player);


	//Exercise
	set<Square*> moves = king.getMoves();


	//Verify
	assert(moves.size() == 2); //Only open moves with all the pawns.


	//Tear down
}