#include "../include/EventGenerator.h"
#include "../include/Event.h"
#include <chrono>
#include <random>



EventGenerator::EventGenerator(Pipe& p)
    : pipe(p), running(false), paused(false), eventIdCounter(0) {

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(100, 1500);
    intervalMs = dist(gen);

}

EventGenerator::~EventGenerator() {
    stop();
}

void EventGenerator::start() {
    running = true;
    generatorThread = std::thread(&EventGenerator::run, this);
}

void EventGenerator::stop() {
    running = false;
    if (generatorThread.joinable()) {
        generatorThread.join();
    }
}

void EventGenerator::faster() {
    if (intervalMs > 1000) intervalMs -= 1000;
    else if (intervalMs > 500) intervalMs -= 500;
    else if (intervalMs > 250) intervalMs -= 250;
    else if (intervalMs > 100) intervalMs -= 100;
}

void EventGenerator::slower() {
    intervalMs += 1000;
}

void EventGenerator::pause() {
    paused = true;
}

void EventGenerator::resume() {
    paused = false;
}

void EventGenerator::run() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(0, 1000);

    while (running) {
        if (!paused) {
            Event event;
            event.timestamp = std::time(nullptr);
            event.id = eventIdCounter++;
            event.param1 = dist(gen);
            event.param2 = dist(gen);
            event.param3 = dist(gen);

            pipe.write(&event, sizeof(Event));
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(intervalMs));
    }
}