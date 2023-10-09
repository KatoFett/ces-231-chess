#include "testGame.h"
#include "game.h"
#include "board.h"
#include "square.h"
#include "player.h"
#include <vector>
#include <cassert>
#include <string>
#include "pawn.h"

using namespace std;

void TestGame::run()
{
   testInitDefault();
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
   Board& board = game.getBoard();

   // EXERCISE

   game.initDefault(false);

   // VERIFY
   // Board must be 8x8.
   assert(board.squares.size() == 8);			   // 8 rows.
   for (int i = 0; i < 8; i++)
   {
      assert(board.squares[i].size() == 8);		// 8 columns.
   }

   char* cols[] = { "a", "b", "c", "d", "e", "f", "g", "h" };

   // Squares must be A1-H8, empty (no piece on top), and alternating color.
   for (int i = 0; i < 63; i++)
   {
      int row = i / 8;
      int col = i % 8;
      Square* square = board.squares[row][col];
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