# Personal attempts at solving advent of code 2015 in C++

In every `d{day}` folder there are my solutions to that day's problems (almost 9 years later).
The day's input sits in that folder in a file named `input` (I don't publish them here).

The programs get their input from a stdin (that might require an end of stream).
This can be accomplished, for instance, by:

- redirecting the input file into the program,
- heredocs,
- typing the input followed by a `^D`.

Certain solutions have caveats:
- Day 4: makes use of `openssl`, specifically the `crypto` module.

## Run
```sh
cd d${DAY}

# Both parts
./run.sh

# Only one part
cmake -S .. -B ../build
cmake --build ../build --target d${DAY}p${PART}
../build/d${DAY}/d${DAY}p{PART} < input
```

## Generate code for a new day
```sh
./generate-day.sh ${DAY}
```
