module logger;

import <iostream>;
import <stdexcept>;
import <format>;

using namespace std;

Logger::Logger()
{
	cout << "Logger constructor" << endl;
}

void Logger::log(LogLevel level, const string& message)
{
	cout << format("{}: {}", getLogLevelString(level), message) << endl;
}

string_view Logger::getLogLevelString(LogLevel level) const
{
	switch (level) {
	case LogLevel::Error: return "ERROR";
	case LogLevel::Info: return "INFO";
	case LogLevel::Debug: return "DEBUG";
	}
	throw runtime_error{ "Invalid log level." };
}




NewLoggerAdapter::NewLoggerAdapter()
{
	cout << "NewLoggerAdapter constructor" << endl;
}

void NewLoggerAdapter::log(string_view message)
{
	m_logger.log(Logger::LogLevel::Info, message.data());
}
