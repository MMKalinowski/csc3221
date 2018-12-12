#pragma once
#include "Piece.hpp"

class Bishop : public Piece
{
	public:
	Bishop(Position pos);

	virtual Position move(Displacement) override;
	virtual bool collision(const Piece* other) const override;

	void captured();

	private:
	static int captures;
};