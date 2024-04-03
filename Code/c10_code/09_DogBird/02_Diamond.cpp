import <iostream>;

using namespace std;

class Animal
{
public:
	virtual void eat() = 0;
};

class Dog : public Animal
{
public:
	virtual void bark() { cout << "woof!" << endl; }
	void eat() override { cout << "The dog ate." << endl; }
};

class Bird : public Animal
{
public:
	virtual void chirp() { cout << "chirp!" << endl; }
	void eat() override { cout << "The bird ate." << endl; }
};

class DogBird : public Dog, public Bird
{
public:
	using Dog::eat;
};

int main()
{
	DogBird myConfusedAnimal;
	myConfusedAnimal.eat();
}
