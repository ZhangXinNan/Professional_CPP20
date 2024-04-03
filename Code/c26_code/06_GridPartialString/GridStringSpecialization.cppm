module;

#include <cstddef>

export module grid:string_specialization;

import :main;
import <stdexcept>;
import <optional>;
import <utility>; 
import <string>;
import <format>;

export
template <size_t WIDTH, size_t HEIGHT>
class Grid<const char*, WIDTH, HEIGHT>
{
public:
	Grid() = default;
	virtual ~Grid() = default;

	// Explicitly default a copy constructor and copy assignment operator.
	Grid(const Grid& src) = default;
	Grid& operator=(const Grid & rhs) = default;

	std::optional<std::string>& at(size_t x, size_t y);
	const std::optional<std::string>& at(size_t x, size_t y) const;

	size_t getHeight() const { return HEIGHT; }
	size_t getWidth() const { return WIDTH; }

private:
	void verifyCoordinate(size_t x, size_t y) const;

	std::optional<std::string> m_cells[WIDTH][HEIGHT];
};

template <size_t WIDTH, size_t HEIGHT>
void Grid<const char*, WIDTH, HEIGHT>::verifyCoordinate(size_t x, size_t y) const
{
	if (x >= WIDTH) {
		throw std::out_of_range{ std::format("{} must be less than {}.", x, WIDTH) };
	}
	if (y >= HEIGHT) {
		throw std::out_of_range{ std::format("{} must be less than {}.", y, HEIGHT) };
	}
}

template <size_t WIDTH, size_t HEIGHT>
const std::optional<std::string>& Grid<const char*, WIDTH, HEIGHT>::at(size_t x, size_t y) const
{
	verifyCoordinate(x, y);
	return m_cells[x][y];
}

template <size_t WIDTH, size_t HEIGHT>
std::optional<std::string>& Grid<const char*, WIDTH, HEIGHT>::at(size_t x, size_t y)
{
	return const_cast<std::optional<std::string>&>(std::as_const(*this).at(x, y));
}
