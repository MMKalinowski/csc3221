#pragma once
#include "Piece.hpp"

class Rook : public Piece
{
	public:
	Rook(Position pos, int sideL = 2);

	virtual Position move(Displacement) override;
	virtual bool collision(Position other) const override;

	private:
	int sideL;
	static int captures;
};