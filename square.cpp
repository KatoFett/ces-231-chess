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

Square* Square::getLeft(Direction direction) const
{
   int newCol = getCol(), newRow = getRow();
   switch (direction)
   {
   case UP:
      newCol--;
      break;
   case DOWN:
      newCol++;
      break;
   case RIGHT:
      newRow++;
      break;
   case LEFT:
      newRow--;
      break;
   default:
      throw "Invalid direction.";
   }

   return Game::getInstance().getBoard().getSquare(newRow, newCol);
}

Square* Square::getRight(Direction direction) const
{
   int newCol = getCol(), newRow = getRow();
   switch (direction)
   {
   case UP:
      newCol++;
      break;
   case DOWN:
      newCol--;
      break;
   case RIGHT:
      newRow--;
      break;
   case LEFT:
      newRow++;
      break;
   default:
      throw "Invalid direction.";
   }

   return Game::getInstance().getBoard().getSquare(newRow, newCol);
}

Square* Square::getUp(Direction direction) const
{
   int newCol = getCol(), newRow = getRow();
   switch (direction)
   {
   case UP:
      newRow++;
      break;
   case DOWN:
      newRow--;
      break;
   case RIGHT:
      newCol++;
      break;
   case LEFT:
      newCol--;
      break;
   default:
      throw "Invalid direction.";
   }

   return Game::getInstance().getBoard().getSquare(newRow, newCol);
}

Square* Square::getDown(Direction direction) const
{
   int newCol = getCol(), newRow = getRow();
   switch (direction)
   {
   case UP:
      newRow--;
      break;
   case DOWN:
      newRow++;
      break;
   case RIGHT:
      newCol--;
      break;
   case LEFT:
      newCol++;
      break;
   default:
      throw "Invalid direction.";
   }

   return Game::getInstance().getBoard().getSquare(newRow, newCol);
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

Square* Square::getAdjacent(int dRow, int dCol)
{
   if (dCol == 0 && dRow == 0) return this;
   dRow += getRow();
   dCol += getCol();
   return Game::getInstance().getBoard().getSquare(dRow, dCol);
}