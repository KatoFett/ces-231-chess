#include "square.h"
#include "game.h"
#include "board.h"
#include "direction.h"
#include <stdexcept>

using namespace std;

Square* Square::getLeft(Direction direction) const
{
   int newCol = col, newRow = row;
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

   return Game::getInstance().getBoard().getSquare(newCol, newRow);
}

Square* Square::getRight(Direction direction) const
{
   int newCol = col, newRow = row;
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

   return Game::getInstance().getBoard().getSquare(newCol, newRow);
}

Square* Square::getUp(Direction direction) const
{
   int newCol = col, newRow = row;
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

   return Game::getInstance().getBoard().getSquare(newCol, newRow);
}

Square* Square::getDown(Direction direction) const
{
   int newCol = col, newRow = row;
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

   return Game::getInstance().getBoard().getSquare(newCol, newRow);
}