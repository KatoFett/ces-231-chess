#include "pawn.h"
#include "piece.h"
#include "game.h"
#include "move.h"
#include "piece.h"
#include "square.h"
#include "iostream"
#include <set>

using namespace std;

const char* Pawn::NAME = "PAWN";

bool Pawn::checkEnPassant(Square& enPassantSquare)
{
   Piece* piece = enPassantSquare.getPiece();
   if (piece != nullptr && piece->getName() == Pawn::NAME)
   {
      Player piecePlayer = piece->getPlayer();
      if (piecePlayer != player)
      {
         Direction direction = player.getDirection();
         Move* lastMove = Game::getInstance().getLastMoveFromPlayer(piecePlayer);
         if (lastMove != nullptr && square.getUp(direction)->getUp(direction) == &lastMove->getFrom())
         {
            return true;
         }
      }
      return false;
   }
}

Square Pawn::getEnPassantMove()
{
   // There *shouldn’t* be a case where multiple en-passant moves are possible, 
   // especially in 2 - player chess.
   // But if there are, this function will need to be changed to return multiple squares.

   Direction direction = player.getDirection();

   // Check Left
   Square enPassantSquare = *square.getLeft(direction);
   if (checkEnPassant(enPassantSquare))
      return enPassantSquare;

   // Check Right
   Square enPassantSquare = *square.getRight(direction);
   if (checkEnPassant(enPassantSquare))
      return enPassantSquare;


}

//int Pawn::getRank() {
//	Square& square ;	
//	/*if(game.initDefault(false))*/
//	return square.getCol();
//}
set<Square> Pawn::getMoves()
{
   Direction direction = player.getDirection();

   std::set<Square> moves;
   Square oneAhead = *square.getUp(direction);

   if (oneAhead.getPiece() == nullptr)
      moves.insert(oneAhead);
   if (oneAhead.getUp(direction)->getPiece() == nullptr && !hasMoved)
      moves.insert(*oneAhead.getUp(direction));

   return moves;
}

void Pawn::promote(Piece& toPiece)
{
   player.removePiece(toPiece);
   player.addPiece(toPiece);
   square.setPiece(&toPiece);
   delete this;
}