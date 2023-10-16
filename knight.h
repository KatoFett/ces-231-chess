#pragma once

#include "piece.h"
#include <set>

using namespace std;

class Square;

/*
* KNIGHT
* The knight piece.
*/
class Knight : public Piece
{
public:

    Knight(Square* square, Player& player)
        : Piece(square, player)
    {}

    static const char NAME;

    const char getName() const override { return NAME; }
    set<Square*> getMoves() const override;
};