#include "square.h"
#include "game.h"
#include "board.h"
#include "direction.h"
#include <stdexcept>
#include <string>

using namespace std;

/* 
* GET NOTATION
* Gets the algebraic notation that refers to this square, e.g. "A1".
*/
string Square::getNotation() const
{
   char colLetter = 97 + getCol();
   char rankNum = 49 + getRow();
   return string({ colLetter, rankNum });
}

/*
* GET LEFT
* Gets the square left of this one relative to the player.
* Allows out of bounds for robustness and returns nullptr if the square doesn't exist.
* Parameters:
*    direction: The direction of the player.
*    distance: How many squares away to check.
*/
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

/*
* GET RIGHT
* Gets the square right of this one relative to the player.
* Allows out of bounds for robustness and returns nullptr if the square doesn't exist.
* Parameters:
*    direction: The direction of the player.
*    distance: How many squares away to check.
*/
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

/*
* GET UP
* Gets the square above this one relative to the player.
* Allows out of bounds for robustness and returns nullptr if the square doesn't exist.
* Parameters:
*    direction: The direction of the player.
*    distance: How many squares away to check.
*/
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

/*
* GET DOWN
* Gets the square below this one relative to the player.
* Allows out of bounds for robustness and returns nullptr if the square doesn't exist.
* Parameters:
*    direction: The direction of the player.
*    distance: How many squares away to check.
*/
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

/*
* GET ADJACENT
* Gets the square offset by the provided delta row and delta column.
* Allows out of bounds for robustness and returns nullptr if the square doesn't exist.
* Parameters:
*    dRow: The vertical delta. Positive is up.
*    dCol: The horizontal delta. Positive is right.
*/
Square* Square::getAdjacent(int dRow, int dCol) const
{
   dRow += getRow();
   dCol += getCol();
   return Game::getInstance().getBoard().getSquare(dRow, dCol);
}

/*
* GET COL
* Gets the column index of this square.
*/
int Square::getCol() const
{
   int width = Game::getInstance().getBoard().getWidth();
   return index % width;
}

/*
* GET ROW
* Gets the row index of this square.
*/
int Square::getRow() const
{
   int width = Game::getInstance().getBoard().getWidth();
   return index / width;
}
