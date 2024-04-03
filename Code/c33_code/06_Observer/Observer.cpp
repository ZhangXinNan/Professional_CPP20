#include <cstddef>
import <map>;
import <functional>;
import <iostream>;

using namespace std;

using EventHandle = size_t;

template <typename... Args>
class Event
{
public:
	virtual ~Event() = default; // Always a virtual destructor!

	// Adds an observer. Returns an EventHandle to unregister the observer.
	[[nodiscard]] EventHandle operator+=(function<void(Args...)> observer)
	{
		auto number{ ++m_counter };
		m_observers[number] = observer;
		return number;
	}

	// Unregisters the observer pointed to by the given handle.
	Event& operator-=(EventHandle handle)
	{
		m_observers.erase(handle);
		return *this;
	}

	// Raise event: notifies all registered observers.
	void raise(Args... args)
	{
		for (auto& observer : m_observers) {
			(observer.second)(args...);
		}
	}

private:
	size_t m_counter{ 0 };
	map<EventHandle, function<void(Args...)>> m_observers;
};


class ObservableSubject
{
public:
	auto& getEventDataModified() { return m_eventDataModified; }
	auto& getEventDataDeleted() { return m_eventDataDeleted; }

	void modifyData()
	{
		// ...
		getEventDataModified().raise(1, 2.3);
	}

	void deleteData()
	{
		// ...
		getEventDataDeleted().raise();
	}

public:
	Event<int, double> m_eventDataModified;
	Event<> m_eventDataDeleted;
};

void modified(int, double)
{
	cout << "modified" << endl;
}

class Observer
{
public:
	Observer(ObservableSubject& subject) : m_subject{ subject }
	{
		m_subjectModifiedHandle = m_subject.getEventDataModified() +=
			[this](int i, double d) { onSubjectModified(i, d); };
	}

	virtual ~Observer()
	{
		m_subject.getEventDataModified() -= m_subjectModifiedHandle;
	}

private:
	void onSubjectModified(int, double)
	{
		cout << "Observer::onSubjectModified()" << endl;
	}

	ObservableSubject& m_subject;
	EventHandle m_subjectModifiedHandle;
};

int main()
{
	ObservableSubject subject;

	auto handleModified{ subject.getEventDataModified() += modified };
	auto handleDeleted{ subject.getEventDataDeleted() += [] { cout << "deleted" << endl; } };
	Observer observer{ subject };

	subject.modifyData();
	subject.deleteData();

	cout << endl;

	subject.getEventDataModified() -= handleModified;
	subject.modifyData();
	subject.deleteData();
}