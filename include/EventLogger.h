#pragma once

#include "Pipe.h"
#include <thread>
#include <atomic>
#include <memory>
#include "Logger.h"

class EventLogger {
public:
    EventLogger(Pipe& pipe);
    ~EventLogger();

    void start();
    void stop();
    void setLevel(int level);

    int getEventCount() const;

private:
    void run();

    Pipe& pipe;
    std::thread loggerThread;
    std::atomic<bool> running;
    std::unique_ptr<Logger> logger;
    std::atomic<int> eventCount;
    int currentLevel;
};