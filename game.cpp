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

Game* Game::instance;

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

void Game::addPlayer(Player& player)
{
   players.push_back(&player);
   playerCount++;
}

const Move* Game::getLastMoveFromPlayer(Player& player) const
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


void Game::move(Square* square)
{
   if (selectedPiece == nullptr) throw "Cannot move without first selecting a piece.";

   const Direction direction = selectedPiece->getPlayer().getDirection();

   const Move* move = selectedPiece->moveToSquare(square);
   moves.push_back(move);

   if (move->getType() == CASTLE || move->getType() == CASTLE_LONG)
   {
      int distance = move->getType() == CASTLE ? 1 : 2;
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
   // If we move a pawn, increment the rank. and check if we can promote
   if (selectedPiece->getName() == 'P')
   {
       Pawn* pawn = (Pawn*)selectedPiece;
       pawn->increment();
       //6 if double move first, 7 if not.
       if (pawn->getRank() == 6 || pawn->getRank() == 7)
       {
           Queen queen = Queen(pawn->getSquare(), pawn->getPlayer());
           pawn->promote(&queen);
       }
   }

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