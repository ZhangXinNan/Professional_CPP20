export module cherry;

import <iostream>;

export class Cherry
{
public:
	virtual void printType()
	{
		std::cout << "I am a Cherry" << std::endl;
	}
};
