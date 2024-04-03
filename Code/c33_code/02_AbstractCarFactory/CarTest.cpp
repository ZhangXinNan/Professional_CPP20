import ford_factory;
import toyota_factory;
import <iostream>;
import <format>;

using namespace std;

void createSomeCars(IAbstractCarFactory& carFactory)
{
	auto sedan{ carFactory.makeSedan() };
	auto suv{ carFactory.makeSuv() };
	cout << format("Sedan: {}\n", sedan->info());
	cout << format("Suv: {}\n", suv->info());
}

int main()
{
	FordFactory fordFactory;
	ToyotaFactory toyotaFactory;
	createSomeCars(fordFactory);
	createSomeCars(toyotaFactory);
}
