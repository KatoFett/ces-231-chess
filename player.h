#pragma once
class Player
{
private:
	int color[3];
public:
	Player();
	Player(Direction direction, int color);
	int getColor();
};

enum class Direction {
	UP,
	DOWN,
	LEFT,
	RIGHT
};