module;

#include <cstddef>

export module spreadsheet;

export import spreadsheet_cell;

export class SpreadsheetApplication { };

export class Spreadsheet
{
public:
	Spreadsheet(size_t width, size_t height,
		const SpreadsheetApplication& theApp);
	Spreadsheet(const Spreadsheet& src);
	~Spreadsheet();
	Spreadsheet& operator=(const Spreadsheet& rhs);

	void setCellAt(size_t x, size_t y, const SpreadsheetCell& cell);
	SpreadsheetCell& getCellAt(size_t x, size_t y);

	size_t getId() const;

	void swap(Spreadsheet& other) noexcept;

	static const size_t MaxHeight{ 100 };
	static const size_t MaxWidth{ 100 };

private:
	void verifyCoordinate(size_t x, size_t y) const;

	const size_t m_id{ 0 };
	size_t m_width{ 0 };
	size_t m_height{ 0 };
	SpreadsheetCell** m_cells{ nullptr };

	const SpreadsheetApplication& m_theApp;

	//static size_t ms_counter; // Pre C++17
	static inline size_t ms_counter{ 0 }; // Since C++17
};

export void swap(Spreadsheet& first, Spreadsheet& second) noexcept;
