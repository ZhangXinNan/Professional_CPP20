module;

#include <cstddef>

export module nd_grid; 

import <vector>;

export
template <typename T, size_t N>
class NDGrid
{
public:
	explicit NDGrid(size_t size = DefaultSize) { resize(size); }
	virtual ~NDGrid() = default;

	NDGrid<T, N-1>& operator[](size_t x) { return m_elements[x]; }
	const NDGrid<T, N-1>& operator[](size_t x) const { return m_elements[x]; }

	void resize(size_t newSize)
	{
		m_elements.resize(newSize);

		// Resizing the vector calls the 0-argument constructor for
		// the NDGrid<T, N-1> elements, which constructs
		// it with the default size. Thus, we must explicitly call
		// resize() on each of the elements to recursively resize all
		// nested Grid elements.
		for (auto& element : m_elements) {
			element.resize(newSize);
		}
	}

	size_t getSize() const { return m_elements.size(); }

	static const size_t DefaultSize{ 10 };

private:
	std::vector<NDGrid<T, N-1>> m_elements;
};

export
template <typename T>
class NDGrid<T, 1>
{
public:
	explicit NDGrid(size_t size = DefaultSize) { resize(size); }
	virtual ~NDGrid() = default;

	T& operator[](size_t x) { return m_elements[x]; }
	const T& operator[](size_t x) const { return m_elements[x]; }

	void resize(size_t newSize) { m_elements.resize(newSize); }
	size_t getSize() const { return m_elements.size(); }

	static const size_t DefaultSize{ 10 };

private:
	std::vector<T> m_elements;
};
