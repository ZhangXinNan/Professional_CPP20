module;

#include <cstddef>

export module invalid_coordinate;

import <exception>;
import <string>;
import <format>;

export class InvalidCoordinate : public std::exception
{
public:
	InvalidCoordinate(size_t x, size_t y, size_t maxX, size_t maxY)
		: m_x{ x }, m_y{ y }
		, m_maxX{ maxX }, m_maxY{ maxY }
	{
		m_message = std::format("Coordinate ({}, {}) is not within the range ({}, {}) - ({}, {}).",
			m_x, m_y, 0, 0, m_maxX, m_maxY);
	}

	const char* what() const noexcept override
	{
		return m_message.c_str();
	}

private:
	// The invalid coordinate.
	size_t m_x{ 0 }, m_y{ 0 };

	// The maximum X and Y coordinates.
	size_t m_maxX{ 0 }, m_maxY{ 0 };

	// The exception message.
	std::string m_message;
};
