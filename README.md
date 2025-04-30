
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

## Commands

The program supports the following commands for controlling event generation and logging:

- `date`  
  Displays the current date (`YYYY-MM-DD` format).

- `time`  
  Displays the current time (`HH:MM:SS` format).

- `exit`  
  Stops the event generator and logger, then exits the program.

- `faster`  
  Speeds up event generation by decreasing the interval.

- `slower`  
  Slows down event generation by increasing the interval.

- `pause`  
  Temporarily pauses event generation.

- `resume`  
  Resumes event generation after a pause.

- `level <level>`  
  Sets the logging level:
  - 0 — Log only event IDs.
  - 1 — Log event IDs and the first parameter.
  - 2 — Log full event details (all parameters).

- `stat`  
  Displays the number of events logged.
