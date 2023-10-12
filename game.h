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
   Board* board;
   int playerCount;
   vector<Player*> players;
   int currentTurn;
   vector<Move*> moves;
   Piece* selectedPiece;

   static Game* instance;

   void addPlayer(Player& player);

public:
   Game() :
      playerCount(0),
      players(),
      currentTurn(0),
      selectedPiece(nullptr),
      board(nullptr),
      moves()
   {
      instance = this;
   }

   ~Game()
   {
      instance = nullptr;
   }

   static Game& getInstance() { return *instance; }
   Board& getBoard() const { return *board; }
   Player& getCurrentTurn() const { return *players[currentTurn]; }
   Player& getPlayer(int index) const { return *players[index]; }
   Move* getLastMoveFromPlayer(Player& player) const;
   Piece* getSelectedPiece() const { return selectedPiece; }

   void setSelectedPiece(Piece* piece) { selectedPiece = piece; }

   void initDefault(bool assignPieces);
   void move(Square* square);
};

