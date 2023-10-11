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
   Board& getBoard() { return *board; }
   Player& getCurrentTurn() const { return *players[currentTurn]; }
   Player& getPlayer(int index) { return *players[index]; }
   Move* getLastMoveEnPassant() const;

   void setSelectedPiece(Piece* piece) { selectedPiece = piece; }

   void initDefault(bool assignPieces);

   void move(Square* square);
};

