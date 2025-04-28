#include "../include/Logger.h"
#include <iomanip>
#include <sstream>

Logger::Logger(const char* fileName) {
    file.open(fileName, std::ios::app);
}

Logger::~Logger() {
    if (file.is_open()) {
        file.close();
    }
}

class LoggerLevel0 : public Logger {
public:
    LoggerLevel0() : Logger("log_level0.txt") {}

    Logger* Write(const Event& event) override {
        file << std::put_time(std::localtime(&event.timestamp), "%H:%M:%S")
            << " | ID: " << event.id << '\n';
        return this;
    }
};

class LoggerLevel1 : public Logger {
public:
    LoggerLevel1() : Logger("log_level1.txt") {}

    Logger* Write(const Event& event) override {
        file << std::put_time(std::localtime(&event.timestamp), "%Y-%m-%d %H:%M:%S")
            << " | ID: " << event.id
            << " | Param1: " << event.param1 << '\n';
        return this;
    }
};

class LoggerLevel2 : public Logger {
public:
    LoggerLevel2() : Logger("log_level2.txt") {}

    Logger* Write(const Event& event) override {
        file << std::put_time(std::localtime(&event.timestamp), "%Y-%m-%d %H:%M:%S")
            << " | ID: " << event.id
            << " | Params: ("
            << event.param1 << ", " << event.param2 << ", " << event.param3 << ")\n";
        return this;
    }
};

std::unique_ptr<Logger> Logger::GetLogger(int level) {
    switch (level) {
    case 0: return std::make_unique<LoggerLevel0>();
    case 1: return std::make_unique<LoggerLevel1>();
    case 2: return std::make_unique<LoggerLevel2>();
    default: return nullptr;
    }
}