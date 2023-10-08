#pragma once

#include "direction.h"

class Piece;

class Square
{
private:
   int index;
   int row;
   int col;
   Piece* piece;
   bool isDark;

public:
   Square(int row, int col, bool isDark) :
      row(0), col(0), isDark(false), piece(nullptr), index(0)
   {
      this->row = row;
      this->col = col;
      this->isDark = isDark;
   }

   bool operator == (const Square& rhs) const { return this == &rhs; }
   bool operator != (const Square& rhs) const { return this != &rhs; }
   bool operator < (const Square& rhs) const { return index < rhs.index; }

   int getIndex() const;
   int getRow() const { return row; }
   int getCol() const { return col; }
   Piece* getPiece() const { return piece; }
   bool getIsDark() const { return isDark; }
   const char* getNotation() const { return "a1"; }
   Square* getLeft(Direction direction) const;
   Square* getRight(Direction direction) const;
   Square* getUp(Direction direction) const;
   Square* getDown(Direction direction) const;

   void setPiece(Piece* newPiece) { piece = newPiece; }
   void setIndex(int index) { this->index = index; }
};


