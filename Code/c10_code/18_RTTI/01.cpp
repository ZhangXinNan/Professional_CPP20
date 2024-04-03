import <typeinfo>;
import <iostream>;

using namespace std;

class Animal { public: virtual ~Animal() = default; };
class Dog : public Animal {};
class Bird : public Animal {};

void speak(const Animal& animal)
{
	if (typeid(animal) == typeid(Dog)) {
		cout << "Woof!" << endl;
	} else if (typeid(animal) == typeid(Bird)) {
		cout << "Chirp!" << endl;
	}
}

int main()
{
	speak(Dog{});
	speak(Bird{});
}
