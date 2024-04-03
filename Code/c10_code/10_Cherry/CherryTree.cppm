export module cherry_tree;

export import cherry;

export class CherryTree
{
public:
	virtual Cherry* pick()
	{
		return new Cherry{};
	}
};
