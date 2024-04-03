import <iostream>;
import <memory>;
import bing_cherry;
import bing_cherry_tree;

int main()
{
	BingCherryTree theTree;
	std::unique_ptr<Cherry> theCherry{ theTree.pick() };
	theCherry->printType();
}

