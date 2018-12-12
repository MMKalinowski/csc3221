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
	for (auto& p : this->pieces)
	{
		delete p;
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

std::string Board::CollisionCheck(const Piece* piece){
	std::string capt;
	for(auto& p : this->pieces){
		if((piece)->collision(p)){
			capt += piece->toString() + " captured " + p->toString() + "\n";
			piece->captured();
		}
	}
	return capt;
}

void Board::MovePiece(Piece* const piece, const Displacement d)
{
	Position current = piece->getPos();
	Position next = current + d;

	if(next.x < 0 || next.x > this->size)	return;
	if(next.y < 0 || next.y > this->size)	return;

	piece->move(d);
}