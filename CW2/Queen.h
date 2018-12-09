#pragma once
#include "Piece.h"

class Queen : public Piece
{
	public:
	Queen(Position pos, int radius = 1);

	Position move(Displacement);
	bool collision(Position other);

	private:
	int radius;
	static int captures;
};