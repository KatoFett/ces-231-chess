#pragma once
#include "piece.h"
#include "square.h"
#include <iostream>
#include <set>

using namespace std;

class Rook : public Piece
{
public:
	set<Square> getMoves();

	set<Square> getRookMoves(Square square);

};

