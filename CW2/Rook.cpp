#include "Rook.hpp"
#include <iostream>

int Rook::captures = 0;

Rook::Rook(Position pos, int sideL)
: Piece(pos, PieceType::ROOK, Shape::SQUARE)
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

bool Rook::collision([[maybe_unused]]const Piece* other) const
{
	const Position otherPos = other->getPos();
	bool colliding = false;

	switch(other->getShape())
	{
		case Shape::SQUARE:
			if(1==1)
			{

			}
			break;
		case Shape::CIRCLE:
			// if(this->getPos().distanceTo(otherPos) < this->getSize() + other->getSize())
			// {
			// 	colliding = true;
			// }
			break;

		default:
			break;
	}
	return colliding;
}