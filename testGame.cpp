#include "testGame.h"
#include "game.h"
#include "board.h"
#include "square.h"
#include "player.h"
#include <vector>
#include <cassert>
#include <string>

using namespace std;

void TestGame::run()
{
   testInitDefault();
}

/* TEST INIT DEFAULT
* Tests Game.initDefault(false) to produce an empty 8x8 chess board,
* necessary for almost all test cases.
*/
void TestGame::testInitDefault()
{
   // SETUP
   Game game;
   Board board = game.getBoard();

   // EXERCISE

   game.initDefault(false);

   // VERIFY
   // Board must be 8x8.
   assert(board.squares.size() == 8);			   // 8 rows.
   for (int i = 0; i < 8; i++)
   {
      assert(board.squares[i].size() == 8);		// 8 columns.
   }

   char* rows[] = { "a", "b", "c", "d", "e", "f", "g", "h" };

   // Squares must be A1-H8, empty (no piece on top), and alternating color.
   for (int i = 0; i < 63; i++)
   {
      int row = i / 8;
      int col = i % 8;
      Square* square = board.squares[row][col];
      assert(square->getNotation() == (rows[row] + to_string(col + 1)));	// Correct notation.
      assert(square->getPiece() == nullptr);								         // No piece.
      bool isOddSquare = i % 2;
      assert(square->getIsDark() == !isOddSquare);							      // Correct color.
   }

   assert(game.playerCount == 2);						   // 2 players.
   assert(game.getCurrentTurn() == game.players[0]);	// Current turn is white.

   // TEARDOWN
}

