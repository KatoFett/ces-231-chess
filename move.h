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
   Move(Square& from, Square& to, Piece& pieceMoved) :
      from(&from), to(&to), pieceMoved(&pieceMoved), pieceCaptured(nullptr)
   {}

   Square& getFrom() const { return *from; }
   Square& getTo() const { return *to; }
};

