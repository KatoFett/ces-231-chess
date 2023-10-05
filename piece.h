#pragma once

#include "Square.h"
#include "Player.h"

class Piece
{
protected:
    Player* player;
    Square& square;
    bool hasMoved;
public:

    Piece(Square square, Player player);

    Square getSquare();
    Player getPlayer();
    bool getHasMoved();


};


