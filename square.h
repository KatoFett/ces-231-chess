#pragma once
#include "piece.h"

class Square
{
private:
   int row;
   int col;
   Piece* piece;
   bool isDark;


public:
   Square(int x, int y, bool isDark);

   bool operator == (Square& rhs) const { return this == &rhs; }
   bool operator != (Square& rhs) const { return this != &rhs; }

   int getRow() const { return row; }
   int getCol() const { return col; }
   Piece* getPiece() const { return piece; }
   bool getIsDark() const { return isDark; }
   const char* getNotation() const;
   Square* getLeft(Direction direction) const;
   Square* getRight(Direction direction) const;
   Square* getUp(Direction direction) const;
   Square* getDown(Direction direction) const;

   void setPiece(Piece* newPiece) { piece = newPiece; }
};


