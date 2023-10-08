#pragma once

#include <vector>
#include "board.h"
#include "move.h"
#include "player.h"

class TestGame;
class Piece;

class Game
{
   friend TestGame;

private:
   Board board;
   int playerCount;
   vector<Player> players;
   Player* currentTurn;
   vector<Move> moves;
   Piece* selectedPiece;

   static Game* instance;

   void addPlayer(Player& player);

public:
   Game() :
      board(),
      playerCount(0),
      players(),
      currentTurn(nullptr),
      selectedPiece(nullptr),
      moves()
   {
      instance = this;
   }

   static Game getInstance() { return *instance; }
   Board& getBoard() { return board; }
   Player& getCurrentTurn() const { return *currentTurn; }
   Player& getPlayer(int index) { return players[index]; }
   Move* getLastMoveFromPlayer(Player& player) const;

   void setSelectedPiece(Piece* piece) { selectedPiece = piece; }

   void initDefault(bool assignPieces);

   void move(Square& square);
};

