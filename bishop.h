#pragma once

#include "piece.h"
#include <iostream>

using namespace std;

class Square;


class Bishop :	 public Piece
{
    Bishop(Square* square, Player& player)
        : Piece(square, player)
    {}

    static const char* NAME;

    set<Square*> getMoves() const override;
    const char* getName() const override { return NAME; }

};

