#pragma once
#include "Piece.h"
#include <vector>

class Board
{
	public:
		Board();
		Board(float size, int pieces);
		~Board();

	private:
		float size;
		std::vector<Piece*> pieces;

		void AddPiece(int type, int size, Position pos);
		void MovePiece(Piece* piece, Displacement d);
};