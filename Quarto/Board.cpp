#include "Board.h"

std::optional<Piece> Board::operator[](const Position& point) const
{
	return m_pieces[point.first * kMatrixDimension + point.second];
}

std::optional<Piece>& Board::operator[](const Position& point)
{
	return m_pieces[point.first * kMatrixDimension + point.second];
}

std::ostream& operator<<(std::ostream& os, const Board& board)
{
	Board::Position position;
	for (position.first = 0; position.first < Board::kMatrixDimension; position.first++)
	{
		for (position.second = 0; position.second < Board::kMatrixDimension; position.second++)
		{
			if (board[position])
			{
				os << *board[position];
			}
			else
			{
				os << "____";
			}				
			os << ' ';
		}

		os << std::endl;
	}
	return os;
}
