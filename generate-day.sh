#!/usr/bin/env sh
cd "$(dirname $(readlink -f "$0") )"

if [ -z "$1" ]; then
    echo !!! Supply day number !!!
    exit 1
fi

cp -r d1 d"$1"

echo "add_executable(d${1}p1 p1.cpp)" > d"$1"/CMakeLists.txt
echo "add_executable(d${1}p2 p2.cpp)" >> d"$1"/CMakeLists.txt

echo "add_subdirectory(d${1})" >> CMakeLists.txt
