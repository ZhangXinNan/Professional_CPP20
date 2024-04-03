module;

#include <cstddef>

export module matrix;

import <iostream>;
import <new>;
import <exception>;

export template <typename T>
class Matrix
{
public:
	Matrix(size_t width, size_t height);
	virtual ~Matrix();

private:
	void cleanup();

	size_t m_width{ 0 };
	size_t m_height{ 0 };
	T** m_matrix{ nullptr };
};

template <typename T>
Matrix<T>::Matrix(size_t width, size_t height)
{
	m_matrix = new T*[width] {};	// Array is zero-initialized!

	// Don't initialize the m_width and m_height members in the ctor-
	// initializer. These should only be initialized when the above
	// m_matrix allocation succeeds!
	m_width = width;
	m_height = height;

	try {
		for (size_t i{ 0 }; i < width; ++i) {
			m_matrix[i] = new T[height];
		}
	} catch (...) {
		std::cerr << "Exception caught in constructor, cleaning up..." << std::endl;
		cleanup();
		// Nest any caught exception inside a bad_alloc exception.
		std::throw_with_nested(std::bad_alloc{});
	}
}

template <typename T>
Matrix<T>::~Matrix()
{
	cleanup();
}

template <typename T>
void Matrix<T>::cleanup()
{
	for (size_t i{ 0 }; i < m_width; ++i) {
		delete[] m_matrix[i];
	}
	delete[] m_matrix;
	m_matrix = nullptr;
	m_width = m_height = 0;
}
