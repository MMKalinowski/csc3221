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
	float distanceTo(const Position other) const;
};

//semantic differentiation indicating purpose of struct in context
using Displacement = Position;

class Piece
{
	public:
	Piece(Position pos, PieceType typ, Shape sha, int size);

	virtual ~Piece() {};

	virtual Position move(Displacement) = 0;
	virtual bool collision(const Piece* other) const = 0;

	Position getPos() const;
	PieceType getType() const;
	Shape getShape() const;
	int getSize() const;

	std::string toString() const;

	protected:
	void setPos(Position pos);

	private:
	Position position;
	PieceType type;
	Shape shape;
	int size;

	std::string typeToStr() const;
	std::string posToStr() const;
};