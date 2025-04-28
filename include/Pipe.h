#pragma once

#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif

class Pipe {
public:
    Pipe();
    ~Pipe();

    bool create();
    bool write(const void* data, size_t size);
    bool read(void* buffer, size_t size);

private:
#ifdef _WIN32 
    HANDLE readHandle;
    HANDLE writeHandle;
#else
    int pipefd[2];
#endif
};