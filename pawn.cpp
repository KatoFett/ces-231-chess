#include "pawn.h"
#include "piece.h"
#include "game.h"
#include "move.h"
#include "piece.h"
#include "square.h"
#include "iostream"
#include <set>


using namespace std;

bool Pawn::checkEnPassant(Square enPassantSquare) {
	Piece* piece = enPassantSquare.getPiece();
	if (piece != nullptr && piece.name == Pawn.NAME)
	{
			Player piecePlayer = piece->getPlayer();
				if (piecePlayer != player) {
					Move lastMove = Game.getInstance().getLastMoveFromPlayer(piecePlayer);
					if (lastMove != NULL && square.getUp().getUp() == lastMove.getFrom()) {
						return true;
					}
				}
				return false;
		}
}

Square Pawn::getEnPassantMove() {
	// There *shouldn’t* be a case where multiple en-passant moves are possible, 
	// especially in 2 - player chess.
	// But if there are, this function will need to be changed to return multiple squares.
	
	// Check Left
	Square enPassantSquare = square.getLeft();
	if (checkEnPassant(enPassantSquare) )
		return enPassantSquare;

	// Check Right
	Square enPassantSquare = square.getRight();
	if (checkEnPassant(enPassantSquare))
		return enPassantSquare;
	

}

//int Pawn::getRank() {
//	Square& square ;	
//	/*if(game.initDefault(false))*/
//	return square.getCol();
//}
set<Square> Pawn::getMoves() {

	std::set<Square> moves;
	Player* player;
	Square& oneAhead = square.getUp();

	if (oneAhead.getPiece() == nullptr)
		moves.insert(oneAhead);
	if (oneAhead.getUp().getPiece() == nullptr && square.getCol() == 1 && player->getColor() == 0)
		moves.insert(oneAhead.getUp());

	return moves;
}

Piece Pawn::promote(Piece& toPiece) {
	Player player;
	player.removePiece(toPiece);
	player.addPiece(toPiece);
	square.setPiece(toPiece);
	delete this;
	return toPiece
}