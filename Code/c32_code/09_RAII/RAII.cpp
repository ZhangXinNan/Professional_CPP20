#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>

class File final
{
public:
	explicit File(std::FILE* file) : m_file{ file } { }
	~File() { reset(); }

	// Prevent copy construction and copy assignment.
	File(const File& src) = delete;
	File& operator=(const File& rhs) = delete;

	// Allow move construction and move assignment.
	File(File&& src) noexcept = default;
	File& operator=(File&& rhs) noexcept = default;

	// get(), release(), and reset()
	std::FILE* get() const noexcept { return m_file; }

	[[nodiscard]] std::FILE* release() noexcept
	{
		std::FILE* file{ m_file };
		m_file = nullptr;
		return file;
	}
	
	void reset(std::FILE* file = nullptr) noexcept
	{
		if (m_file) { fclose(m_file); }
		m_file = file;
	}

private:
	std::FILE* m_file{ nullptr };
};

int main()
{
	File myFile{ fopen("input.txt", "r") };
}
