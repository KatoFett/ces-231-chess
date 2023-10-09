#pragma once

class Square;
class Piece;

class Move
{
private:
   Square* from;
   Square* to;
   Piece* pieceMoved;
   Piece* pieceCaptured;

public:
   Move(Square* from, Square* to, Piece* pieceMoved) :
      from(from), to(to), pieceMoved(pieceMoved), pieceCaptured(nullptr)
   {}

   Move(Square* from, Square* to, Piece* pieceMoved, Piece* pieceCaptured)
      : Move::Move(from, to, pieceMoved)
   {
      this->pieceCaptured = pieceCaptured;
   }

   Square* getFrom() const { return from; }
   Square* getTo() const { return to; }
   Piece* getPieceMoved() const { return pieceMoved; }
   Piece* getPieceCaptured() const { return pieceCaptured; }
};

