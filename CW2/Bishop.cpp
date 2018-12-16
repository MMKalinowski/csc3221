//	Author: Maciej Kalinowski
//	Student no: 160473294

#include "Bishop.hpp"
#include <iostream>
#include <cmath>
#include <algorithm>

int Bishop::captures = 0;

Bishop::Bishop(Position pos)
: Piece(pos, PieceType::BISHOP, Shape::CIRCLE, 1)
{}

Position Bishop::move(const Displacement d)
{
	if (!Piece::sameFloat(std::fabs(d.x), std::fabs(d.y)))
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
		{
			const Position botLeft = {
				this->getPos().x - this->getSize(),
				this->getPos().y - this->getSize()
			};
			const Displacement d = {
				otherPos.x - Piece::clip(otherPos.x, botLeft.x, botLeft.x + 2 * this->getSize()),
				otherPos.y - Piece::clip(otherPos.y, botLeft.y, botLeft.y + 2 * this->getSize())
			};

			colliding = (d.x * d.x + d.y * d.y) < (otherSize * otherSize);
			break;
		}
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

void Bishop::captured() const{
	captures++;
}

int Bishop::noOfCaptures(){
	return captures;
}