module;

#include <cstddef>

export module grid;

import <stdexcept>;
import <vector>;
import <optional>;
import <utility>;
import <algorithm>;
import <format>;

// Forward declare Grid template.
export template <typename T> class Grid;

// Prototype for templatized operator+.
export
template<typename T>
Grid<T> operator+(const Grid<T>& lhs, const Grid<T>& rhs);

export
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

	friend Grid operator+<T>(const Grid& lhs, const Grid& rhs);

private:
	void verifyCoordinate(size_t x, size_t y) const;

	std::vector<std::vector<std::optional<T>>> m_cells;
	size_t m_width { 0 }, m_height { 0 };
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

export
template <typename T>
Grid<T> operator+(const Grid<T>& lhs, const Grid<T>& rhs)
{
	size_t minWidth{ std::min(lhs.getWidth(), rhs.getWidth()) };
	size_t minHeight{ std::min(lhs.getHeight(), rhs.getHeight()) };

	Grid<T> result{ minWidth, minHeight };
	for (size_t y{ 0 }; y < minHeight; ++y) {
		for (size_t x{ 0 }; x < minWidth; ++x) {
			const auto& leftElement{ lhs.m_cells[x][y] };
			const auto& rightElement{ rhs.m_cells[x][y] };
			if (leftElement.has_value() && rightElement.has_value()) {
				result.at(x, y) = leftElement.value() + rightElement.value();
			}
		}
	}

	return result;
}
