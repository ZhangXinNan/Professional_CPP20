export module simulator:car;

import <iostream>;

export namespace Simulator
{
	class CarSimulator
	{
	public:
		CarSimulator() { std::cout << "CarSimulator::CarSimulator()" << std::endl; }
	};
}
