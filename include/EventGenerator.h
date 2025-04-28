#pragma once

#include "Pipe.h"
#include <thread>
#include <atomic>

class EventGenerator {
public:
    EventGenerator(Pipe& pipe);
    ~EventGenerator();

    void start();
    void stop();
    void faster();
    void slower();
    void pause();
    void resume();

private:
    void run();

    Pipe& pipe;
    std::thread generatorThread;
    std::atomic<bool> running;
    std::atomic<bool> paused;
    int intervalMs;
    int eventIdCounter;
};