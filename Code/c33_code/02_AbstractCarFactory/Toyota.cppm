export module toyota;

export import icar;
import <string>;

export class Toyota : public ICar
{
};

export class ToyotaSedan : public Toyota
{
public:
	std::string info() const override { return "Toyota Sedan"; }
};

export class ToyotaSuv : public Toyota
{
public:
	std::string info() const override { return "Toyota Suv"; }
};
