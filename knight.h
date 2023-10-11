#pragma once

#include "piece.h"
#include <set>

using namespace std;

class Square;

class Knight : public Piece
{
public:

    Knight(Square* square, Player& player)
        : Piece(square, player)
    {}

    static const char* NAME;

    set<Square*> getMoves() const override;
    const char* getName() const override { return NAME; }
};