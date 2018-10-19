#include "Board.h"

std::optional<Piece> Board::operator[](const Position& point) const
{
	const auto&[line_index, column_index] = point;
	return m_pieces[line_index * kMatrixDimension + column_index];
}

std::optional<Piece>& Board::operator[](const Position& point)
{
	const auto&[line_index, column_index] = point;
	return m_pieces[line_index * kMatrixDimension + column_index];
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
