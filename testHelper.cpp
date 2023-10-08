#include "testHelper.h"
#include "square.h"
#include <set>

using namespace std;

bool containsSquare(set<Square>& squares, const char* square)
{
   for (const Square& element : squares)
   {
      if (element.getNotation() == square)
      {
         return true;
      }
   }

   return false;
}

bool squaresMatch(set<Square>& squares1, const char* squares2[], int moveLength)
{
   if (squares1.size() != moveLength)
   {
      return false;
   }

   for (int i = 0; i < moveLength; i++)
   {
      if (!containsSquare(squares1, squares2[i]))
      {
         return false;
      }
   }

   return true;
}
