//	Author: Maciej Kalinowski
//	Student no: 160473294

#pragma once
#include "Piece.hpp"

class Queen : public Piece
{
	public:
	static int captures;	

	Queen(Position pos);

	virtual Position move(Displacement) override;
	virtual bool collision(const Piece* other) const override;
	virtual void captured() const override;

	static int noOfCaptures();

	private:
	
};