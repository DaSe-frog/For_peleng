#include "../include/EventLogger.h"
#include "../include/Event.h"

EventLogger::EventLogger(Pipe& p)
    : pipe(p), running(false), eventCount(0), currentLevel(0) {
    logger = Logger::GetLogger(currentLevel);
}

EventLogger::~EventLogger() {
    stop();
}

void EventLogger::start() {
    running = true;
    loggerThread = std::thread(&EventLogger::run, this);
}

void EventLogger::stop() {
    running = false;
    if (loggerThread.joinable()) {
        loggerThread.join();
    }
}

void EventLogger::setLevel(int level) {
    currentLevel = level;
    logger = Logger::GetLogger(level);
}

int EventLogger::getEventCount() const {
    return eventCount.load();
}

void EventLogger::run() {
    Event event;
    while (running) {
        if (pipe.read(&event, sizeof(Event))) {
            if (logger) {
                logger->Write(event);
                ++eventCount;
            }
        }
    }
}