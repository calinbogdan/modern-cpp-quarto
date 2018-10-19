#include "Board.h"

std::optional<Piece> Board::operator[](const Position& point) const
{
	const auto&[line_index, column_index] = point; // structured binding
	return m_pieces[line_index * kMatrixDimension + column_index];
}

std::optional<Piece>& Board::operator[](const Position& point)
{
	const auto&[line_index, column_index] = point; // structured binding
	return m_pieces[line_index * kMatrixDimension + column_index];
}

std::ostream& operator<<(std::ostream& os, const Board& board)
{
	Board::Position position;
	auto&[line_index, column_index] = position; // structured binding
	for (line_index = 0; line_index < Board::kMatrixDimension; line_index++)
	{
		for (column_index = 0; column_index < Board::kMatrixDimension; column_index++)
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
