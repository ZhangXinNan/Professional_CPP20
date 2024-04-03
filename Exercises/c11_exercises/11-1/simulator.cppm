export module simulator;

import <iostream>;

export namespace Simulator
{
	class CarSimulator
	{
	public:
		CarSimulator() { std::cout << "CarSimulator::CarSimulator()" << std::endl; }
	};

	class BikeSimulator
	{
	public:
		BikeSimulator() { std::cout << "BikeSimulator::BikeSimulator()" << std::endl; }
	};
}
