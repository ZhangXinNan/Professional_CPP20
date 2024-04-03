import <memory>;
import <iostream>;

using namespace std;

class Simple
{
public:
	Simple() { cout << "Simple constructor called!" << endl; }
	~Simple() { cout << "Simple destructor called!" << endl; }
};

void useResource(weak_ptr<Simple>& weakSimple)
{
	auto resource{ weakSimple.lock() };
	if (resource) {
		cout << "Resource still alive." << endl;
	} else {
		cout << "Resource has been freed!" << endl;
	}
}

int main()
{
	auto sharedSimple{ make_shared<Simple>() };
	weak_ptr<Simple> weakSimple{ sharedSimple };

	// Try to use the weak_ptr.
	useResource(weakSimple);

	// Reset the shared_ptr.
	// Since there is only 1 shared_ptr to the Simple resource, this will
	// free the resource, even though there is still a weak_ptr alive.
	sharedSimple.reset();

	// Try to use the weak_ptr a second time.
	useResource(weakSimple);
}
