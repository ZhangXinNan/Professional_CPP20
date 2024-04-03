module;

#include <cstddef>

export module car_factory;

export import car;
import <memory>;

export class CarFactory
{
public:
	virtual ~CarFactory() = default;  // Always a virtual destructor!
	
	std::unique_ptr<ICar> requestCar()
	{
		// Increment the number of cars produced and return the new car.
		++m_numberOfCarsProduced;
		return createCar();
	}

	size_t getNumberOfCarsProduced() const
	{
		return m_numberOfCarsProduced;
	}

protected:
	virtual std::unique_ptr<ICar> createCar() = 0;

private:
	size_t m_numberOfCarsProduced{ 0 };
};

export class FordFactory : public CarFactory
{
protected:
	std::unique_ptr<ICar> createCar() override
	{
		return std::make_unique<Ford>();
	}

};

export class ToyotaFactory : public CarFactory
{
protected:
	std::unique_ptr<ICar> createCar() override
	{
		return std::make_unique<Toyota>();
	}
};
