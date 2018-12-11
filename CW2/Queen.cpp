#include "Queen.hpp"
#include <iostream>
#include <cmath>

int Queen::captures = 0;

Queen::Queen(Position pos)
: Piece(pos, PieceType::QUEEN, Shape::CIRCLE, 1)
, radius(radius)
{}

Position Queen::move(Displacement d)
{
	// TODO: proper debug needed for edge cases
	if ((std::fabs(d.x) != std::fabs(d.y)) ^ ((d.x != 0 && d.y != 0)))
	{
		std::cout << "Wrong input for Queen: Move cancelled!" << std::endl;
		return this->getPos();
	}

	Position p = {
		this->getPos().x + d.x,
		this->getPos().y + d.y
	};

	this->setPos(p);

	return p;
}

bool Queen::collision(const Piece* other) const
{
	const Position otherPos = other->getPos();
	const int otherSize = other->getSize();
	bool colliding = false;

	switch(other->getShape())
	{
		case Shape::SQUARE:
			if(1==1)
			{

			}
			break;
		case Shape::CIRCLE:
			if(this->getPos().distanceTo(otherPos) < this->getSize() + otherSize)
			{
				colliding = true;
			}
			break;

		default:
			break;
	}
	return colliding;
}