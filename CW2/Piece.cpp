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

float Position::distanceTo(const Position other) const{
	const Displacement d = {
		this->x - other.x,
		this->y - other.y
	};
	
	return std::sqrt(d.x * d.x + d.y * d.y);
}