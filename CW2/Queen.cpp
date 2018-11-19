#include "Queen.h"
#include <iostream>

int Queen::captures = 0;

Queen::Queen(Position pos, int radius)
	: Piece(pos)
	, radius(radius)
{}

Position Queen::move(Displacement d)
{
	// TODO: proper debug needed for edge cases
	if ((abs(d.x) != abs(d.y)) ^ ((d.x != 0 && d.y != 0)))
	{
		std::cout << "Wrong input for Queen: Move cancelled!" << std::endl;
		return this->getPos();
	}

	Position p = Position();
	p.x += d.x;
	p.y += d.y;

	this->setPos(p);

	return p;
}