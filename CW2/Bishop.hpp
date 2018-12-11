#pragma once
#include "Piece.hpp"

class Bishop : public Piece
{
	public:
	Bishop(Position pos, int radius = 1);

	virtual Position move(Displacement) override;
	virtual bool collision(const Position other) const override;

	private:
	int radius;
	static int captures;
};