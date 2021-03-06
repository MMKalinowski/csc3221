//	Author: Maciej Kalinowski
//	Student no: 160473294

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

	Position operator+(const Position& rhs) const;
	Position operator-(const Position& rhs) const;
	bool operator==(const Position& rhs) const;
};

//semantic differentiation indicating purpose of struct in context
using Displacement = Position;

class Piece
{
	public:
	Piece(Position pos, PieceType typ, Shape sha, int size);

	virtual ~Piece() {};

	virtual Position move(const Displacement) = 0;
	virtual bool collision(const Piece* other) const = 0;
	virtual void captured() const = 0;
	virtual Displacement generateMove(int boardSize) const = 0;

	Position getPos() const;
	PieceType getType() const;
	Shape getShape() const;
	int getSize() const;

	std::string toString() const;
	std::string typeToStr() const;
	std::string posToStr() const;

	bool sameFloat(float a, float b) const;
	static float clip(float n, float lower, float upper);

	protected:
	void setPos(Position pos);

	private:
	Position position;
	PieceType type;
	Shape shape;
	int size;
};