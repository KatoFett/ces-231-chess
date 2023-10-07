#pragma once
#include "piece.h"
#include "square.h"
#include "iostream"
#include <set>
using namespace std;

class Pawn : public Piece
{


public:
	/*int getRank();*/
	Piece promote(Piece& toPiece);
	std::set<Square> getMoves();
	Square getEnPassantMove();
	bool checkEnPassant(Square enPassantSquare);

};
