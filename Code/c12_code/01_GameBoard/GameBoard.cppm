module;

#include <cstddef>

export module game_board;

import <vector>;
import <memory>;

export class GamePiece
{
public:
	virtual ~GamePiece() = default;
	virtual std::unique_ptr<GamePiece> clone() const = 0;
};

export class GameBoard
{
public:
	explicit GameBoard(size_t width = DefaultWidth, size_t height = DefaultHeight);
	GameBoard(const GameBoard& src);   // copy constructor
	virtual ~GameBoard() = default;    // virtual defaulted destructor
	GameBoard& operator=(const GameBoard& rhs); // assignment operator
	
	// Explicitly default a move constructor and move assignment operator.
	GameBoard(GameBoard&& src) = default;
	GameBoard& operator=(GameBoard&& src) = default;

	std::unique_ptr<GamePiece>& at(size_t x, size_t y);
	const std::unique_ptr<GamePiece>& at(size_t x, size_t y) const;

	size_t getHeight() const { return m_height; }
	size_t getWidth() const { return m_width; }

	static const size_t DefaultWidth{ 10 };
	static const size_t DefaultHeight{ 10 };

	void swap(GameBoard& other) noexcept;

private:
	void verifyCoordinate(size_t x, size_t y) const;

	std::vector<std::vector<std::unique_ptr<GamePiece>>> m_cells;
	size_t m_width { 0 }, m_height { 0 };
};

export void swap(GameBoard& first, GameBoard& second) noexcept;
