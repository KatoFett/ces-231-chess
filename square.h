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
    void setPiece(Piece& newPiece);
    bool getIsDark();
    Square& getLeft(Direction direction);
    Square& getRight(Direction direction);
    Square& getUp(Direction direction);
    Square& getDown(Direction direction);
    std::string getNotation();
    bool operator != (const nullptr_t& rhs) const;
    
};


