export module simulator:bike;

import <iostream>;

export namespace Simulator
{
	class BikeSimulator
	{
	public:
		BikeSimulator() { std::cout << "BikeSimulator::BikeSimulator()" << std::endl; }
	};
}
