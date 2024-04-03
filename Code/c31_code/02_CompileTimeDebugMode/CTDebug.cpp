#include <cstddef>
import <exception>;
import <fstream>;
import <iostream>;
import <string>;

using namespace std;

#define DEBUG_MODE

#ifdef DEBUG_MODE
	class Logger
	{
	public:
		template<typename... Args>
		static void log(const Args&... args)
		{
			ofstream logfile{ ms_debugFilename, ios_base::app };
			if (logfile.fail()) {
				cerr << "Unable to open debug file!" << endl;
				return;
			}
			// Use a C++17 unary right fold, see Chapter 26.
			((logfile << args), ...);
			logfile << endl;
		}

	private:
		static inline const string ms_debugFilename{ "debugfile.out" };
	};

	#define log(...) Logger::log(__func__, "(): ", __VA_ARGS__)
#else
	#define log(...)
#endif

// WARNING:
//		Be careful not to put any code that must be executed for correct program
//		functioning inside your log() calls. For example, a line as follows could
//		be asking for trouble:
//		    log("Result: ", myFunctionCall());
//		If DEBUG_MODE is not defined, the preprocessor replaces all log() calls with
//		no-ops, which means that the call to myFunctionCall() is removed as well!

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
			log("received exception from processUserCommand(): ", e.what());
		}
	}
}

int main(int argc, char* argv[])
{
#ifdef DEBUG_MODE
	// Print the command-line arguments to the trace.
	for (int i{ 0 }; i < argc; i++) {
		log("Argument: ", argv[i]);
	}
#endif

	ComplicatedClass obj;
	trickyFunction(&obj);

	// Rest of the function not shown.
}
