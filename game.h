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

   void addPlayer(Player& player);

public:
   Game() :
      board(),
      playerCount(0),
      players(),
      currentTurn(nullptr)
   {}

   Board& getBoard() { return board; }
   Player& getCurrentTurn() const { return *currentTurn; }

   void initDefault(bool assignPieces);
};

