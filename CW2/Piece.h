#pragma once
#include <string>
struct Position
{
	float x;
	float y;
};

class Piece
{
	public:
	Piece(Position pos)
	: position(pos)
	{}

	~Piece() {}

	virtual Position move() = 0;
	virtual bool collision(Position pos) = 0;

	Position getPos()
	{
		return position;
	}

	protected:
	void setPos(Position pos)
	{
		this->position.x = pos.x;
		this->position.y = pos.y;
	}

	private:
	Position position;
};