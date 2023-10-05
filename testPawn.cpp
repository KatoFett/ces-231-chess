#include "testPawn.h"
#include "square.h"
#include "game.h"
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
class TestPawn {

	void TestPawn::testgetEnEnpassantMove() {
		//8 | _ | # | _ | # | _ | # | _ | # |
		//7 | # | P | # | _ | # | _ | # | _ |
		//6 | _ | # | _ | P | _ | # | _ | # |
		//5 | # | _ | p | _ | # | _ | # | _ |
		//4 | _ | # | _ | # | _ | # | _ | # |
		//3 | # | _ | # | _ | # | _ | # | _ |
		//2 | _ | # | - | # | _ | # | _ | # |
		//1 | # | _ | # | _ | # | _ | # | _ |
		//	  a   b   c   d  e    f   g   h
	//Set Up
		Game game;
		game.initDefault(false);
		Board board = game.getBoard();
		Player player1 = game.getPlayer(0);
		Player player2 = game.getPlayer(1);

		Pawn pawnWhite1(board["c4", player1]);
		Pawn pawnBlack1(board["d6", player2]);
		Pawn pawnBlack2(board["b7", player2]);

		// Set current player to black.
		game.setSelectedPiece(pawnWhite1);
		game.move(board["c5"]);

		// Move black pawn.
		game.setSelectedPiece(pawnBlack1);
		game.move(board["b5"]);

		//Exercise
		Square* square = pawnWhite1.getEnPassantMove();

		//Verify

		assert(square != nullptr);
		assert(square->getNotation() == "B6");



		//Tear down
	}

	void TestPawn::testPawnPieceInFront() {

		//8 | _ | # | _ | # | _ | # | _ | # |
		//7 | # | _ | # | _ | # | _ | # | _ |
		//6 | _ | # | _ | # | _ | # | _ | # |
		//5 | # | _ | # | _ | # | _ | # | _ |
		//4 | _ | # | _ | # | _ | # | _ | # |
		//3 | # | _ | P | _ | # | _ | # | _ |
		//2 | _ | # | p | # | _ | # | _ | # |
		//1 | # | _ | # | _ | # | _ | # | _ |
		//	  a   b   c   d  e    f   g   h
	//Set Up
		Game game;
		game.initDefault(false);
		Board board = game.getBoard();
		Player player = game.getPlayer(0);
		Player player2 = game.getPlayer(1);

		Pawn pawn(board["c2", player]);
		Pawn blackPawn(board["c3", player2]);

		//Exercise
		vector<Square> moves = pawn.getMoves();


		//Verify
		assert(moves.size() == 0);


		//Tear down
	}
	void TestPawn::testPawnPromte() {
		//8 | _ | # | p | # | _ | # | _ | # |
		//7 | # | _ | # | _ | # | _ | # | _ |
		//6 | _ | # | _ | # | _ | # | _ | # |
		//5 | # | _ | # | _ | # | _ | # | _ |
		//4 | _ | # | _ | # | _ | # | _ | # |
		//3 | # | _ | # | _ | # | _ | # | _ |
		//2 | _ | # | - | # | _ | # | _ | # |
		//1 | # | _ | # | _ | # | _ | # | _ |
		//	  a   b   c   d  e    f   g   h
	//Set Up
		Game game;
		game.initDefault(false);
		Board board = game.getBoard();
		Player player = game.getPlayer(0);
		Pawn pawn(board["c8", player]);
		Queen queen;
		//Exercise

		pawn.promote(queen);

		//Verify
		assert(queen.getSquare().getNotation() == "c8");

		//Tear down
	}
	void TestPawn::testPawnPieceOneMove() {

		//8 | _ | # | _ | # | _ | # | _ | # |
		//7 | # | _ | # | _ | # | _ | # | _ |
		//6 | _ | # | _ | # | _ | # | _ | # |
		//5 | # | _ | # | _ | # | _ | # | _ |
		//4 | _ | # | P | # | _ | # | _ | # |
		//3 | # | _ | # | _ | # | _ | # | _ |
		//2 | _ | # | p | # | _ | # | _ | # |
		//1 | # | _ | # | _ | # | _ | # | _ |
		//	  a   b   c   d  e    f   g   h
	//Set Up
		Game game;
		game.initDefault(false);
		Board board = game.getBoard();
		Player player = game.getPlayer(0);
		Player player2 = game.getPlayer(1);

		Pawn pawn(board["c2", player]);
		Pawn blackPawn(board["c4", player2]);

		//Exercise
		vector<Square> moves = pawn.getMoves();


		//Verify
		char* correctMoves[] = { "c3" };
		assert(squaresMatch(moves, correctMoves, 1));

		//Tear down
	}
	void TestPawn::testPawnPieceGetMoves() {
		//8 | _ | # | _ | # | _ | # | _ | # |
		//7 | # | _ | # | _ | # | _ | # | _ |
		//6 | _ | # | _ | # | _ | # | _ | # |
		//5 | # | _ | # | _ | # | _ | # | _ |
		//4 | _ | # | _ | # | _ | # | _ | # |
		//3 | # | _ | # | _ | # | _ | # | _ |
		//2 | _ | # | p | # | _ | # | _ | # |
		//1 | # | _ | # | _ | # | _ | # | _ |
		//	  a   b   c   d  e    f   g   h
	//Set Up
		Game game;
		game.initDefault(false);
		Board board = game.getBoard();
		Player player = game.getPlayer(0);
		Pawn pawn(board["c2", player]);

		//Exercise
		vector<Square> moves = pawn.getMoves();


		//Verify
		char* correctMoves[] = { "c3","c4" };
		assert(squaresMatch(moves, correctMoves, 2));

		//Tear down
	}

};
