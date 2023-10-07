#pragma once
#include "piece.h"
#include "square.h"
#include <iostream>
#include <set>

using namespace std;

class Rook : public Piece
{
public:

   static const char* NAME;

   const char* getName() const override { return NAME; }
   set<Square> getMoves() const override;
   static set<Square> getRookMoves(Square& square);
};

