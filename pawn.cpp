#include "pawn.h"
#include "piece.h"
#include "game.h"
#include "move.h"
#include "piece.h"
#include "square.h"
#include "iostream"
#include "player.h"
#include "direction.h"
#include "queen.h"
#include <set>
#include <cassert>

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
         const Move* lastMove = Game::getInstance().getLastMoveFromPlayer(piecePlayer);
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

   Square* oneAhead = square->getUp(direction);

   // Move ahead, can't capture ahead.
   bool canMoveAhead = canMoveToSquare(player, oneAhead) && oneAhead->getPiece() == nullptr;
   if (canMoveAhead)
      moves.insert(oneAhead);

   // Capture left
   Square* capture = oneAhead->getLeft(direction);
   if (canMoveToSquare(player, capture) && capture->getPiece() != nullptr)
      moves.insert(capture);

   // Capture right
   capture = oneAhead->getRight(direction);
   if (canMoveToSquare(player, capture) && capture->getPiece() != nullptr)
      moves.insert(capture);

   // Move 2 squares on first move.
   if (!hasMoved && canMoveAhead)
   {
      oneAhead = oneAhead->getUp(direction);
      if (canMoveToSquare(player, oneAhead) && oneAhead->getPiece() == nullptr)
         moves.insert(oneAhead);
   }

   //Check if enPassant is allowed
   Square* enPassant = getEnPassantMove();
   if (enPassant != nullptr)
      moves.insert(enPassant);

   return moves;
}

void Pawn::promote(Piece* toPiece)
{
   if (toPiece == nullptr) throw "Cannot promote to null piece.";

   player.removePiece(this);
}

const Move* Pawn::getMoveFromSquare(Square* destination)
{
   if (destination == getEnPassantMove())
   {
      Square* capturedSquare = destination->getDown(player.getDirection());
      assert(capturedSquare != nullptr);
      Piece* captured = capturedSquare->getPiece();
      assert(captured != nullptr);
      assert(captured->getName() == Pawn::NAME);
      assert(captured->getPlayer() != player);
      return new Move(square, destination, this, captured);
   }

   return Piece::getMoveFromSquare(destination);
}

void Pawn::finishMove(const Move* move)
{
   // Increment the pawn's rank.
   int dRow = move->getTo()->getRow() - move->getFrom()->getRow();
   int dCol = move->getTo()->getCol() - move->getFrom()->getCol();
   rank += max(abs(dRow), abs(dCol));

   // Promote to queen
   if (rank == 8)
   {
      Queen* queen = new Queen(square, player);
      promote(queen);
   }
}