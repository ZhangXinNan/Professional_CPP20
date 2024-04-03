module;

#include <cstddef>

export module spreadsheet;

export import spreadsheet_cell;
import <memory>;

export class SpreadsheetApplication { };

export class Spreadsheet
{
public:
	Spreadsheet(const SpreadsheetApplication& theApp,
		size_t width = MaxWidth, size_t height = MaxHeight);
	Spreadsheet(const Spreadsheet& src);
	Spreadsheet(Spreadsheet&&) noexcept;
	~Spreadsheet();

	Spreadsheet& operator=(const Spreadsheet& rhs);
	Spreadsheet& operator=(Spreadsheet&&) noexcept;
	
	void setCellAt(size_t x, size_t y, const SpreadsheetCell& cell);
	SpreadsheetCell& getCellAt(size_t x, size_t y);
	
	size_t getId() const;

	static const size_t MaxHeight{ 100 };
	static const size_t MaxWidth{ 100 };

	void swap(Spreadsheet& other) noexcept;

private:
	class Impl;
	std::unique_ptr<Impl> m_impl;
};

export void swap(Spreadsheet& first, Spreadsheet& second) noexcept;
