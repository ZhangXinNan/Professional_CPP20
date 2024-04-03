import round_robin;
import <stdexcept>;
import <iostream>;
import <string>;
import <string_view>;
import <vector>;

using namespace std;

// Basic Process class.
class Process final
{
public:
	// Constructor accepting the name of the process.
	explicit Process(string name) : m_name{ move(name) } {}

	// Lets a process perform its work for the duration of a time slice.
	void doWorkDuringTimeSlice()
	{
		cout << "Process " << m_name
			<< " performing work during time slice." << endl;
		// Actual implementation omitted.
	}

	// Needed for the RoundRobin::remove() method to work.
	bool operator==(const Process&) const = default; // = default since C++20.
	// Pre-C++20:
	//bool operator==(const Process& rhs) const
	//{
	//	return m_name = rhs.m_name;
	//}

private:
	string m_name;
};





// Basic round-robin based process scheduler.
class Scheduler final
{
public:
	// Constructor takes a vector of processes.
	explicit Scheduler(const vector<Process>& processes)
	{
		// Add the processes.
		for (auto& process : processes) { m_processes.add(process); }
	}

	// Selects the next process using a round-robin scheduling algorithm
	// and allows it to perform some work during this time slice.
	void scheduleTimeSlice()
	{
		try {
			m_processes.getNext().doWorkDuringTimeSlice();
		} catch (const out_of_range&) {
			cerr << "No more processes to schedule." << endl;
		}
	}

	// Removes the given process from the list of processes.
	void removeProcess(const Process& process)
	{
		m_processes.remove(process);
	}
private:
	RoundRobin<Process> m_processes;
};




int main()
{
	vector processes{ Process { "1" }, Process { "2" }, Process { "3" } };

	Scheduler scheduler{ processes };
	for (size_t i{ 0 }; i < 4; ++i) {
		scheduler.scheduleTimeSlice();
	}

	scheduler.removeProcess(processes[1]);
	cout << "Removed second process" << endl;

	for (size_t i{ 0 }; i < 4; ++i) {
		scheduler.scheduleTimeSlice();
	}
}
