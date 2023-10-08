#pragma once

#include <set>

using namespace std;

class Square;

class TestHelper
{
public:
   static bool containsSquare(set<Square>& squares, const char* square);
   static bool squaresMatch(set<Square>& squares1, const char* squares2[], int moveLength);
};
