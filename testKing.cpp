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
	testKingGetCastleMoves();
	testKingGetMoves();
}

void TestKing::testKingInFront()
{
	//Set Up
	Game game;
	game.initDefault(false);
	Board board = game.getBoard();
	Player player = game.getPlayer(0);


	King king(*board["d1"], player);
	Pawn Pawn(*board["d2"], player);

	//Exercise
	set<Square> moves = king.getMoves();


	//Verify
	assert(moves.size() == 4);


	//Tear down
}

void TestKing::testKingGetCastleMoves()
{
	//Set Up
	Game game;
	game.initDefault(false);
	Board board = game.getBoard();
	Player player = game.getPlayer(0);


	King king(*board["d1"], player);
	Rook rook(*board["a1"], player);

	//Exercise
	set<Square> moves = king.getCastleMoves();


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


	King king(*board["d2"], player);


	//Exercise
	set<Square> moves = king.getMoves();


	//Verify
	assert(moves.size() == 8);


	//Tear down
}

void TestKing::testKingGetMoves()
{
	//Set Up
	Game game;
	game.initDefault(false);
	Board board = game.getBoard();
	Player player = game.getPlayer(0);


	King king(*board["d1"], player);
	Pawn pawn1(*board["c1"], player);
	Pawn pawn2(*board["c2"], player);
	Pawn pawn3(*board["e2"], player);


	//Exercise
	set<Square> moves = king.getMoves();


	//Verify
	assert(moves.size() == 2);


	//Tear down
}