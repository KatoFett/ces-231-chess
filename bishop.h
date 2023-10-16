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

    set<Square*> getMoves() const override { return getBishopMoves(this->square); }; // Returns all possible moves for the bishop.
    const char getName() const override { return NAME; } // Returns the name of the piece.
    static set<Square*> getBishopMoves(Square* square); // Returns all possible moves of the bisop from a given square.

};

