//	Author: Maciej Kalinowski
//	Student no: 160473294

#include "Rook.hpp"
#include "fmath.hpp"
#include <iostream>
#include <algorithm>

int Rook::captures = 0;

Rook::Rook(Position pos)
: Piece(pos, PieceType::ROOK, Shape::SQUARE, 1)
{}

Position Rook::move(const Displacement d)
{
	//not using sameFloat since 0 can be represented as a direct power of 2
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

//important: check if this piece collides with other piece when this was moved
bool Rook::collision(const Piece* other) const
{
	const Position otherPos = other->getPos();
	const int otherSize = other->getSize();

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
				return false;
			}
			
			if(topLeft.y < otherBotRight.y || otherTopLeft.y < botRight.y)
			{
				return false;
			}

			return true;
		}
		case Shape::CIRCLE:
		{
			const Position botLeft = {
				this->getPos().x - this->getSize(),
				this->getPos().y - this->getSize()
			};
			const Displacement d = {
				otherPos.x - Piece::clip(otherPos.x, botLeft.x, botLeft.x + 2 * this->getSize()),
				otherPos.y - Piece::clip(otherPos.y, botLeft.y, botLeft.y + 2 * this->getSize())
			};

			return (d.x * d.x + d.y * d.y) < (otherSize * otherSize);
		}
		default:
			break;
	}
	return false;
}

void Rook::captured() const
{
	captures++;
}

Displacement Rook::generateMove(int boardSize) const
{
	Displacement d;
	int decide = std::rand() % 2;

	float move = fmath::randFloatRange(-boardSize, boardSize);

	decide > 0 ? d.x = move : d.y = move;
	decide > 0 ? d.y = 0 : d.x = 0;
	return d;
}

int Rook::noOfCaptures(){
	return captures;
}