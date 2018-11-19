#include "Bishop.h"
#include <cmath>
#include <iostream>

Bishop::Bishop(Position pos, int radius)
: Piece(pos)
, radius(radius)
{}

Position Bishop::move(float x, float y)
{
	if (abs(x) != abs(y))
	{
		std::cout << "Wrong input for Bishop: Move cancelled!" << std::endl;
	}
	else
	{
		Position p = Position();
		p.x = x;
		p.y = y;

		this->setPos(p);
	}

	return this->getPos();
}