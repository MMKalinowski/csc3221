#pragma once
#include "Piece.hpp"

class Queen : public Piece
{
	public:
	Queen(Position pos);

	virtual Position move(Displacement) override;
	virtual bool collision(const Piece* other) const override;

	private:
	static int captures;
};