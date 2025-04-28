#!/bin/bash
mkdir -p build
cd build || exit 1
cmake .. || { echo "Ошибка на этапе cmake .."; exit 1; }
cmake --build . || { echo "Ошибка на этапе сборки"; exit 1; }
OS=$(uname)

if [[ "$OS" == "Linux" ]]; then
    echo "Запуск программы на Linux: "
    ./project
elif [[ "$OS" == "MINGW"* || "$OS" == "MSYS"* || "$OS" == "CYGWIN"* ]]; then
    echo "Запуск программы на Windows (Git Bash):"
    cd Debug || exit 1
    ./project.exe
else
    echo "Неизвестная операционная система: $OS"
    exit 1
fi