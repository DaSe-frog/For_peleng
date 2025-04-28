#pragma once
#include <ctime>

struct Event {
    std::time_t timestamp;
    int id;
    int param1;
    int param2;
    int param3;
};