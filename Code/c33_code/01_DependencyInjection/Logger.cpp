module logger;

import <stdexcept>;
import <format>;

using namespace std;

Logger::Logger(string_view logFilename)
{
	m_outputStream.open(logFilename.data(), ios_base::app);
	if (!m_outputStream.good()) {
		throw runtime_error{ "Unable to initialize the Logger!" };
	}
}

Logger::~Logger()
{
	m_outputStream << "Logger shutting down." << endl;
	m_outputStream.close();
}

void Logger::setLogLevel(LogLevel level)
{
	m_logLevel = level;
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

void Logger::log(string_view message, LogLevel logLevel)
{
	if (m_logLevel < logLevel) {
		return;
	}

	m_outputStream << format("{}: {}", getLogLevelString(logLevel), message) << endl;
}
