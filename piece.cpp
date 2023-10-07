#include "piece.h"
#include "square.h" 
#include "player.h" 


Square Piece::getSquare()  {
    return square;
}

Player Piece::getPlayer()  {
    return player;
}

bool Piece::getHasMoved()  {
    return hasMoved;
}

char* Piece::getName() {
    return name;
}

