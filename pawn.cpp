#include "pawn.h"
#include "piece.h"
#include "game.h"
#include "move.h"
#include "piece.h"
#include "square.h"
#include "iostream"
#include "player.h"
#include "direction.h"
#include <set>

using namespace std;

const char Pawn::NAME = 'P';

bool Pawn::checkEnPassant(Square* enPassantSquare) const
{
    // check to make sure enPassantSquare is valid square
    if (enPassantSquare == nullptr) return false;

   // Piece is a valid piece and it is a pawn
   Piece* piece = enPassantSquare->getPiece();
   if (piece != nullptr && piece->getName() == Pawn::NAME)
   {
      // Make sure enpassantSquare is somehow not your piece
      Player& piecePlayer = piece->getPlayer();
      if (piecePlayer != player)
      {
         const Direction direction = player.getDirection();
         
         // Check to make sure that the move was made last turn only and pawn made a two space jump
         Move* lastMove = Game::getInstance().getLastMoveFromPlayer(piecePlayer);
         if (lastMove != nullptr && enPassantSquare->getUp(direction)->getUp(direction) == lastMove->getFrom())
         {
            return true;
         }
      }
   }
   return false;
}

Square* Pawn::getEnPassantMove() const
{
   // There *shouldn’t* be a case where multiple en-passant moves are possible, 
   // especially in 2 - player chess.
   // But if there are, this function will need to be changed to return multiple squares.

   const Direction direction = player.getDirection();

   // Check Left 
   Square* enPassantSquare = square->getLeft(direction);
   if (checkEnPassant(enPassantSquare) && enPassantSquare->getUp(direction) != nullptr)
      return enPassantSquare->getUp(direction);

   // Check Right
   enPassantSquare = square->getRight(direction);
   if (checkEnPassant(enPassantSquare) && enPassantSquare->getUp(direction) != nullptr)
      return enPassantSquare->getUp(direction);

   return nullptr;
}

//int Pawn::getRank() {
//  Board& board = board.getHeight()
//}

set<Square*> Pawn::getMoves() const
{
   const Direction direction = player.getDirection();

   std::set<Square*> moves;
   int deltas[][2] = {
       {1,1}, {1,-1},
       {-1,1}, {-1, -1}
   };
   Square* oneAhead = square->getUp(direction);

   //Check no piece is in front
   if (oneAhead != nullptr && oneAhead->getPiece() == nullptr)
      moves.insert(oneAhead);
   //Check no piece in front or two ahead and pawn hasnt moved
   if (oneAhead->getUp(direction) != nullptr && oneAhead->getUp(direction)->getPiece()  == nullptr && !hasMoved && oneAhead->getPiece() == nullptr)
      moves.insert(oneAhead->getUp(direction));
   //Check if enPassant is allowed
   if (getEnPassantMove() != nullptr)
       moves.insert(getEnPassantMove());
   //capture
   for (int* delta : deltas)
   {
       int row = *delta;
       int col = *(delta + 1);
       Square* destination = square->getAdjacent(row, col);

       if (destination != nullptr && destination->getPiece() != nullptr && destination->getPiece()->getPlayer() != player)
       {
           moves.insert(destination);
       }
   }

   return moves;
}

void Pawn::promote(Piece* toPiece)
{
   if (toPiece == nullptr) throw "Cannot promote to null piece.";

   player.removePiece(toPiece);
   square->setPiece(toPiece);
}