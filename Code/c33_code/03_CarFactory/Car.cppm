export module car;

import <string>;

export class ICar
{
public:
	virtual ~ICar() = default;  // Always a virtual destructor!
	virtual std::string info() const = 0;
};

export class Ford : public ICar
{
public:
	std::string info() const override { return "Ford"; }
};

export class Toyota : public ICar
{
public:
	std::string info() const override { return "Toyota"; }
};
