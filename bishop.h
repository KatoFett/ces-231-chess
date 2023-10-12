#pragma once

#include "piece.h"
#include <iostream>

using namespace std;

class Square;


class Bishop :	 public Piece
{
public:
    Bishop(Square* square, Player& player)
        : Piece(square, player)
    {}

    static const char NAME;

    set<Square*> getMoves() const override { return getBishopMoves(this->square); };
    const char getName() const override { return NAME; }
    static set<Square*> getBishopMoves(Square* square);

};

