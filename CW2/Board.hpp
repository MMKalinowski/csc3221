#pragma once
#include "Piece.hpp"

#include <vector>

class Board
{
	public:
		Board();
		Board(const float size, const int pieces);
		~Board();

		float getSize() const;
		int noOfPieces() const;
		std::vector<Piece*> getPieces() const;

		void MovePiece(Piece* const piece, const Displacement d);
		std::string CollisionCheck(const Piece* piece);

	private:
		float size;
		std::vector<Piece*> pieces;
		void AddPiece(const PieceType type, const Position pos);
};