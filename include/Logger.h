#include "Event.h"
#include <fstream>
#include <memory>

class Logger {
protected:
    std::ofstream file;
    Logger(const char* fileName);
    

public:
    virtual ~Logger();
    static std::unique_ptr<Logger> GetLogger(int level);
    virtual Logger* Write(const Event& event) = 0;
};