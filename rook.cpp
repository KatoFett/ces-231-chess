#include "rook.h"
#include "square.h"
#include <set>

using namespace std;

const char* Rook::NAME = "ROOK";

set<Square> Rook::getMoves() const
{
   return set<Square>();
}