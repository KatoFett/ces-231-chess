#pragma once
class Square;
class Piece;

enum MoveType
{
   REGULAR,
   CASTLE,
   CASTLE_LONG
};

class Move
{
private:
   Square* from;
   Square* to;
   Piece* pieceMoved;
   Piece* pieceCaptured;
   const MoveType moveType;

public:
   Move(Square* from, Square* to, Piece* pieceMoved, const MoveType moveType = REGULAR) :
      from(from),
      to(to),
      pieceMoved(pieceMoved),
      pieceCaptured(nullptr),
      moveType(moveType)
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
   const MoveType getType() const { return moveType; }
};

