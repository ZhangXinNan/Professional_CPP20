module;

#include <cstddef>

export module grid:implementation;

import :definition;
import <vector>;
import <optional>;
import <stdexcept>;
import <utility>;
import <format>;

export
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

export
template <typename T>
void Grid<T>::verifyCoordinate(size_t x, size_t y) const
{
	if (x >= m_width) {
		throw std::out_of_range{ std::format("{} must be less than {}.", x, m_width) };
	}
	if (y >= m_height) {
		throw std::out_of_range{ std::format("{} must be less than {}.", y, m_height) };
	}
}

export
template <typename T>
const std::optional<T>& Grid<T>::at(size_t x, size_t y) const
{
	verifyCoordinate(x, y);
	return m_cells[x][y];
}

export
template <typename T>
std::optional<T>& Grid<T>::at(size_t x, size_t y)
{
	return const_cast<std::optional<T>&>(std::as_const(*this).at(x, y));
}
