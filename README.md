
## Installation

Install and run my project in bash (Linux or MINGW64):

```bash
bash build_run.sh
```
or build project:
```bash
cd <path_to_progect>
mkdir build
cd build
cmake ..
cmake --build .   
```
After building you can find application file in:
- Windows: <path_to_progect>/build/Debug
- Linux: <path_to_progect>/build/
## Log description
Find logs in:
- Windows: <path_to_progect>/build/Debug
- Linux: <path_to_progect>/build/
#### log_level0.txt


| Time | ID:     | 
| :-------- | :------- | 
| `%H:%M:%S` | ID: `int` |

#### log_level1.txt

| Date Time | ID:     |Param 1|
| :-------- | :------- | :-------------------------------- |
| `%Y-%m-%d` `%H:%M:%S`| ID: `int` | Param1: `int` |

#### log_level2.txt
| Date Time | ID:     |Params: (Param1, Param2, Param3)|
| :-------- | :------- | :----------|
| `%Y-%m-%d` `%H:%M:%S`| ID: `int` | Params: (`int`,`int`,`int`)|

## Project tree

```bash
|   build_run.sh
|   CMakeLists.txt
|---include
|       Event.h
|       EventGenerator.h
|       EventLogger.h
|       Logger.h
|       Pipe.h
|
|---src
        EventGenerator.cpp
        EventLogger.cpp
        Logger.cpp
        main.cpp
        Pipe.cpp
```
