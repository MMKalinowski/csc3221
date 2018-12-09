#pragma once
#include "Piece.h"
#include <vector>

const static int TYPE_NUMBER = 3;

enum class PieceType : int
{
	ROOK,
	BISHOP,
	QUEEN
};

class Board
{
	public:
		Board();
		Board(float size, int pieces);
		~Board();

	private:
		float size;
		std::vector<Piece*> pieces;

		void AddPiece(PieceType type, int size, Position pos);
		void MovePiece(Piece* piece, Displacement d);
};