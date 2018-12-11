#include "Queen.hpp"
#include <iostream>
#include <cmath>

int Queen::captures = 0;

Queen::Queen(Position pos, int radius)
	: Piece(pos, PieceType::QUEEN, Shape::CIRCLE)
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

bool Queen::collision([[maybe_unused]]const Piece* other) const
{
	switch(other->getShape())
	{
		case(Shape::SQUARE):

		break;
		
		case(Shape::CIRCLE):

		break;

		default:
		break;
	}
	return false;
}