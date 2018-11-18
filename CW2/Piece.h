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
	//test if works

	virtual bool collision(Position pos) = 0;

	private:
	Position position;
};