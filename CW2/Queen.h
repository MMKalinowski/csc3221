#pragma once
#include "Piece.h"

class Queen : public Piece
{
	public:
	Queen(Position pos, int radius);

	Position move(Displacement);
	bool collision(Position other);

	private:
	int radius;
	static int captures;
};