#pragma once

#include "piece.h"
#include <set>

using namespace std;

class Square;

class Pawn : public Piece
{
public:
	Pawn(Square* square, Player& player)
		: Piece(square, player), rank(1)
	{}

	static const char NAME;

	/*int getRank();*/
	void promote(Piece* toPiece);
	std::set<Square*> getMoves() const override;
	Square* getEnPassantMove() const;
	bool checkEnPassant(Square* enPassantSquare) const;
	const char getName() const override { return NAME; }
	const Move* getMoveFromSquare(Square* destination) override;
	int getRank() { return rank; }

	Pawn& operator++()
	{
		 rank+=1;
		 return *this;
	}

private:
	 int rank;
};
