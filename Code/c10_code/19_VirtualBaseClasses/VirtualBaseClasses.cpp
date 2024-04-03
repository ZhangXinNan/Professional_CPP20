import <iostream>;

using namespace std;

class Animal
{
public:
	virtual void eat() = 0;
	virtual void sleep() { cout << "zzzzz...." << endl; }
};

class Dog : public virtual Animal
{
public:
	virtual void bark() { cout << "Woof!" << endl; }
	void eat() override { cout << "The dog ate." << endl; }
};

class Bird : public virtual Animal
{
public:
	virtual void chirp() { cout << "Chirp!" << endl; }
	void eat() override { cout << "The bird ate." << endl; }
};

class DogBird : public Dog, public Bird
{
public:
	void eat() override { Dog::eat(); }
};

int main()
{
	DogBird myConfusedAnimal;
	myConfusedAnimal.sleep();  // Not ambiguous because of virtual base class
}
