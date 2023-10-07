#include "square.h"
#include <stdexcept>

using namespace std;

Square::Square(int row, int col, bool isDark) : row(row), col(col), isDark(isDark) {

}

int Square::getRow() const {
    return row;
}

int Square::getCol() const {
    return col;
}

Piece* Square::getPiece() const {
    return piece;
}

void Square::setPiece(Piece& newPiece) const {
    piece = &newPiece;
}

bool Square::getIsDark() const {
    return isDark;
}

Square* Square::getLeft(Direction direction) const {
   

    //Will need to be changed later to handle different board sizes
    if (col < 0 ) {
        return &Square(row, col -1, isDark);
    }
    else { 
        return nullptr;
    }
}
Square* Square::getRight(Direction direction) const {


    //Will need to be changed later to handle different board sizes
    if (col > 8) {
        return &Square(row, col + 1, isDark);
    }
    else {
        return nullptr;
    }

}
Square* Square::getUp(Direction direction) const {

    //Will need to be changed later to handle different board sizes
    //Direction will be added later. not needed for testcases
    if(row  > 8)
     return &Square(row + 1, col, isDark);
    else {
        return nullptr;
    }


}

Square* Square::getDown(Direction direction) const {

    //Will need to be changed later to handle different board sizes
    if (row > 0)
        return  &Square(row - 1, col, isDark);
    else {
        return nullptr;
    }
}
//
//std::string Square::getNotation()  {
//}


bool Square::operator!=(const nullptr_t& rhs) const
{
    if (piece != rhs)
    {
        return true;
    }
    else
    {
        return false;
    }
}