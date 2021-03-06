//	Author: Maciej Kalinowski
//	Student no: 160473294

#pragma once
#include "Piece.hpp"

class Bishop : public Piece
{
	public:
	static int captures;
	
	Bishop(Position pos);

	virtual Position move(Displacement) override;
	virtual bool collision(const Piece* other) const override;
	virtual void captured() const override;
	virtual Displacement generateMove() const override;

	static int noOfCaptures();

	private:
};