#include "Rook.h"
#include <iostream>

int Rook::captures = 0;

Rook::Rook(Position pos, int sideL)
: Piece(pos)
, sideL(sideL)
{}

Position Rook::move(Displacement d)
{
	if (d.x != 0 && d.y != 0)
	{
		std::cout << "Wrong input for Rook: Move cancelled!" << std::endl;
		return this->getPos();
	}

	Position p = this->getPos();
	p.x += d.x;
	p.y += d.y;

	this->setPos(p);

	return p;
}