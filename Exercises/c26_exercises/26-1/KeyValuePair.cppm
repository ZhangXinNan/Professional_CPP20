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



// A partial specialization of KeyValuePair<> for const char* values.
export
template<typename Key>
class KeyValuePair<Key, const char*>
{
public:
	KeyValuePair(const Key& key, const char* value)
		: m_key{ key }
		, m_value{ value }
	{
	}

	const Key& getKey() const { return m_key; }
	void setKey(const Key& key) { m_key = key; }

	const std::string& getValue() const { return m_value; }
	void setValue(const char* value) { m_value = value; }

private:
	Key m_key;
	std::string m_value;
};
