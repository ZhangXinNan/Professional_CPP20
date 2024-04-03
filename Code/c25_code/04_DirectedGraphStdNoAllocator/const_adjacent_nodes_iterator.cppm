module;

#include <cstddef>

export module directed_graph:const_adjacent_nodes_iterator;

import <iterator>;
import <set>;

namespace ProCpp
{

	template<typename GraphType>
	class const_adjacent_nodes_iterator
	{
	public:
		using value_type = typename GraphType::value_type;
		using difference_type = ptrdiff_t;
		using iterator_category = std::bidirectional_iterator_tag;
		using pointer = const value_type*;
		using reference = const value_type&;
		using iterator_type = std::set<size_t>::const_iterator;

		// Bidirectional iterators must supply a default constructor.
		// In this case, the default-constructed iterator serves as an
		// end iterator.
		const_adjacent_nodes_iterator() = default;

		// No transfer of ownership of graph.
		const_adjacent_nodes_iterator(iterator_type it, const GraphType* graph);

		reference operator*() const;

		// Return type must be something to which -> can be applied.
		// Return a pointer to a node, to which the compiler
		// will apply -> again.
		pointer operator->() const;

		const_adjacent_nodes_iterator& operator++();
		const_adjacent_nodes_iterator operator++(int);

		const_adjacent_nodes_iterator& operator--();
		const_adjacent_nodes_iterator operator--(int);

		// The following are ok as member functions because we don't
		// support comparisons of different types to this one.
		bool operator==(const const_adjacent_nodes_iterator& rhs) const;
		bool operator!=(const const_adjacent_nodes_iterator& rhs) const;

	protected:
		iterator_type m_adjacentNodeIterator;
		// If nullptr, then this instance is an end iterator.
		const GraphType* m_graph{ nullptr };

		// Helper methods for operator++ and operator--
		void increment();
		void decrement();
	};

	template<typename GraphType>
	const_adjacent_nodes_iterator<GraphType>::const_adjacent_nodes_iterator(
		iterator_type it, const GraphType* graph)
		: m_adjacentNodeIterator{ it }, m_graph{ graph }
	{
	}

	// Return a reference to the node.
	template<typename GraphType>
	typename const_adjacent_nodes_iterator<GraphType>::reference
		const_adjacent_nodes_iterator<GraphType>::operator*() const
	{
		// Return an reference to the actual node, not the index to the node.
		return (*m_graph)[*m_adjacentNodeIterator];
	}

	// Return a pointer to the actual node, so the compiler can
	// apply -> to it to access the actual desired field.
	template<typename GraphType>
	typename const_adjacent_nodes_iterator<GraphType>::pointer
		const_adjacent_nodes_iterator<GraphType>::operator->() const
	{
		return &((*m_graph)[*m_adjacentNodeIterator]);
	}

	// Defer the details to the increment() helper.
	template<typename GraphType>
	const_adjacent_nodes_iterator<GraphType>&
		const_adjacent_nodes_iterator<GraphType>::operator++()
	{
		increment();
		return *this;
	}

	// Defer the details to the increment() helper.
	template<typename GraphType>
	const_adjacent_nodes_iterator<GraphType>
		const_adjacent_nodes_iterator<GraphType>::operator++(int)
	{
		auto oldIt{ *this };
		increment();
		return oldIt;
	}

	// Defer the details to the decrement() helper.
	template<typename GraphType>
	const_adjacent_nodes_iterator<GraphType>&
		const_adjacent_nodes_iterator<GraphType>::operator--()
	{
		decrement();
		return *this;
	}

	// Defer the details to the decrement() helper.
	template<typename GraphType>
	const_adjacent_nodes_iterator<GraphType>
		const_adjacent_nodes_iterator<GraphType>::operator--(int)
	{
		auto oldIt{ *this };
		decrement();
		return oldIt;
	}

	// Behavior is undefined if m_adjacentNodeIterator already refers to the past-the-end
	// element, or is otherwise invalid.
	template<typename GraphType>
	void const_adjacent_nodes_iterator<GraphType>::increment()
	{
		++m_adjacentNodeIterator;
	}

	// Behavior is undefined if m_adjacentNodeIterator already refers to the first
	// element, or is otherwise invalid.
	template<typename GraphType>
	void const_adjacent_nodes_iterator<GraphType>::decrement()
	{
		--m_adjacentNodeIterator;
	}

	template<typename GraphType>
	bool const_adjacent_nodes_iterator<GraphType>::operator==(
		const const_adjacent_nodes_iterator<GraphType>& rhs) const
	{
		if (!m_graph && !rhs.m_graph)
		{
			// They are both end iterators.
			return true;
		}
		return (m_graph == rhs.m_graph &&
			m_adjacentNodeIterator == rhs.m_adjacentNodeIterator);
	}

	template<typename GraphType>
	bool const_adjacent_nodes_iterator<GraphType>::operator!=(
		const const_adjacent_nodes_iterator<GraphType>& rhs) const
	{
		return !(*this == rhs);
	}

}
