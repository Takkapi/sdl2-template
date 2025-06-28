#include "Logger.hpp"

Logger::Logger(const string& p_fileName) {
    logFile.open(p_fileName, ios::app);
    if(!logFile.is_open()) {
        log(ERROR, "Error opening log file: " + p_fileName);
    }
}

Logger::~Logger() {
    log(INFO, "Closing log file");
    log(INFO, "Logger destroyed");
    logFile.close();
}

void Logger::log(LogLevel level, const string& message) {
    time_t now = time(0);
    tm* timeinfo = localtime(&now);
    char timestamp[20];
    strftime(timestamp, sizeof(timestamp), "%Y-%m-%d %H:%M:%S", timeinfo);

    ostringstream logEntry;
    logEntry << "[" << timestamp << "] " << levelToString(level) << ": " << message << endl;

    cout << logEntry.str();

    if(logFile.is_open()) {
        logFile << logEntry.str();
        logFile.flush();
    }
}

void Logger::log(LogLevel level, const int& message) {
    time_t now = time(0);
    tm* timeinfo = localtime(&now);
    char timestamp[20];
    strftime(timestamp, sizeof(timestamp), "%Y-%m-%d %H:%M:%S", timeinfo);

    ostringstream logEntry;
    logEntry << "[" << timestamp << "] " << levelToString(level) << ": " << message << endl;

    cout << logEntry.str();

    if(logFile.is_open()) {
        logFile << logEntry.str();
        logFile.flush();
    }
}

string Logger::levelToString(LogLevel level) {
    switch(level) {
        case DEBUG: return "DEBUG";
        case INFO: return "INFO";
        case WARNING: return "WARNING";
        case ERROR: return "ERROR";
        case CRITICAL: return "CRITICAL";
        default: return "UNKNOWN";
    }
}