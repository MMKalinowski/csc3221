//	Author: Maciej Kalinowski
//	Student no: 160473294

#include "Piece.hpp"
#include <cmath>

Piece::Piece(Position pos, PieceType typ, Shape sha, int size)
: position(pos)
, type(typ)
, shape(sha)
, size(size)
{}

void Piece::setPos(Position pos)
{
	this->position = pos;
}

Position Piece::getPos() const
{
	return this->position;
}

PieceType Piece::getType() const
{
	return this->type;
}

Shape Piece::getShape() const
{
	return this->shape;
}

int Piece::getSize() const
{
	return this->size;
}

std::string Piece::toString() const
{
	std::string print;

	print += this->typeToStr();
	print += " at position ";
	print += this->posToStr();

	return print;
}

std::string Piece::typeToStr() const
{
	std::string print;

	switch(this->type)
	{
		case PieceType::BISHOP:
			print = "Bishop";
			break;
		case PieceType::QUEEN:
			print = "Queen";
			break;
		case PieceType::ROOK:
			print = "Rook";
			break;
	}

	return print;
}

std::string Piece::posToStr() const
{
	std::string print;

	print += "(" + std::to_string(this->position.x) + ", " + std::to_string(this->position.y) + ")";

	return print;
}

bool Piece::sameFloat(float a, float b) const
{
	bool x;
	float aAbs = std::fabs(a);
	float bAbs = std::fabs(b);
		
	(std::fabs(aAbs-bAbs) < DELTA_FLOAT) ? x = true : x = false;
	
	return x;
}

float Position::distanceTo(const Position other) const
{
	const Displacement d = {
		this->x - other.x,
		this->y - other.y
	};
	
	return std::sqrt(d.x * d.x + d.y * d.y);
}

Position Position::operator+(const Position& rhs) const
{
	return Position{ rhs.x+this->x, rhs.y+this->y };
}

bool Position::operator==(const Position& rhs) const
{
	return (this->x == rhs.x && this->y == rhs.y);
}

float Piece::clip(float n, float lower, float upper) {
  return std::max(lower, std::min(n, upper));
}