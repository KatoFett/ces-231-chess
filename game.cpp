#include "game.h"
#include "player.h"
#include "square.h"
#include "piece.h"

Game* Game::instance;

void Game::initDefault(bool assignPieces)
{
   if (assignPieces) throw "Assign pieces not implemented yet.";

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
}

void Game::addPlayer(Player& player)
{
   players.push_back(&player);
   playerCount++;
}

Move* Game::getLastMoveFromPlayer(Player& player) const
{
   //I know this doesnt work for for man chess it currently only checks the last move made
   if (moves.empty())
      throw "no moves have been made.";

   int prev = moves.size() - 1;

   return moves[prev];

}


void Game::move(Square* square)
{
   if (selectedPiece == nullptr) throw "Cannot move without first selecting a piece.";

   Move* move = selectedPiece->moveToSquare(square);
   moves.push_back(move);
}