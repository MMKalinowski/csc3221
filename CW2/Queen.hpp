#pragma once
#include "Piece.hpp"

class Queen : public Piece
{
	public:
	Queen(Position pos, int radius = 1);

	virtual Position move(Displacement) override;
	virtual bool collision(const Piece* other) const override;

	private:
	int radius;
	static int captures;
};