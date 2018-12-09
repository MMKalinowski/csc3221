#pragma once
#include "Piece.h"

class Bishop : public Piece
{
	public:
	Bishop(Position pos, int radius = 1);

	Position move(Displacement);
	bool collision(Position other);

	private:
	int radius;
	static int captures;
};