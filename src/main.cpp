#include <iostream>
#include <map>
#include <functional>
#include <sstream>
#include <iomanip>
#include <ctime>
#include "../include/Pipe.h"
#include "../include/EventGenerator.h"
#include "../include/EventLogger.h"



int main() {
    Pipe pipe;
    if (!pipe.create()) {
        std::cerr << "Failed to create pipe\n";
        return 1;
    }

    bool exit_flag = false;

    EventGenerator generator(pipe);
    EventLogger logger(pipe);

    generator.start();
    logger.start();

    std::map<std::string, std::function<void(const char*)>> commands = {
        {"date", [](const char*) {
            auto now = std::time(nullptr);
            std::cout << std::put_time(std::localtime(&now), "%Y-%m-%d") << '\n';
        }},
        {"time", [](const char*) {
            auto now = std::time(nullptr);
            std::cout << std::put_time(std::localtime(&now), "%H:%M:%S") << '\n';
        }},
        {"exit", [&](const char*) {
            exit_flag = true;
            logger.stop();
            generator.stop();          
        }},
        {"faster", [&](const char*) { generator.faster(); }},
        {"slower", [&](const char*) { generator.slower(); }},
        {"pause", [&](const char*) { generator.pause(); }},
        {"resume", [&](const char*) { generator.resume(); }},
        {"level", [&](const char* args) {
            if (!args) {
                std::cerr << "Missing level argument\n";
                return;
            }
            int level = std::atoi(args);
            if (level < 0 || level > 2) {
                std::cerr << "Invalid level: must be 0, 1 or 2\n";
            }
             else {
              logger.setLevel(level);
            }
        }},

        {"stat", [&](const char*) {
            std::cout << "Events logged: " << logger.getEventCount() << '\n';
        }}
    };

    std::string input;
    while (!exit_flag) {
        std::cout << "> ";
        if (!std::getline(std::cin, input)) break;

        std::istringstream iss(input);
        std::string command;
        iss >> command;

        auto it = commands.find(command);
        if (it != commands.end()) {
            std::string args;
            std::getline(iss, args);
            const char* c_args = args.empty() ? nullptr : args.c_str();
            it->second(c_args);
        }
        else {
            std::cerr << "Unknown command: " << command << '\n';
        }
    }

    logger.stop();
    generator.stop();
    
    return 0;
}