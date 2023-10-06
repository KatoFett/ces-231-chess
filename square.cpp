#include "square.h"
#include <stdexcept>

using namespace std;

Square::Square(int row, int col, bool isDark) : row(row), col(col), isDark(isDark) {

}

int Square::getRow() {
    return row;
}

int Square::getCol() {
    return col;
}

Piece* Square::getPiece() {
    return piece;
}

void Square::setPiece(Piece* newPiece) {
    piece = newPiece;
}

bool Square::getIsDark() {
    return isDark;
}

Square& Square::getLeft()  {
   

    //Will need to be changed later to handle different board sizes
    if (col < 0) {
        return Square(row, col -1, isDark);
    }
    else {
        throw std::out_of_range("Out of bounds");
    }
}
Square& Square::getRight()  {


    //Will need to be changed later to handle different board sizes
    if (col > 8) {
        return Square(row, col + 1, isDark);
    }
    else {
        throw std::out_of_range("Out of bounds");
    }

}
Square& Square::getUp() {

    //Will need to be changed later to handle different board sizes
    if(row  > 8)
     return Square(row + 1, col, isDark);
    else {
        throw std::out_of_range("Out of bounds");
    }


}

Square& Square::getDown()  {

    //Will need to be changed later to handle different board sizes
    if (row > 0)
        return  Square(row - 1, col, isDark);
    else {
        throw std::out_of_range ("Out of bounds");
    }
}
//
//std::string Square::getNotation()  {
//}