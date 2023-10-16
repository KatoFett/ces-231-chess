#pragma once
class Square;
class Piece;

/*
* MOVE TYPE
* The type of move executed.
*/
enum MoveType
{
   REGULAR,       // Normal movements.
   CASTLE,        // Short (kingside) castle.
   CASTLE_LONG    // Long (queenside) castle.
};

/* 
* MOVE
* A single turn by a player.
*/
class Move
{
private:
   Square* from;              // The square where the piece originated.
   Square* to;                // The square where the piece went.
   Piece* pieceMoved;         // The piece that was moved.
   Piece* pieceCaptured;      // The piece that was captured, if any.
   const MoveType moveType;   // The type of move.

public:
   // Constructors

   // Creates a move without a captured piece, allowing for special move types.
   Move(Square* from, Square* to, Piece* pieceMoved, const MoveType moveType = REGULAR) :
      from(from),
      to(to),
      pieceMoved(pieceMoved),
      pieceCaptured(nullptr),
      moveType(moveType)
   {}

   // Creates a move with a captured piece. Only regular moves can capture.
   Move(Square* from, Square* to, Piece* pieceMoved, Piece* pieceCaptured)
      : Move::Move(from, to, pieceMoved)
   {
      this->pieceCaptured = pieceCaptured;
   }

   // Getters
   Square* getFrom() const { return from; }
   Square* getTo() const { return to; }
   Piece* getPieceMoved() const { return pieceMoved; }
   Piece* getPieceCaptured() const { return pieceCaptured; }
   const MoveType getType() const { return moveType; }
};

