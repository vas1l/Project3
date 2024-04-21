#pragma once
#include <iostream>
#include <sstream>

enum class LogLevel {
    Log,
    Warning,
    Error,
    Critical,
};

class Logger {
    std::stringstream ss;
    LogLevel logLevel;

    public:
        Logger(LogLevel l) : logLevel(l) {}
        ~Logger() {
            switch (logLevel) {
                case LogLevel::Log:
                    std::cout << "[LOG]: ";
                    break;

                case LogLevel::Warning:
                    std::cout << "[WARNING]: ";
                    break;

                case LogLevel::Error:
                    std::cout << "[ERROR]: ";
                    break;

                case LogLevel::Critical:
                    std::cout << "[===CRITICAL===]: ";
                    break;
            }

            std::cout << ss.str() << std::endl;
        }

        template<typename T>
        Logger& operator << (const T& arg) {
            ss << arg;
            return *this;
        }

        Logger& operator << (bool b) {
            ss << (b? "true" : "false");
            return *this;
        }
};