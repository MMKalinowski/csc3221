#pragma once
#include <string>
struct Position
{
	float x;
	float y;
};

using Displacement = Position;

class Piece
{
	public:
	Piece(Position pos)
	: position(pos)
	{}

	~Piece() {}

	virtual Position move(Displacement) = 0;
	virtual bool collision(Position other) = 0;

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