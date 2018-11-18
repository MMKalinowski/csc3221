#pragma once

struct Position
{
	float x;
	float y;
};

class Piece
{
	public:
	~Piece() {}

	virtual Position move() = 0;
	virtual bool collision(Position pos) = 0;

	private:
	Position position;
};