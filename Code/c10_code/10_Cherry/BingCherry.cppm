export module bing_cherry;

export import cherry;
import <iostream>;

export class BingCherry : public Cherry
{
public:
	void printType() override
	{
		std::cout << "I am a Bing Cherry" << std::endl;
	}

	virtual void polish()
	{
		std::cout << "I am getting polished" << std::endl;
	}
};
