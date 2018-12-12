#include "Board.hpp"

#include <iostream>

//randFloat modified from code by Ivan Prodanov, Stack Overflow
float randFloatRange(float a, float b)
{
	return ((b - a) * ((float)rand() / RAND_MAX)) + a;
}

Displacement generateMove(const PieceType t, const Board* b)
{
	int decide = rand() % 2;
	Displacement d;

	switch(t)
	{
		case PieceType::BISHOP:
		{
			float x = randFloatRange(-b->getSize(), b->getSize());
			float y = decide > 0 ? -x : x;

			d.x = x;
			d.y = y;
			return d;
		}
		case PieceType::ROOK:
		{
			float move = randFloatRange(-b->getSize(), b->getSize());

			decide > 0 ? d.x = move : d.y = move;
			decide > 0 ? d.y = 0 : d.x = 0;
			return d;
		}
		case PieceType::QUEEN:
		{
			float x = randFloatRange(-b->getSize(), b->getSize());
			float y = decide > 0 ? -x : x;

			d.x = x;
			d.y = y;
			return d;
		}
	}
}

int main()
{
	std::cout << "Test" << std::endl;

	Board* b = new Board();

	int cycles = 10;

	for(int i = 1; i <= cycles; ++i)
	{
		for(auto p : b->getPieces())
		{
			p->move(generateMove(p->getType(), b));
			std::cout << "Moving " << p->typeToStr() << "from ";
			b->CollisionCheck(p);
		}
	}

	system("pause");
	
	return 0;
}