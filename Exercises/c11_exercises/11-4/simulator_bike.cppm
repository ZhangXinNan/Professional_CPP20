export module simulator:bike;

import <iostream>;
import :internals;

export namespace Simulator
{
	class BikeSimulator
	{
	public:
		BikeSimulator()
		{
			std::cout << "BikeSimulator::BikeSimulator()" << std::endl;
		}

		void setOdometer(double miles)
		{
			double km{ convertMilesToKm(miles) };
			std::cout << km << std::endl;
		}
	};
}
