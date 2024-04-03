module phone_book;

import <utility>;

using namespace std;

void PhoneBook::addPhoneNumber(const Person& person, string_view phoneNumber)
{
	m_phoneBook.insert(pair{ person, phoneNumber });
}

void PhoneBook::removePhoneNumber(const Person& person, string_view phoneNumber)
{
	auto [begin, end]{ m_phoneBook.equal_range(person) };
	for (auto iter{ begin }; iter != end; ++iter) {
		if (iter->second == phoneNumber) {
			m_phoneBook.erase(iter);
			break;
		}
	}
}

vector<string> PhoneBook::getPhoneNumbers(const Person& person) const
{
	vector<string> phoneNumbers;

	auto [begin, end]{ m_phoneBook.equal_range(person) };
	for (auto iter{ begin }; iter != end; ++iter) {
		phoneNumbers.push_back(iter->second);
	}

	return phoneNumbers;
}
