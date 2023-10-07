#pragma once
#include "piece.h"
#include "square.h"
#include <iostream>
#include <set>

using namespace std;

class King : public Piece
{
public:
   static const char* NAME;

   std::set<Square> getMoves();
   std::set<Square> getCastleMoves();
   const char* getName() const override { return NAME; }
};