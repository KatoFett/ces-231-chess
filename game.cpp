#include "game.h"
#include "player.h"
#include "square.h"
#include "piece.h"
#include "rook.h"
#include "pawn.h"
#include "knight.h"
#include "bishop.h"
#include "king.h"
#include "queen.h"
#include <cassert>

Game* Game::instance;   // Singleton instance of the current game.

/*
* INIT DEFAULT
* Initializes the game and board to a default 8x8 board with white and black pieces.
* Parameters:
*    assignPieces: Whether the board should come with pieces (true) or be empty (false).
*/
void Game::initDefault(bool assignPieces)
{
   int whiteColor[] = { 255, 255, 255 };
   int blackColor[] = { 0, 0, 0 };

   board = new Board(8, 8);

   // Create 2 players.
   Player* white = new Player(Direction::UP, whiteColor);
   Player* black = new Player(Direction::DOWN, blackColor);
   addPlayer(*white);
   addPlayer(*black);

   // Create squares.
   bool isDark = true;    // A1 square is always black.
   for (int row = 0; row < 8; row++)
   {
      for (int col = 0; col < 8; col++)
      {
         Square* square = new Square(isDark);
         board->addSquare(square);
         isDark = !isDark;
      }
   }

   // Assign pieces.
   if (assignPieces)
   {
      for (int i = 0; i < 2; i++)
      {
         bool blackPlayer = i;
         Player& player = blackPlayer ? *black : *white;
         const Direction direction = player.getDirection();

         // Init pieces from bottom-left to top-right (relative).

         const char* startingSquare = blackPlayer ? "h8" : "a1";

         // Add special pieces.
         Square* square = (*board)[startingSquare];
         new Rook(square, player);

         square = square->getRight(direction);
         new Knight(square, player);

         square = square->getRight(direction);
         new Bishop(square, player);

         // Black king or white queen.
         square = square->getRight(direction);
         blackPlayer ? (Piece*)(new King(square, player)) : new Queen(square, player);

         // Black queen or white king.
         square = square->getRight(direction);
         blackPlayer ? (Piece*)(new Queen(square, player)) : new King(square, player);

         square = square->getRight(direction);
         new Bishop(square, player);

         square = square->getRight(direction);
         new Knight(square, player);

         square = square->getRight(direction);
         new Rook(square, player);

         // Add pawns.
         square = square->getUp(direction);
         for (int n = 0; n < 8; n++)
         {
            new Pawn(square, player);
            square = square->getLeft(direction);
         }
      }
   }
}

/*
* ADD PLAYER
* Adds a player to the current game.
*/
void Game::addPlayer(Player& player)
{
   players.push_back(&player);
   playerCount++;
}

/*
* GET LAST MOVE FROM PLAYER
* Gets the last moved executed by the provided player, or nullptr if none exists.
*/
const Move* Game::getLastMoveFromPlayer(const Player& player) const
{
   if (!moves.empty())
   {
      for (int i = moves.size() - 1; i > max((int)moves.size() - playerCount - 1, 0); i--)
      {
         if (moves[i]->getPieceMoved()->getPlayer() == player) return moves[i];
      }
   }

   return nullptr;
}

/*
* MOVE
* Moves the selected piece to the provided square.
*/
void Game::move(Square* square)
{
   if (selectedPiece == nullptr) throw "Cannot move without first selecting a piece.";

   const Direction direction = selectedPiece->getPlayer().getDirection();

   // Create a move and add it to the internal list.
   const Move* move = selectedPiece->moveToSquare(square);
   moves.push_back(move);

   // Move king and rook for castling.
   if (move->getType() == CASTLE || move->getType() == CASTLE_LONG)
   {
      int distance = move->getType() == CASTLE ? 1 : 2;  // Rook is 1 or 2 squares away from the destination.

      // Check if rook is on the left.
      Square* rookSquare = square->getLeft(direction, distance);
      if (rookSquare != nullptr && rookSquare->getPiece() != nullptr && rookSquare->getPiece()->getName() == Rook::NAME)
      {
         // Move rook to the right.
         rookSquare->getPiece()->moveToSquare(square->getRight(direction));
      }
      else
      {
         // Castle rook must be on the right.
         rookSquare = square->getRight(direction, distance);
         assert(rookSquare != nullptr);
         assert(rookSquare->getPiece() != nullptr);
         assert(rookSquare->getPiece()->getName() == Rook::NAME);
         rookSquare->getPiece()->moveToSquare(square->getLeft(direction));
      }
   }

   // Callback if the piece needs to apply logic after a move (e.g. pawn promotion).
   selectedPiece->finishMove(move);

   bool playerFound = false;

   // Move to next player, which may have to skip some if they have no pieces.
   while (!playerFound)
   {
      // Move to next player.
      currentTurn++;
      if (currentTurn == playerCount)
         currentTurn = 0;

      // Check if the player can play a move.
      // If the game is over, only the remaining player will have any pieces left.
      playerFound = players[currentTurn]->hasPieces();
   }
}