#include <cstddef>

import <stdexcept>;
import <vector>;
import <optional>;
import <utility>;
import <format>;
import <concepts>;

template <typename T>
class Grid
{
public:
	explicit Grid(size_t width = DefaultWidth, size_t height = DefaultHeight);
	virtual ~Grid() = default;

	// Explicitly default a copy constructor and copy assignment operator.
	Grid(const Grid& src) = default;
	Grid& operator=(const Grid& rhs) = default;

	// Explicitly default a move constructor and move assignment operator.
	Grid(Grid&& src) = default;
	Grid& operator=(Grid&& rhs) = default;

	std::optional<T>& at(size_t x, size_t y);
	const std::optional<T>& at(size_t x, size_t y) const;

	size_t getHeight() const { return m_height; }
	size_t getWidth() const { return m_width; }

	static const size_t DefaultWidth{ 10 };
	static const size_t DefaultHeight{ 10 };

private:
	void verifyCoordinate(size_t x, size_t y) const;

	std::vector<std::vector<std::optional<T>>> m_cells;
	size_t m_width{ 0 }, m_height{ 0 };
};

template <typename T>
Grid<T>::Grid(size_t width, size_t height)
	: m_width{ width }
	, m_height{ height }
{
	m_cells.resize(m_width);
	for (auto& column : m_cells) {
		column.resize(m_height);
	}
}

template <typename T>
void Grid<T>::verifyCoordinate(size_t x, size_t y) const
{
	if (x >= m_width) {
		throw std::out_of_range { std::format("{} must be less than {}.", x, m_width) };
	}
	if (y >= m_height) {
		throw std::out_of_range { std::format("{} must be less than {}.", y, m_height) };
	}
}

template <typename T>
const std::optional<T>& Grid<T>::at(size_t x, size_t y) const
{
	verifyCoordinate(x, y);
	return m_cells[x][y];
}

template <typename T>
std::optional<T>& Grid<T>::at(size_t x, size_t y)
{
	return const_cast<std::optional<T>&>(std::as_const(*this).at(x, y));
}





class GamePiece
{
public:
	virtual ~GamePiece() = default;
};






template <std::derived_from<GamePiece> T>
class GameBoard : public Grid<T>
{
public:
	explicit GameBoard(size_t width = Grid<T>::DefaultWidth,
		size_t height = Grid<T>::DefaultHeight);
	void move(size_t xSrc, size_t ySrc, size_t xDest, size_t yDest);
};


template <std::derived_from<GamePiece> T>
GameBoard<T>::GameBoard(size_t width, size_t height)
	: Grid<T>{ width, height }
{
}

template <std::derived_from<GamePiece> T>
void GameBoard<T>::move(size_t xSrc, size_t ySrc, size_t xDest, size_t yDest)
{
	Grid<T>::at(xDest, yDest) = std::move(Grid<T>::at(xSrc, ySrc));
	Grid<T>::at(xSrc, ySrc).reset(); // Reset source cell
	// Or:
	// this->at(xDest, yDest) = std::move(this->at(xSrc, ySrc));
	// this->at(xSrc, ySrc).reset();
}





class ChessPiece : public GamePiece
{
};

int main()
{
	GameBoard<ChessPiece> chessBoard{ 8, 8 };

	ChessPiece pawn;
	chessBoard.at(0, 0) = pawn;
	chessBoard.move(0, 0, 0, 1);
}
