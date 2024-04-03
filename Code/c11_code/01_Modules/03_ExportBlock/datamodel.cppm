export module datamodel;

import <vector>;

export
{
	namespace DataModel
	{
		class Person { /* ... */ };

		class Address { /* ... */ };

		using Persons = std::vector<Person>;
	}
}
