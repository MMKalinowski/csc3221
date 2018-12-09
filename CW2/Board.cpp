#include "Board.h"
#include "Rook.h"
#include "Bishop.h"
#include "Queen.h"

Board::Board()
{

}

Board::Board(float size, int pieces)
: size(size)
{
	int type = 0;
	int posx = 0;
	int posy = 0;

	for (int i = 0; i < pieces; ++i)
	{
		type = std::rand() % 3;
		posx = std::rand() % (int)size;
		posy = std::rand() % (int)size;
		
		Position pos = {
			pos.x = posx,
			pos.y = posy
		};

		AddPiece(type, 1, pos);
	}
	
}

Board::~Board()
{
	//this->pieces.clear();
	for (auto& c : this->pieces)
	{
		delete c;
	}
}

// 0 - Rook
// 1 - Bishop
// 2 - Queen
void Board::AddPiece(int type, int size, Position pos)
{
	switch (type)
	{
		case 0:
			this->pieces.emplace_back(new Rook(pos, size));
			break;
		case 1:
			this->pieces.emplace_back(new Bishop(pos, size));
			break;
		case 2:
			this->pieces.emplace_back(new Queen(pos, size));
			break;
		default:
			break;
	}
	
}