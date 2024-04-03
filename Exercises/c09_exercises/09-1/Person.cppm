export module person;

import <string>;
import <format>;
import <iostream>;

export class Person
{
public:
	Person(std::string firstName, std::string lastName) //// Pass by value and move.
		: m_firstName{ std::move(firstName) }, m_lastName{ std::move(lastName) }
	{
	}

	Person() = default;

	// Copy constructor.
	Person(const Person& src)
		: m_firstName{ src.m_firstName }, m_lastName{ src.m_lastName }
	{
		std::cout << "Person copy constructor called." << std::endl;
	}

	// Assignment operator.
	//// Modified to use copy-and-swap to avoid code duplication.
	Person& operator=(const Person& rhs)
	{
		std::cout << "Person assignment operator called." << std::endl;

		auto temp{ rhs };
		swap(temp);
		return *this;
	}

	// Destructor.
	~Person()
	{
		std::cout << "Person destructor called." << std::endl;
	}

	// Move constructor.
	Person(Person&& src) noexcept
	{
		std::cout << "Person move constructor called." << std::endl;
		swap(src);
	}

	// Move assignment operator.
	Person& operator=(Person&& rhs) noexcept
	{
		std::cout << "Person move assignment operator called." << std::endl;
		swap(rhs);
		return *this;
	}

	// swap method.
	//// Added to avoid code duplication
	void swap(Person& other) noexcept
	{
		std::swap(m_firstName, other.m_firstName);
		std::swap(m_lastName, other.m_lastName);
	}

	const std::string& getFirstName() const { return m_firstName; }
	void setFirstName(std::string firstName) { m_firstName = std::move(firstName); } //// Pass by value and move.

	const std::string& getLastName() const { return m_lastName; }
	void setLastName(std::string lastName) { m_lastName = std::move(lastName); } //// Pass by value and move.

private:
	std::string m_firstName;
	std::string m_lastName;
};