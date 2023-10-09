#include "testPawn.h"
#include "square.h"
#include "game.h"
#include "pawn.h"
#include "queen.h"
#include "player.h"
#include <cassert>
#include <vector>
#include "testHelper.h"

using namespace std;

void TestPawn::run()
{
   testGetEnpassantMove();
   testPawnInFront();
   testPawnPromote();
   testPawnOneMove();
   testPawnGetMoves();
}

void TestPawn::testGetEnpassantMove()
{
   //Set Up
   Game game;
   game.initDefault(false);
   Board& board = game.getBoard();
   Player& player1 = game.getPlayer(0);
   Player& player2 = game.getPlayer(1);

   Pawn pawnWhite1(board["c4"], player1);
   Pawn pawnBlack1(board["d6"], player2);
   Pawn pawnBlack2(board["b7"], player2);

   // Set current player to black.
   game.setSelectedPiece(&pawnWhite1);
   game.move(board["c5"]);

   // Move black pawn.
   game.setSelectedPiece(&pawnBlack2);
   game.move(board["b5"]);

   //Exercise
   Square* square = pawnWhite1.getEnPassantMove();

   //Verify


   assert(square->getNotation() == "b6");

   //Tear down
}

void TestPawn::testPawnInFront()
{
   //Set Up
   Game game;
   game.initDefault(false);
   Board& board = game.getBoard();
   Player& player = game.getPlayer(0);
   Player& player2 = game.getPlayer(1);

   Pawn pawn(board["c2"], player);
   Pawn blackPawn(board["c3"], player2);

   //Exercise

   set<Square*> moves = pawn.getMoves();


   //Verify
   assert(moves.size() == 0);
   //Tear down
}

void TestPawn::testPawnPromote()
{
   //Set Up
   Game game;
   game.initDefault(false);
   Board& board = game.getBoard();
   Player& player = game.getPlayer(0);
   Pawn pawn(board["c8"], player);
   Queen queen(pawn.getSquare(), player);
   //Exercise

   pawn.promote(&queen);

   //Verify
   assert(queen.getSquare()->getNotation() == "c8");

   //Tear down
}

void TestPawn::testPawnOneMove()
{
   //Set Up
   Game game;
   game.initDefault(false);
   Board& board = game.getBoard();
   Player& player = game.getPlayer(0);
   Player& player2 = game.getPlayer(1);

   Pawn pawn(board["c2"], player);
   Pawn blackPawn(board["c4"], player2);

   //Exercise
   set<Square*> moves = pawn.getMoves();


   //Verify
   char* correctMoves[] = { "c3" };
   assert(moves.size() == 1);

   //Tear down
}

void TestPawn::testPawnGetMoves()
{
   //Set Up
   Game game;
   game.initDefault(false);
   Board& board = game.getBoard();
   Player& player = game.getPlayer(0);
   Pawn pawn(board["c2"], player);

   //Exercise
   set<Square*> moves = pawn.getMoves();


   //Verify
   char* correctMoves[] = { "c3","c4" };
   assert(moves.size() == 2);

   //Tear down
}
