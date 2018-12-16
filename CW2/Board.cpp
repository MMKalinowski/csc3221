//	Author: Maciej Kalinowski
//	Student no: 160473294

#include "Board.hpp"
#include "Rook.hpp"
#include "Bishop.hpp"
#include "Queen.hpp"

#include <algorithm>

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
	//for(auto& p : this->pieces)
	for(int i = 0; i < this->noOfPieces(); ++i)
	{
		//change to operator override in Piece
		if(piece == this->pieces[i])
		{
			continue;
		}

		if((piece)->collision(pieces[i])){
			std::vector<Piece*>::iterator it = std::find(this->pieces.begin(), this->pieces.end(), pieces[i]);
			capt += "!!!!!!!!!!!\n";
			capt += piece->toString() + " captured " + this->pieces[i]->toString() + "\n";
			this->pieces.erase(it);
			piece->captured();
			capt += "!!!!!!!!!!!\n";
		}
	}
	return capt;
}

void Board::MovePiece(Piece* const piece, const Displacement d)
{
	Position current = piece->getPos();
	Position next = current + d;

	//if(next.x < 0 || next.x > this->size)	
	next.x = Piece::clip(next.x, .0f, (float)this->size);
	//if(next.y < 0 || next.y > this->size)
	next.y = Piece::clip(next.y, .0f, (float)this->size);

	next = next - current;

	piece->move(next);
}

float Board::getSize() const
{
	return this->size;
}

int Board::noOfPieces() const
{
	return pieces.size();
}

std::vector<Piece*> Board::getPieces() const
{
	return pieces;
}