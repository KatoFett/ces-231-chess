#include "square.h"
#include "game.h"
#include "board.h"
#include "direction.h"
#include <stdexcept>
#include <string>

using namespace std;

string Square::getNotation() const
{
   char colLetter = 97 + getCol();
   char rankNum = 49 + getRow();
   return string({ colLetter, rankNum });
}

Square* Square::getLeft(Direction direction, int distance) const
{
   int newCol = getCol(), newRow = getRow();
   switch (direction)
   {
   case UP:
      newCol -= distance;
      break;
   case DOWN:
      newCol += distance;
      break;
   case RIGHT:
      newRow += distance;
      break;
   case LEFT:
      newRow -= distance;
      break;
   default:
      throw "Invalid direction.";
   }

   return Game::getInstance().getBoard().getSquare(newRow, newCol);
}

Square* Square::getRight(Direction direction, const int distance) const
{
   int newCol = getCol(), newRow = getRow();
   switch (direction)
   {
   case UP:
      newCol += distance;
      break;
   case DOWN:
      newCol -= distance;
      break;
   case RIGHT:
      newRow -= distance;
      break;
   case LEFT:
      newRow += distance;
      break;
   default:
      throw "Invalid direction.";
   }

   return Game::getInstance().getBoard().getSquare(newRow, newCol);
}

Square* Square::getUp(Direction direction, const int distance) const
{
   int newCol = getCol(), newRow = getRow();
   switch (direction)
   {
   case UP:
      newRow += distance;
      break;
   case DOWN:
      newRow -= distance;
      break;
   case RIGHT:
      newCol += distance;
      break;
   case LEFT:
      newCol -= distance;
      break;
   default:
      throw "Invalid direction.";
   }

   return Game::getInstance().getBoard().getSquare(newRow, newCol);
}

Square* Square::getDown(Direction direction, const int distance) const
{
   int newCol = getCol(), newRow = getRow();
   switch (direction)
   {
   case UP:
      newRow -= distance;
      break;
   case DOWN:
      newRow += distance;
      break;
   case RIGHT:
      newCol -= distance;
      break;
   case LEFT:
      newCol += distance;
      break;
   default:
      throw "Invalid direction.";
   }

   return Game::getInstance().getBoard().getSquare(newRow, newCol);
}

Square* Square::getAdjacent(int dRow, int dCol) const
{
   dRow += getRow();
   dCol += getCol();
   return Game::getInstance().getBoard().getSquare(dRow, dCol);
}

int Square::getCol() const
{
   int width = Game::getInstance().getBoard().getWidth();
   return index % width;
}

int Square::getRow() const
{
   int width = Game::getInstance().getBoard().getWidth();
   return index / width;
}
