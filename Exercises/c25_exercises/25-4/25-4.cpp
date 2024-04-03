
///////////////////////////////////////////////////////////////////////
////
//// NOTE:
////   This file does not compile on itself.
////   It just contains the implementation for the contains() method.
////   You can take the code from 06_DirectedGraphFinal and add the
////   below contains() method to test it.
////
///////////////////////////////////////////////////////////////////////

namespace ProCpp
{

	export
	template<typename T, typename A = std::allocator<T>>
	class directed_graph
	{
	public:
		// ...

		// Returns true if node_value is in the graph, false otherwise.
		bool contains(const T& node_value) const;

		// ...
 	};


	template<typename T, typename A>
	bool directed_graph<T, A>::contains(const T& node_value) const
	{
		const auto iter{ findNode(node_value) };
		return iter != std::end(m_nodes);
	}

}
