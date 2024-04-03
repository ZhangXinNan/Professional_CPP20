#include <cstddef>
#include <cstring>
import <exception>;
import <fstream>;
import <iostream>;
import <string>;

using namespace std;

class Logger
{
public:
	static void enableLogging(bool enable) { ms_loggingEnabled = enable; }
	static bool isLoggingEnabled() { return ms_loggingEnabled; }

	template<typename... Args>
	static void log(const Args&... args)
	{
		if (!ms_loggingEnabled) { return; }

		ofstream logfile{ ms_debugFilename, ios_base::app };
		if (logfile.fail()) {
			cerr << "Unable to open debug file!" << endl;
			return;
		}
		// Use a C++17 unary right fold, see Chapter 26.
		((logfile << args),...);
		logfile << endl;
	}

private:
	static inline const string ms_debugFilename{ "debugfile.out" };
	static inline bool ms_loggingEnabled{ false };
};


#define log(...) Logger::log(__func__, "(): ", __VA_ARGS__)



bool isDebugSet(int argc, char* argv[])
{
	for (int i{ 0 }; i < argc; i++) {
		if (strcmp(argv[i], "-d") == 0) {
			return true;
		}
	}
	return false;
}



class ComplicatedClass
{
	// Class details omitted for brevity.
};
ostream& operator<<(ostream& ostr, const ComplicatedClass& /* src */)
{
	ostr << "ComplicatedClass";
	return ostr;
}

class UserCommand
{
	// Class details not shown for brevity.
};
ostream& operator<<(ostream& ostr, const UserCommand& /* src */)
{
	ostr << "UserCommand";
	return ostr;
}



UserCommand getNextCommand(ComplicatedClass* /* obj */)
{
	UserCommand cmd;
	return cmd;
}

void processUserCommand(UserCommand& /* cmd */)
{
	// Details omitted for brevity.
}

void trickyFunction(ComplicatedClass* obj)
{
	log("given argument: ", *obj);

	for (size_t i{ 0 }; i < 100; ++i) {
		UserCommand cmd{ getNextCommand(obj) };
		log("retrieved cmd ", i, ": ", cmd);

		try {
			processUserCommand(cmd);
		} catch (const exception& e) {
			log("exception from processUserCommand(): ", e.what());
		}
	}
}

int main(int argc, char* argv[])
{
	Logger::enableLogging(isDebugSet(argc, argv));

	if (Logger::isLoggingEnabled()) {
		// Print the command-line arguments to the trace.
		for (int i{ 0 }; i < argc; i++) {
			log("Argument: ", argv[i]);
		}
	}

	ComplicatedClass obj;
	trickyFunction(&obj);

	// Rest of the function not shown.
}
