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
         Piece* pieceToAdd = new Rook(square, player);
         player.addPiece(pieceToAdd);

         square = square->getRight(direction);
         pieceToAdd = new Knight(square, player);
         player.addPiece(pieceToAdd);

         square = square->getRight(direction);
         pieceToAdd = new Bishop(square, player);
         player.addPiece(pieceToAdd);

         // Black king or white queen.
         square = square->getRight(direction);
         pieceToAdd = blackPlayer ? (Piece*)(new King(square, player)) : new Queen(square, player);
         player.addPiece(pieceToAdd);

         // Black queen or white king.
         square = square->getRight(direction);
         pieceToAdd = blackPlayer ? (Piece*)(new Queen(square, player)) : new King(square, player);
         player.addPiece(pieceToAdd);

         square = square->getRight(direction);
         pieceToAdd = new Bishop(square, player);
         player.addPiece(pieceToAdd);

         square = square->getRight(direction);
         pieceToAdd = new Knight(square, player);
         player.addPiece(pieceToAdd);

         square = square->getRight(direction);
         pieceToAdd = new Rook(square, player);
         player.addPiece(pieceToAdd);

         // Add pawns.
         square = square->getUp(direction);
         for (int n = 0; n < 8; n++)
         {
            Piece* pieceToAdd = new Pawn(square, player);
            player.addPiece(pieceToAdd);
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

Move* Game::getLastMoveFromPlayer(Player& player) const
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

   Move* move = selectedPiece->moveToSquare(square);
   moves.push_back(move);
}