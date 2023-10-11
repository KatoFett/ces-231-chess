#include "rook.h"
#include "game.h"
#include  "board.h"
#include "square.h"
#include <set>

using namespace std;

const char* Rook::NAME = "ROOK";

set<Square*> Rook::getMoves() const
{	
	Board board = Game::getInstance().getBoard();
	Direction direction = player.getDirection();
	int i = 1;

	set<Square*> moves;

    //Or statements to check if checks should continue once all false while is false
    bool first = true, second = true, third = true, fourth = true;
    bool doneChecking = (first || second) || (third || fourth);

    while (doneChecking) {
        Square* up = board.getSquare(square->getRow(), square->getCol() + i);
        //Check until piece is or boundary is found
        if (up != nullptr && up->getPiece() == nullptr)
            moves.insert(up);
        //If piece and not boundary add. Sets dont allow for duplicate values so should work
        if (up != nullptr && up->getPiece() != nullptr)
            moves.insert(up);
	    first = false; 
        else {
             first = false; // set 1/4 of checks to false
        }
        Square* down = board.getSquare(square->getRow(), square->getCol() - i);
        if (down != nullptr && down->getPiece() == nullptr)
            moves.insert(down);
        if (down != nullptr && down->getPiece() != nullptr)
            moves.insert(down);
	    second = false; 
        else {
             second = false; // set 1/4 of checks to false
        }
        Square* left = board.getSquare(square->getRow() - i, square->getCol());
        if (left != nullptr && left->getPiece() == nullptr)
            moves.insert(left);
        if (left != nullptr && left->getPiece() != nullptr)
            moves.insert(left);
            third = false; 
        else {
             third = false; // set 1/4 of checks to false
        }
        Square* right = board.getSquare(square->getRow() + i, square->getCol());
        if (right != nullptr && right->getPiece() == nullptr)
            moves.insert(right);
        if (right != nullptr && right->getPiece() != nullptr)
            moves.insert(right);
            fourth = false; 
        else {
             fourth = false; // set 1/4 of checks to false
        }
        i++;  // Increment i to check the next square
    }
	
	return set<Square*>();
}
