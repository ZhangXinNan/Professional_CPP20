module;

#include <cstddef>  // For size_t

export module serial;

export class Serial
{
public:
	Serial() : m_serialNumber{ ms_nextSerial++ } {} // A new object gets a next serial number.
	size_t getSerialNumber() const { return m_serialNumber; }

private:
	static inline size_t ms_nextSerial{ 0 }; // The first serial number is 0.
	size_t m_serialNumber;
};

