export module directed_graph.to_dot;

import directed_graph;
import <string>;
import <string_view>;
import <sstream>;
import <format>;

namespace ProCpp
{

	// Returns a given graph in DOT format.
	export
	template <typename T, typename A>
	std::wstring to_dot(const directed_graph<T, A>& graph, std::wstring_view graph_name)
	{
		std::wstringstream wss;

		wss << std::format(L"digraph {} {{", graph_name.data()) << std::endl;
		for (auto&& node : graph)
		{
			const auto b{ graph.cbegin(node) };
			const auto e{ graph.cend(node) };
			if (b == e)
			{
				wss << node << std::endl;
			}
			else
			{
				for (auto iter{ b }; iter != e; ++iter)
				{
					wss << std::format(L"{} -> {}", node, *iter) << std::endl;
				}
			}
		}
		wss << "}" << std::endl;

		return wss.str();
	}

}
