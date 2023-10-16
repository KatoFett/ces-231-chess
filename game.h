#pragma once

#include <vector>
#include "board.h"
#include "move.h"
#include "player.h"

class TestGame;
class Piece;

/*
* GAME
* A full chess game.
*/
class Game
{
   friend TestGame;

private:
   Board* board;              // Chess board.
   int playerCount;           // Amount of players, including dead.
   vector<Player*> players;   // List of players.
   int currentTurn;           // Index of the player whose turn it is.
   vector<const Move*> moves; // List of all moves from the start of the game.
   Piece* selectedPiece;      // The selected piece for the current turn.

   static Game* instance;     // The singleton instance of the current game.

   void addPlayer(Player& player);  // Adds a player to the game.

public:
   // Constructors
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

   // Destructors
   ~Game()
   {
      instance = nullptr;
   }

   // Getters
   static Game& getInstance() { return *instance; }
   Board& getBoard() const { return *board; }
   Player& getCurrentTurn() const { return *players[currentTurn]; }
   Player& getPlayer(int index) const { return *players[index]; }
   const Move* getLastMoveFromPlayer(const Player& player) const;
   Piece* getSelectedPiece() const { return selectedPiece; }

   // Setters
   void setSelectedPiece(Piece* piece) { selectedPiece = piece; }

   // Operations
   void initDefault(bool assignPieces);   // Initializes a default 8x8 board.
   void move(Square* square);             // Moves the selected piece to the provided square.
};

