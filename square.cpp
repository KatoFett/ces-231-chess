#include "square.h"



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
//
//Square& Square::getLeft()  {
//   
//}
//Square& Square::getRight()  {
//
Square& Square::getUp() {


    return Square(row, col + 1, isDark);


}
//
//Square& Square::getDown()  {
//    return 
//}
//
//std::string Square::getNotation()  {
//}