#include "testGame.h"
#include "game.h"
#include "board.h"
#include "square.h"
#include "player.h"
#include <vector>
#include <cassert>
#include <string>
#include "pawn.h"
#include "rook.h"
#include "knight.h"
#include "bishop.h"
#include "king.h"
#include "queen.h"

using namespace std;

void TestGame::run()
{
   testInitDefault();
   testDefaultPieces();
   testMovePawn();
}

/* TEST INIT DEFAULT
* Tests Game.initDefault(false) to produce an empty 8x8 chess board.
* Almost ALL test cases use this function.
*/
void TestGame::testInitDefault()
{
   // SETUP
   Game game;

   // EXERCISE

   game.initDefault(false);

   // VERIFY

   Board& board = game.getBoard();

   // Board must be 8x8.
   assert(board.width == 8);
   assert(board.height == 8);
   assert(board.squares.size() == 64);

   char* cols[] = { "a", "b", "c", "d", "e", "f", "g", "h" };

   // Squares must be A1-H8, empty (no piece on top), and alternating color.
   for (int i = 0; i < 63; i++)
   {
      int row = i / 8;
      int col = i % 8;
      Square* square = board.squares[i];
      auto squareNotation = square->getNotation();
      auto expectedNotation = cols[col] + to_string(row + 1);
      auto notationMatches = squareNotation == expectedNotation;
      assert(notationMatches);	                                    // Correct notation.
      assert(square->getPiece() == nullptr);								   // No piece.
      bool isOddSquare = i % 2;
      assert(square->getIsDark() == !isOddSquare);                   // Correct color.
   }

   assert(game.playerCount == 2);						   // 2 players.
   assert(game.getCurrentTurn() == *game.players[0]);	// Current turn is white.

   // TEARDOWN
}

/* TEST INIT DEFAULT
* Tests Game.initDefault(true) to produce a populated 8x8 chess board.
*/
void TestGame::testDefaultPieces()
{
   // SETUP
   Game game;

   // EXERCISE

   game.initDefault(true);

   // VERIFY

   Board& board = game.getBoard();

   // Test white pieces.
   assert(board["a1"]->getPiece()->getName() == Rook::NAME);
   assert(board["a1"]->getPiece()->getPlayer() == game.getPlayer(0));
   assert(board["b1"]->getPiece()->getName() == Knight::NAME);
   assert(board["b1"]->getPiece()->getPlayer() == game.getPlayer(0));
   assert(board["c1"]->getPiece()->getName() == Bishop::NAME);
   assert(board["c1"]->getPiece()->getPlayer() == game.getPlayer(0));
   assert(board["d1"]->getPiece()->getName() == Queen::NAME);
   assert(board["d1"]->getPiece()->getPlayer() == game.getPlayer(0));
   assert(board["e1"]->getPiece()->getName() == King::NAME);
   assert(board["e1"]->getPiece()->getPlayer() == game.getPlayer(0));
   assert(board["f1"]->getPiece()->getName() == Bishop::NAME);
   assert(board["f1"]->getPiece()->getPlayer() == game.getPlayer(0));
   assert(board["g1"]->getPiece()->getName() == Knight::NAME);
   assert(board["g1"]->getPiece()->getPlayer() == game.getPlayer(0));
   assert(board["h1"]->getPiece()->getName() == Rook::NAME);
   assert(board["h1"]->getPiece()->getPlayer() == game.getPlayer(0));
   for (int i = 1; i <= 8; i++)
   {
      string notation = char(i + 96) + string("2");
      assert(board[notation.c_str()]->getPiece()->getName() == Pawn::NAME);
      assert(board[notation.c_str()]->getPiece()->getPlayer() == game.getPlayer(0));
   }

   // Test black pieces.
   assert(board["a8"]->getPiece()->getName() == Rook::NAME);
   assert(board["a8"]->getPiece()->getPlayer() == game.getPlayer(1));
   assert(board["b8"]->getPiece()->getName() == Knight::NAME);
   assert(board["b8"]->getPiece()->getPlayer() == game.getPlayer(1));
   assert(board["c8"]->getPiece()->getName() == Bishop::NAME);
   assert(board["c8"]->getPiece()->getPlayer() == game.getPlayer(1));
   assert(board["d8"]->getPiece()->getName() == Queen::NAME);
   assert(board["d8"]->getPiece()->getPlayer() == game.getPlayer(1));
   assert(board["e8"]->getPiece()->getName() == King::NAME);
   assert(board["e8"]->getPiece()->getPlayer() == game.getPlayer(1));
   assert(board["f8"]->getPiece()->getName() == Bishop::NAME);
   assert(board["f8"]->getPiece()->getPlayer() == game.getPlayer(1));
   assert(board["g8"]->getPiece()->getName() == Knight::NAME);
   assert(board["g8"]->getPiece()->getPlayer() == game.getPlayer(1));
   assert(board["h8"]->getPiece()->getName() == Rook::NAME);
   assert(board["h8"]->getPiece()->getPlayer() == game.getPlayer(1));
   for (int i = 1; i <= 8; i++)
   {
      string notation = char(i + 96) + string("7");
      assert(board[notation.c_str()]->getPiece()->getName() == Pawn::NAME);
      assert(board[notation.c_str()]->getPiece()->getPlayer() == game.getPlayer(1));
   }

   // TEARDOWN
}

/* TEST MOVE PAWN
* Tests Game.Move() with a generic pawn move.
*/
void TestGame::testMovePawn()
{
   // SETUP
   Game game;
   game.initDefault(false);
   Board& board = game.getBoard();
   Player& player = game.getCurrentTurn();
   Square* fromSquare = board["e2"];
   Square* toSquare = board["e4"];
   Pawn pawn(fromSquare, player);
   game.setSelectedPiece(&pawn);

   // EXERCISE
   game.move(toSquare);

   // VERIFY
   assert(pawn.getSquare() == toSquare);			// Moved to the square.
   assert(fromSquare->getPiece() == nullptr);	// Old square is empty.
   assert(toSquare->getPiece() == &pawn);			// New square contains the pawn.
   assert(game.moves.size() == 1);					// Added new move.

   Move* move = game.moves[0];
   assert(move->getPieceMoved() == &pawn);		   // Moved piece is the pawn.
   assert(move->getPieceCaptured() == nullptr);    // No captured piece.
   assert(move->getFrom() == fromSquare);		      // Correct from-square.
   assert(move->getTo() == toSquare);			      // Correct to-square.

   // TEARDOWN
}