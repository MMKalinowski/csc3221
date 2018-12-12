//	Author: Maciej Kalinowski
//	Student no: 160473294

#include "Board.hpp"
#include "Rook.hpp"
#include "Bishop.hpp"
#include "Queen.hpp"

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
			if(decide > 0)
			{
				int direction = rand() % 2;
				float x = randFloatRange(-b->getSize(), b->getSize());
				float y = direction > 0 ? -x : x;

				d.x = x;
				d.y = y;
				return d;
			}
			else
			{
				int direction = rand() % 2;
				float move = randFloatRange(-b->getSize(), b->getSize());

				direction > 0 ? d.x = move : d.y = move;
				direction > 0 ? d.y = 0 : d.x = 0;
				return d;
			}
			
		}
	}
}

void exampleSmall()
{
	Board* b = new Board();

	int cycles = 1000;

	std::cout << std::endl << "////// GAME BEGUN \\\\\\\\\\\\" << std::endl;

	for(int i = 1; i <= cycles; ++i)
	{
		if(b->noOfPieces() < 2)
		{
			break;
		}

		std::cout << "--- Beginning cycle " << i << " ---" << std::endl; 
		for(int j = 0; j < b->noOfPieces(); ++j)
		{
			std::string initPos = b->getPieces()[j]->posToStr();
			b->MovePiece(b->getPieces()[j], generateMove(b->getPieces()[j]->getType(), b));
			
			std::cout << "Moving " << b->getPieces()[j]->typeToStr() << " from " << initPos << " to " << b->getPieces()[j]->posToStr() << std::endl;
			std::string cap = b->CollisionCheck(b->getPieces()[j]);
			
			if(cap.length() == 0)
			{
				continue;
			}

			std::cout << cap; 
		}
	}

	std::cout << "\\\\\\\\\\\\ GAME ENDED //////" << std::endl;

	std::cout << "SUMMARY: " << std::endl;
	std::cout << "Rooks captured "<< Rook::captures << " pieces." << std::endl;
	std::cout << "Bishops captured "<< Bishop::captures << " pieces." << std::endl;
	std::cout << "Queens captured "<< Queen::captures << " pieces." << std::endl;

	delete b;

	
}

void exampleLarge()
{
	int cycles = 1000;
	int pieces = 100;

	Board* b = new Board(pieces, pieces);

	std::cout << std::endl << "////// GAME BEGUN \\\\\\\\\\\\" << std::endl;

	for(int i = 1; i <= cycles; ++i)
	{
		if(b->noOfPieces() < 2)
		{
			break;
		}

		std::cout << "--- Beginning cycle " << i << " ---" << std::endl; 
		for(int j = 0; j < b->noOfPieces(); ++j)
		{
			std::string initPos = b->getPieces()[j]->posToStr();
			b->MovePiece(b->getPieces()[j], generateMove(b->getPieces()[j]->getType(), b));
			
			std::cout << "Moving " << b->getPieces()[j]->typeToStr() << " from " << initPos << " to " << b->getPieces()[j]->posToStr() << std::endl;
			std::string cap = b->CollisionCheck(b->getPieces()[j]);
			
			if(cap.length() == 0)
			{
				continue;
			}

			std::cout << cap; 
		}
	}

	std::cout << "\\\\\\\\\\\\ GAME ENDED //////" << std::endl;

	std::cout << "SUMMARY: " << std::endl;
	std::cout << "Rooks captured "<< Rook::captures << " pieces." << std::endl;
	std::cout << "Bishops captured "<< Bishop::captures << " pieces." << std::endl;
	std::cout << "Queens captured "<< Queen::captures << " pieces." << std::endl;

	delete b;
}

int main()
{
	while (true)
	{
		int x;
		std::cout << "choose small [0] or large [1] example: ";
		std::cin >> x;
		switch(x)
		{
			case 0:
				exampleSmall();
				break;
			case 1:
				exampleLarge();
				break;
			default:
				std::cout << std::endl << "please input valid int next time.";
				break;
		}
	}
	system("pause");
	
	return 0;
}