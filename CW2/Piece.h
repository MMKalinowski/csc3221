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

	virtual int move() = 0;
	virtual bool collision() = 0;

	private:
	Position position;
};