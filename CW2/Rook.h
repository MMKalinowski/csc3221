#pragma once
#include "Piece.h"

class Rook : public Piece
{
	public:
	Rook(Position pos, int sideL);

	Position move(Displacement);
	bool collision(Position other);

	private:
	int sideL = 1;
	static int captures;
};