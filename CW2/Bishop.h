#pragma once
#include "Piece.h"

class Bishop : public Piece
{
	public:
	Bishop(Position pos, int radius);

	Position move(float x, float y);
	bool collision(Position pos);

	private:
	int radius = 1;
};