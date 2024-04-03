module;

#include <cstddef>

export module grid:pointers;

import :main;
import <stdexcept>;
import <utility>;
import <memory>;
import <format>;

export
template <typename T>
class Grid<T*>
{
public:
	explicit Grid(size_t width = DefaultWidth, size_t height = DefaultHeight);
	virtual ~Grid() = default;

	// Copy constructor and copy assignment operator.
	Grid(const Grid& src);
	Grid& operator=(const Grid& rhs);

	// Explicitly default a move constructor and move assignment operator.
	Grid(Grid&& src) = default;
	Grid& operator=(Grid&& rhs) = default;

	void swap(Grid& other) noexcept;

	std::unique_ptr<T>& at(size_t x, size_t y);
	const std::unique_ptr<T>& at(size_t x, size_t y) const;

	size_t getHeight() const { return m_height; }
	size_t getWidth() const { return m_width; }

	static const size_t DefaultWidth{ 10 };
	static const size_t DefaultHeight{ 10 };

private:
	void verifyCoordinate(size_t x, size_t y) const;

	std::vector<std::vector<std::unique_ptr<T>>> m_cells;
	size_t m_width { 0 }, m_height { 0 };
};

template <typename T>
Grid<T*>::Grid(size_t width, size_t height)
	: m_width{ width }
	, m_height{ height }
{
	m_cells.resize(m_width);
	for (auto& column : m_cells) {
		column.resize(m_height);
	}
}

template <typename T>
void Grid<T*>::swap(Grid& other) noexcept
{
	using std::swap;

	swap(m_width, other.m_width);
	swap(m_height, other.m_height);
	swap(m_cells, other.m_cells);
}

template <typename T>
Grid<T*>::Grid(const Grid& src)
	: Grid { src.m_width, src.m_height }
{
	// The ctor-initializer of this constructor delegates first to the
	// non-copy constructor to allocate the proper amount of memory.

	// The next step is to copy the data.
	for (size_t i{ 0 }; i < m_width; i++) {
		for (size_t j{ 0 }; j < m_height; j++) {
			// Make a deep copy of the element by using its copy constructor.
			if (src.m_cells[i][j]) {
				m_cells[i][j].reset(new T { *(src.m_cells[i][j]) } );
			}
		}
	}
}

template <typename T>
Grid<T*>& Grid<T*>::operator=(const Grid& rhs)
{
	// Use copy-and-swap idiom.
	auto copy{ rhs };    // Do all the work in a temporary instance
	swap(copy);          // Commit the work with only non-throwing operations
	return *this;
}

template <typename T>
void Grid<T*>::verifyCoordinate(size_t x, size_t y) const
{
	if (x >= m_width) {
		throw std::out_of_range{ std::format("{} must be less than {}.", x, m_width) };
	}
	if (y >= m_height) {
		throw std::out_of_range{ std::format("{} must be less than {}.", y, m_height) };
	}
}

template <typename T>
const std::unique_ptr<T>& Grid<T*>::at(size_t x, size_t y) const
{
	verifyCoordinate(x, y);
	return m_cells[x][y];
}

template <typename T>
std::unique_ptr<T>& Grid<T*>::at(size_t x, size_t y)
{
	return const_cast<std::unique_ptr<T>&>(std::as_const(*this).at(x, y));
}
