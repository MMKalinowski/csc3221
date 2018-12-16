//	Author: Maciej Kalinowski
//	Student no: 160473294

#pragma once
#include "Piece.hpp"

class Rook : public Piece
{
	public:
	static int captures;
	
	Rook(Position pos);

	virtual Position move(Displacement) override;
	virtual bool collision(const Piece* other) const override;
	virtual void captured() const override;

	static int noOfCaptures();

	private:
	
};