#include "queen.h"
#include "square.h"
#include "bishop.h"
#include "rook.h"
#include "game.h"
#include "rook.h"
#include "bishop.h"
#include <set>

using namespace std;

const char* Queen::NAME = "QUEEN";

set<Square*> Queen::getMoves() const
{
   set<Square*> moves = Rook::getRookMoves(square);

   // Combine rook and bishop moves.
   set<Square*> bishopMoves = Bishop::getBishopMoves(square);
   for (Square* move : bishopMoves)
      moves.insert(move);

   return moves;
}