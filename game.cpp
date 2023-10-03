#include "game.h"

void Game::initDefault(bool assignPieces)
{
   if (assignPieces) throw "Assign pieces not implemented yet.";

   // Create 2 players.
   Player white, black;
   addPlayer(white);
   addPlayer(black);

   // Create squares.
   bool isDark = true;    // A1 square is always black.
   for (int row = 0; row < 8; row++)
   {
      for (int col = 0; col < 8; col++)
      {
         Square square(row, col, isDark);
         board.addSquare(row, square);
         isDark = !isDark;
      }
   }
}

void Game::addPlayer(Player& player)
{
   players.push_back(player);
   playerCount++;

   if (currentTurn == nullptr)
      currentTurn = &player;
}