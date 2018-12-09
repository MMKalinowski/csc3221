#include "Board.h"
#include "Rook.h"
#include "Bishop.h"
#include "Queen.h"

Board::Board()
: size(30.0f)
{
	/*for (auto& c : this->pieces)
	{
		delete c;
	}*/
}

Board::Board(float size, int pieces)
: size(size)
{
	PieceType type;
	float posx = 0;
	float posy = 0;

	for (int i = 0; i < pieces; ++i)
	{
		type = (PieceType) (std::rand() % TYPE_NUMBER);
		posx = float (std::rand() % (int) size);
		posy = float(std::rand() % (int) size);
		
		Position pos = {
			pos.x = posx,
			pos.y = posy
		};

		AddPiece((PieceType) type, 1, pos);		// TODO: COLLISIONS ON SPAWN!!!
	}
	
}

Board::~Board()
{
	//this->pieces.clear();	//<-- check if same behaviour
	for (auto& c : this->pieces)
	{
		delete c;
	}
}

void Board::AddPiece(PieceType type, int psize, Position pos)
{
	switch (type)
	{
		case PieceType::ROOK:
			this->pieces.emplace_back(new Rook(pos, psize));
			break;
		case PieceType::BISHOP:
			this->pieces.emplace_back(new Bishop(pos, psize));
			break;
		case PieceType::QUEEN:
			this->pieces.emplace_back(new Queen(pos, psize));
			break;
		default:
			break;
	}
	
}