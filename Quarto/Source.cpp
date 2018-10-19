#include "Piece.h"

#include <iostream>
#include "Board.h"

int main()
{
	Piece piece(Piece::Body::Full, Piece::Color::Dark, Piece::Height::Short, Piece::Shape::Square);
	std::cout << "Full, Dark, Short, Square piece: " << piece << std::endl;

	Board board;
	board[{1, 1}] = piece;

	board[{1, 3}] = piece;
	std::cout << board;
		
	return 0;
}
