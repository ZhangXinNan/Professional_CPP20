export module simulator:car;

import <iostream>;
import :internals;

export namespace Simulator
{
	class CarSimulator
	{
	public:
		CarSimulator()
		{
			std::cout << "CarSimulator::CarSimulator()" << std::endl;
		}

		void setOdometer(double miles)
		{
			double km{ convertMilesToKm(miles) };
			std::cout << km << std::endl;
		}
	};
}
