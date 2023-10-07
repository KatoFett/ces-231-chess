#pragma once
#include "piece.h"
#include "square.h"
#include <iostream>
#include <set>

using namespace std;

class King : public Piece
{
public:

	std::set<Square> getMoves();

	std::set<Square> getCastleMoves();

};