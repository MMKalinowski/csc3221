#include "Bishop.hpp"
#include <cmath>
#include <iostream>

int Bishop::captures = 0;

Bishop::Bishop(Position pos)
: Piece(pos, PieceType::BISHOP, Shape::CIRCLE, 1)
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

bool Bishop::collision(const Piece* other) const
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