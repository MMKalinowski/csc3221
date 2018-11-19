#pragma once
#include "Piece.h"

class Rook : public Piece
{
	public:
	Rook(Position pos, int sideL);

	Position move(float x, float y);
	bool collision(Position pos);

	private:
	int sideL = 1;
};