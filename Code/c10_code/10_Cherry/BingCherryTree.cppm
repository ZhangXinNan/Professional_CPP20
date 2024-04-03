export module bing_cherry_tree;

export import cherry_tree;
export import bing_cherry;
import <memory>;

export class BingCherryTree : public CherryTree
{
public:
	BingCherry* pick() override
	{
		auto theCherry{ std::make_unique<BingCherry>() };
		theCherry->polish();
		return theCherry.release();
	}
};
