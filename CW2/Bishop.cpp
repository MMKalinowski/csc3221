#include "Bishop.h"
#include <cmath>
#include <iostream>

int Bishop::captures = 0;

Bishop::Bishop(Position pos, int radius)
: Piece(pos)
, radius(radius)
{}

Position Bishop::move(Displacement d)
{
	if (std::fabs(d.x) != std::fabs(d.y))
	{
		std::cout << "Wrong input for Bishop: Move cancelled!" << std::endl;
		return this->getPos();
	}

	Position p = {
		this->getPos().x + d.x,
		this->getPos().y + d.y
	};

	this->setPos(p);

	return p;
}

bool Bishop::collision([[maybe_unused]] Position other)
{
	return false;
}