#pragma once
#include "Piece.hpp"
#include <vector>

class Board
{
	public:
		Board();
		Board(const float size, const int pieces);
		~Board();

	private:
		float size;
		std::vector<Piece*> pieces;

		void AddPiece(const PieceType type, const Position pos);
		void MovePiece(const Piece* piece, const Displacement d);
		bool CollisionCheck(const Piece* piece);
};