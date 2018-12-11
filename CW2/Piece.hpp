#pragma once
#include <string>

const static int TYPE_NUMBER = 3;

enum class PieceType : int
{
	ROOK,
	BISHOP,
	QUEEN
};

enum class Shape : int
{
	SQUARE,
	CIRCLE
};

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
	Piece(Position pos);

	virtual ~Piece() {};

	virtual Position move(Displacement) = 0;
	virtual bool collision(const Position other) const = 0;

	Position getPos() const;

	protected:
	void setPos(Position pos);

	private:
	Position position;
};