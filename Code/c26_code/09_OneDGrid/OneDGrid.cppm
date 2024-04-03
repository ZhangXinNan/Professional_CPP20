module;

#include <cstddef>

export module oned_grid;

import <vector>;

export
template <typename T>
class OneDGrid
{
public:
	explicit OneDGrid(size_t size = DefaultSize) { resize(size); }
	virtual ~OneDGrid() = default;

	T& operator[](size_t x) { return m_elements[x]; }
	const T& operator[](size_t x) const { return m_elements[x]; }

	void resize(size_t newSize) { m_elements.resize(newSize); }
	size_t getSize() const { return m_elements.size(); }

	static const size_t DefaultSize{ 10 };

private:
	std::vector<T> m_elements;
};
