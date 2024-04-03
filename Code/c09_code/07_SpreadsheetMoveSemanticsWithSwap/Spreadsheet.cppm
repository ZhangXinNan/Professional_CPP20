module;

#include <cstddef>

export module spreadsheet;

export import spreadsheet_cell;

export class Spreadsheet
{
public:
	Spreadsheet(size_t width, size_t height);
	Spreadsheet(const Spreadsheet& src);
	Spreadsheet(Spreadsheet&& src) noexcept; // Move constructor
	~Spreadsheet();

	Spreadsheet& operator=(const Spreadsheet& rhs);
	Spreadsheet& operator=(Spreadsheet&& rhs) noexcept;  // Move assignment

	void setCellAt(size_t x, size_t y, const SpreadsheetCell& cell);
	SpreadsheetCell& getCellAt(size_t x, size_t y);

	void swap(Spreadsheet& other) noexcept;

private:
	void verifyCoordinate(size_t x, size_t y) const;

	size_t m_width{ 0 };
	size_t m_height{ 0 };
	SpreadsheetCell** m_cells{ nullptr };
};

export void swap(Spreadsheet& first, Spreadsheet& second) noexcept;
