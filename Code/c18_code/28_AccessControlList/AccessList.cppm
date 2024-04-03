export module access_list;

import <set>;
import <string>;
import <string_view>;
import <vector>;
import <initializer_list>;

export class AccessList final
{
public:
	// Default constructor
	AccessList() = default;

	// Constructor to support uniform initialization.
	AccessList(std::initializer_list<std::string_view> users)
	{
		m_allowed.insert(begin(users), end(users));
	}

	// Adds the user to the permissions list.
	void addUser(std::string user)
	{
		m_allowed.emplace(std::move(user));
	}

	// Removes the user from the permissions list.
	void removeUser(const std::string& user)
	{
		m_allowed.erase(user);
	}

	// Returns true if the user is in the permissions list.
	bool isAllowed(const std::string& user) const
	{
		return (m_allowed.count(user) != 0);
	}

	// Returns a vector of all the users who have permissions.
	std::vector<std::string> getAllUsers() const
	{
		return { begin(m_allowed), end(m_allowed) };
	}

private:
	std::set<std::string> m_allowed;
};
