#pragma once
#include "Piece.h"

class Rook : public Piece
{
	public:
	Rook(Position pos, int sideL = 2);

	Position move(Displacement);
	bool collision(Position other);

	private:
	int sideL;
	static int captures;
};