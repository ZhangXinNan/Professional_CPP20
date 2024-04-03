export module key_value_pair;

import <string>;

export
template <typename Key, typename Value>
class KeyValuePair
{
public:
	KeyValuePair(const Key& key, const Value& value)
		: m_key{ key }
		, m_value{ value }
	{
	}

	const Key& getKey() const { return m_key; }
	void setKey(const Key& key) { m_key = key; }

	const Value& getValue() const { return m_value; }
	void setValue(const Value& value) { m_value = value; }

private:
	Key m_key;
	Value m_value;
};



// A full specialization of KeyValuePair<> for const char*s.
export
template<>
class KeyValuePair<const char*, const char*>
{
public:
	KeyValuePair(const char* key, const char* value)
		: m_key{ key }
		, m_value{ value }
	{
	}

	const std::string& getKey() const { return m_key; }
	void setKey(const char* key) { m_key = key; }

	const std::string& getValue() const { return m_value; }
	void setValue(const char* value) { m_value = value; }

private:
	std::string m_key;
	std::string m_value;
};
