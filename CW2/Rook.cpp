#include "Rook.hpp"
#include <iostream>

int Rook::captures = 0;

Rook::Rook(Position pos)
: Piece(pos, PieceType::ROOK, Shape::SQUARE, 1)
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

bool Rook::collision(const Piece* other) const
{
	const Position otherPos = other->getPos();
	const int otherSize = other->getSize();
	bool colliding = false;

	switch(other->getShape())
	{
		case Shape::SQUARE:
		{
			const Position topLeft = {
				this->getPos().x - this->getSize(),
				this->getPos().y + this->getSize()
			};
			const Position botRight = {
				this->getPos().x + this->getSize(),
				this->getPos().y - this->getSize()
			};
			const Position otherTopLeft = {
				otherPos.x - otherSize,
				otherPos.y + otherSize
			};
			const Position otherBotRight = {
				otherPos.x + otherSize,
				otherPos.y - otherSize
			};

			if(topLeft.x > otherBotRight.x || otherTopLeft.x > botRight.x)
			{
				break;
			}
			
			if(topLeft.y < otherBotRight.y || otherTopLeft.y < botRight.y)
			{
				break;
			}
			
			colliding = true;
			break;
		}
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