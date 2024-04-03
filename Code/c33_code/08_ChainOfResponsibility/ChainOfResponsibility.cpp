import <iostream>;

using namespace std;

enum class Event {
	LeftMouseButtonDown,
	LeftMouseButtonUp,
	RightMouseButtonDown,
	RightMouseButtonUp
};

class Handler
{
public:
	virtual ~Handler() = default;

	explicit Handler(Handler* nextHandler) : m_nextHandler{ nextHandler } { }

	virtual void handleMessage(Event message)
	{
		if (m_nextHandler) { m_nextHandler->handleMessage(message); }
	}
private:
	Handler* m_nextHandler;
};


class Application : public Handler
{
public:
	explicit Application(Handler* nextHandler) : Handler{ nextHandler } { }

	void handleMessage(Event message) override
	{
		cout << "Application::handleMessage()" << endl;
		if (message == Event::RightMouseButtonDown) {
			cout << "   Handling message RightMouseButtonDown" << endl;
		} else {
			Handler::handleMessage(message);
		}
	}
};

class Window : public Handler
{
public:
	explicit Window(Handler* nextHandler) : Handler{ nextHandler } { }

	void handleMessage(Event message) override
	{
		cout << "Window::handleMessage()" << endl;
		if (message == Event::LeftMouseButtonUp) {
			cout << "   Handling message LeftMouseButtonUp" << endl;
		} else {
			Handler::handleMessage(message);
		}
	}
};

class Shape : public Handler
{
public:
	explicit Shape(Handler* nextHandler) : Handler{ nextHandler } { }

	void handleMessage(Event message) override
	{
		cout << "Shape::handleMessage()" << endl;
		if (message == Event::LeftMouseButtonDown) {
			cout << "   Handling message LeftMouseButtonDown" << endl;
		} else {
			Handler::handleMessage(message);
		}
	}
};


int main()
{
	Application application{ nullptr };
	Window window{ &application };
	Shape shape{ &window };

	shape.handleMessage(Event::LeftMouseButtonDown);
	cout << endl;

	shape.handleMessage(Event::LeftMouseButtonUp);
	cout << endl;

	shape.handleMessage(Event::RightMouseButtonDown);
	cout << endl;

	shape.handleMessage(Event::RightMouseButtonUp);
}
