#include "Piece.h"

Piece::Piece(Position pos)
: position(pos)
{}

Position Piece::getPos() const
{
	return position;
}

void Piece::setPos(Position pos)
{
	this->position = pos;
}