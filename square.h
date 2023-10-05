#pragma once
#include <string>
#include "piece.h"
class Square
{
private:
    int row;
    int col;
    Piece* piece;
    bool isDark;

public:
    Square();
    Square(int x, int y, bool isDark);
    int getRow();
    int getCol();
    Piece* getPiece();
    void setPiece(Piece* newPiece);
    bool getIsDark();
    Square& getLeft();
    Square& getRight();
    Square& getUp();
    Square& getDown();
    std::string getNotation();
};

