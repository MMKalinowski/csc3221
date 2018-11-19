#include "Rook.h"
#include <iostream>

Rook::Rook(Position pos, int sideL)
: Piece(pos)
, sideL(sideL)
{}

Position Rook::move(float x, float y)
{
	if (x != 0 && y != 0)
	{
		std::cout << "Wrong input for Rook: Move cancelled!" << std::endl;
		return this->getPos();
	}

	Position p = Position();
	p.x = x;
	p.y = y;

	this->setPos(p);

	return this->getPos();
}