#pragma once
#include <array>
#include "Piece.h"
#include <optional>



class Board
{

private:
	static const uint8_t kMatrixDimension = 4;
	static const uint8_t kTiles = kMatrixDimension * kMatrixDimension;
	std::array<std::optional<Piece>, kTiles> m_pieces;
	

public:
	using Position = std::pair<uint8_t, uint8_t>;
	// getter
	std::optional<Piece> operator [] (const Position& point) const;
	// setter
	std::optional<Piece>& operator [] (const Position& point);

	friend std::ostream& operator << (std::ostream& os, const Board& board);
};

