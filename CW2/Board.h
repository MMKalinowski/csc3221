#pragma once
#include "Piece.h"
#include <vector>

class Board
{
	public:
		Board();
		Board(float size, int pieces);

	private:
		float size;
		std::vector<Piece*> pieces;
};