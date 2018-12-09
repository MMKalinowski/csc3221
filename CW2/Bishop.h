#pragma once
#include "Piece.h"

class Bishop : public Piece
{
	public:
	Bishop(Position pos, int radius = 1);

	virtual Position move(Displacement) override;
	virtual bool collision(Position other) override;

	private:
	int radius;
	static int captures;
};