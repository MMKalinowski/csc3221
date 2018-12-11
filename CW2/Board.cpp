#include "Board.hpp"
#include "Rook.hpp"
#include "Bishop.hpp"
#include "Queen.hpp"

Board::Board()
: size(30.0f)
{
	for(int i = 0; i < 5; ++i){
		PieceType type = (PieceType) (i % TYPE_NUMBER);

		Position pos = {
			pos.x = float (std::rand() % (int) size),
			pos.y = float (std::rand() % (int) size)
		};

		AddPiece(type, pos);
	}
}

Board::Board(float size, int pieces)
: size(size)
{
	for (int i = 0; i < pieces; ++i)
	{
		PieceType type = (PieceType) (std::rand() % TYPE_NUMBER);
		
		Position pos = {
			pos.x = float (std::rand() % (int) size),
			pos.y = float (std::rand() % (int) size)
		};

		AddPiece(type, pos);		// TODO: COLLISIONS ON SPAWN!!!
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

void Board::AddPiece(PieceType type, Position pos)
{
	switch (type)
	{
		case PieceType::ROOK:
			this->pieces.emplace_back(new Rook(pos));
			break;
		case PieceType::BISHOP:
			this->pieces.emplace_back(new Bishop(pos));
			break;
		case PieceType::QUEEN:
			this->pieces.emplace_back(new Queen(pos));
			break;
		default:
			break;
	}
	
}

bool Board::CollisionCheck(const Piece* piece){
	for(auto& p : this->pieces){
		if((piece)->collision(p)){
			
		}
	}
	return true;
}