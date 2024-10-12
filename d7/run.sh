#!/usr/bin/env sh

cwd="$(dirname $(readlink -f "$0") )"
cd "$cwd"
current_day="$(basename "$cwd")"

cmake -S .. -B ../build

echo === PART 1 ===
cmake --build ../build --target "$current_day"p1
../build/"$current_day"/"$current_day"p1 < input

echo === PART 2 ===
cmake --build ../build --target "$current_day"p2
../build/"$current_day"/"$current_day"p2 < input
