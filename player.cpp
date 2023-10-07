#include "player.h"
//#include "piece.h"





int Player::getColor() {
	return color[3];
}


void Player::addPiece(Piece &piece) {
	pieces.insert(piece);
}
void Player::removePiece(Piece &piece) {
	pieces.erase(piece);
}
