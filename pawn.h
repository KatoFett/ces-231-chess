#pragma once
#include "piece.h"
#include "square.h"
#include "iostream"
#include <set>
using namespace std;

class Pawn : public Piece
{


public:
	static const char* NAME;

	/*int getRank();*/
	void promote(Piece& toPiece);
	std::set<Square> getMoves();
	Square getEnPassantMove();
	bool checkEnPassant(Square& enPassantSquare);
	const char* getName() const override { return NAME; }
};
