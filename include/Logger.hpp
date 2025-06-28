#include <iostream>
#include <fstream>
#include <sstream>
#include <ctime>

using namespace std;

class Logger {
public:
    Logger(const string& p_fileName);
    ~Logger();

    enum LogLevel { DEBUG, INFO, WARNING, ERROR, CRITICAL };
    void log(LogLevel level, const string& message);
    void log(LogLevel level, const int& message);
private:
    ofstream logFile;

    string levelToString(LogLevel level);
};