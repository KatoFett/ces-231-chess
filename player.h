#pragma once
#include "piece.h"
#include "set"
class Player
{
protected:
	Direction direction;
	int color[3];
	std::set<Piece> pieces;
public:
	Player();
	Player(Direction direction, int color[3]);
	int getColor();
	void addPiece(Piece& piece);
	void removePiece(Piece& piece);
};

enum Direction {
	UP,
	DOWN,
	LEFT,
	RIGHT
};