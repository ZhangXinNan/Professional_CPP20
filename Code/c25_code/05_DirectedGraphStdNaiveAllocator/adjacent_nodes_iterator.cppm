module;

#include <cstddef>

export module directed_graph:adjacent_nodes_iterator;

import :const_adjacent_nodes_iterator;
import <iterator>;
import <set>;

namespace ProCpp
{

	template<typename GraphType>
	class adjacent_nodes_iterator : public const_adjacent_nodes_iterator<GraphType>
	{
	public:
		using value_type = typename GraphType::value_type;
		using difference_type = ptrdiff_t;
		using iterator_category = std::bidirectional_iterator_tag;
		using pointer = value_type*;
		using reference = value_type&;
		using iterator_type = std::set<size_t>::iterator;

		// Bidirectional iterators must supply a default constructor.
		// In this case, the default-constructed iterator serves as an
		// end iterator.
		adjacent_nodes_iterator() = default;

		// No transfer of ownership of graph.
		adjacent_nodes_iterator(iterator_type it, const GraphType* graph);

		reference operator*();

		// Return type must be something to which -> can be applied.
		// Return a pointer to a node, to which the compiler
		// will apply -> again.
		pointer operator->();

		adjacent_nodes_iterator& operator++();
		adjacent_nodes_iterator operator++(int);

		adjacent_nodes_iterator& operator--();
		adjacent_nodes_iterator operator--(int);
	};

	template<typename GraphType>
	adjacent_nodes_iterator<GraphType>::adjacent_nodes_iterator(
		iterator_type it, const GraphType* graph)
		: const_adjacent_nodes_iterator<GraphType>{ it, graph }
	{
	}

	// Return a reference to the node.
	template<typename GraphType>
	typename adjacent_nodes_iterator<GraphType>::reference
		adjacent_nodes_iterator<GraphType>::operator*()
	{
		// Return an reference to the actual node, not the index to the node.
		return const_cast<reference>((*(this->m_graph))[*(this->m_adjacentNodeIterator)]);
	}

	// Return a pointer to the actual node, so the compiler can
	// apply -> to it to access the actual desired field.
	template<typename GraphType>
	typename adjacent_nodes_iterator<GraphType>::pointer
		adjacent_nodes_iterator<GraphType>::operator->()
	{
		return const_cast<pointer>(&((*(this->m_graph))[*(this->m_adjacentNodeIterator)]));
	}

	// Defer the details to the increment() helper.
	template<typename GraphType>
	adjacent_nodes_iterator<GraphType>&
		adjacent_nodes_iterator<GraphType>::operator++()
	{
		this->increment();
		return *this;
	}

	// Defer the details to the increment() helper.
	template<typename GraphType>
	adjacent_nodes_iterator<GraphType>
		adjacent_nodes_iterator<GraphType>::operator++(int)
	{
		auto oldIt{ *this };
		this->increment();
		return oldIt;
	}

	// Defer the details to the decrement() helper.
	template<typename GraphType>
	adjacent_nodes_iterator<GraphType>&
		adjacent_nodes_iterator<GraphType>::operator--()
	{
		this->decrement();
		return *this;
	}

	// Defer the details to the decrement() helper.
	template<typename GraphType>
	adjacent_nodes_iterator<GraphType>
		adjacent_nodes_iterator<GraphType>::operator--(int)
	{
		auto oldIt{ *this };
		this->decrement();
		return oldIt;
	}

}
