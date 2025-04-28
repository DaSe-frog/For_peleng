#include "../include/Pipe.h"
#include <cstring>

Pipe::Pipe() { 
    #ifdef _WIN32
    readHandle = INVALID_HANDLE_VALUE;
    writeHandle = INVALID_HANDLE_VALUE;
#endif  
}

Pipe::~Pipe() {
#ifdef _WIN32
    if (readHandle != INVALID_HANDLE_VALUE) CloseHandle(readHandle);
    if (writeHandle != INVALID_HANDLE_VALUE) CloseHandle(writeHandle);
#else
    close(pipefd[0]);
    close(pipefd[1]);
#endif
}

bool Pipe::create() {
#ifdef _WIN32
    SECURITY_ATTRIBUTES sa = { sizeof(SECURITY_ATTRIBUTES), NULL, TRUE };
    return CreatePipe(&readHandle, &writeHandle, &sa, 0);
#else
    return ::pipe(pipefd) == 0;
#endif
}

bool Pipe::write(const void* data, size_t size) {
#ifdef _WIN32
    DWORD written;
    return WriteFile(writeHandle, data, static_cast<DWORD>(size), &written, NULL);
#else
    return ::write(pipefd[1], data, size) == (ssize_t)size;
#endif
}

bool Pipe::read(void* buffer, size_t size) {
#ifdef _WIN32
    DWORD read;
    return ReadFile(readHandle, buffer, static_cast<DWORD>(size), &read, NULL);
#else
    return ::read(pipefd[0], buffer, size) == (ssize_t)size;
#endif
}