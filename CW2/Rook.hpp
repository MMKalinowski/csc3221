#pragma once
#include "Piece.hpp"

class Rook : public Piece
{
	public:
	Rook(Position pos);

	virtual Position move(Displacement) override;
	virtual bool collision(const Piece* other) const override;

	private:
	int sideL;
	static int captures;
};