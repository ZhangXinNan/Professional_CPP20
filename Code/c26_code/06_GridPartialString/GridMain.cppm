module;

#include <cstddef>

export module grid:main;

import <stdexcept>;
import <optional>;
import <utility>; 
import <format>;

export
template <typename T, size_t WIDTH, size_t HEIGHT>
class Grid
{
public:
	Grid() = default;
	virtual ~Grid() = default;

	// Explicitly default a copy constructor and copy assignment operator.
	Grid(const Grid& src) = default;
	Grid& operator=(const Grid & rhs) = default;

	std::optional<T>& at(size_t x, size_t y);
	const std::optional<T>& at(size_t x, size_t y) const;

	size_t getHeight() const { return HEIGHT; }
	size_t getWidth() const { return WIDTH; }

private:
	void verifyCoordinate(size_t x, size_t y) const;

	std::optional<T> m_cells[WIDTH][HEIGHT];
};

template <typename T, size_t WIDTH, size_t HEIGHT>
void Grid<T, WIDTH, HEIGHT>::verifyCoordinate(size_t x, size_t y) const
{
	if (x >= WIDTH) {
		throw std::out_of_range{ std::format("{} must be less than {}.", x, WIDTH) };
	}
	if (y >= HEIGHT) {
		throw std::out_of_range{ std::format("{} must be less than {}.", y, HEIGHT) };
	}
}

template <typename T, size_t WIDTH, size_t HEIGHT>
const std::optional<T>& Grid<T, WIDTH, HEIGHT>::at(size_t x, size_t y) const
{
	verifyCoordinate(x, y);
	return m_cells[x][y];
}

template <typename T, size_t WIDTH, size_t HEIGHT>
std::optional<T>& Grid<T, WIDTH, HEIGHT>::at(size_t x, size_t y)
{
	return const_cast<std::optional<T>&>(std::as_const(*this).at(x, y));
}
