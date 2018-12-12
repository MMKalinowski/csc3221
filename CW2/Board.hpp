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
		void MovePiece(Piece* const piece, const Displacement d);
		std::string CollisionCheck(const Piece* piece);
};