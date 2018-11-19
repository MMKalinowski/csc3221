#pragma once
#include "Piece.h"

class Bishop : public Piece
{
	public:
	Bishop(Position pos, int radius);

	Position move(Displacement);
	bool collision(Position other);

	private:
	int radius = 1;
	static int captures;
};