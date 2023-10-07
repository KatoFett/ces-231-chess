
#pragma once

#include "piece.h"
#include "square.h"
#include "player.h"
class Queen : public Piece
{
public:
   static const char* NAME;

   const char* getName() const override { return NAME; }
};

