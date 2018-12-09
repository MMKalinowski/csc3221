#pragma once
#include <string>
struct Position
{
	float x;
	float y;
};

//semantic differentiation indicating purpose of struct in context
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

	Position getPos() const
	{
		return position;
	}

	protected:
	void setPos(Position pos)
	{
		this->position = pos;
	}

	private:
	Position position;
};