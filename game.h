#pragma once

#include "board.h"
#include "testGame.h"
#include "player.h"

class Game
{
   friend TestGame;

private:
   Board board;
   int playerCount;
   vector<Player&> players;
   Player* currentTurn;

   static Game& instance;

   void addPlayer(Player& player);

public:
   Game() :
      board(),
      playerCount(0),
      players(),
      currentTurn(nullptr)
   {
      instance = *this;
   }

   static Game& getInstance() { return instance; }
   Board& getBoard() { return board; }
   Player& getCurrentTurn() const { return *currentTurn; }
   Move* getLastMoveFromPlayer(Player& player) const;

   void initDefault(bool assignPieces);
};

