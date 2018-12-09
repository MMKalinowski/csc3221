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

	Position p = {
		this->getPos().x + d.x,
		this->getPos().y + d.y
	};

	this->setPos(p);

	return p;
}

bool Rook::collision([[maybe_unused]]Position other)
{
	return false;
}