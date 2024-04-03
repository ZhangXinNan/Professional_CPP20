export module key_value_pair;

import <concepts>;

export
template <std::integral Key, std::floating_point Value>
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
