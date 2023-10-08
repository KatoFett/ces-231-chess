#include "queen.h"
#include "square.h"
#include <set>

using namespace std;

const char* Queen::NAME = "QUEEN";

set<Square> Queen::getMoves() const
{
   return set<Square>();
}