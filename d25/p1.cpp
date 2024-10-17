#include <algorithm>
#include <array>
#include <cctype>
#include <climits>
#include <cmath>
#include <cstring>
#include <deque>
#include <iostream>
#include <map>
#include <random>
#include <regex>
#include <queue>
#include <set>
#include <sstream>
#include <streambuf>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

int main() {
	std::string input;
	std::getline(std::cin, input);

	int row, column, end;

	input = input.substr(input.find_first_of("1234567890"));
	end = input.find_first_not_of("1234567890");
	row = std::stoi(input.substr(0, end));

	input = input.substr(end);
	input = input.substr(input.find_first_of("1234567890"));
	end = input.find_first_not_of("1234567890");
	column = std::stoi(input.substr(0, end));

	long long diagonal = row + column - 1;
	long long prev_elems = diagonal * (diagonal - 1) / 2 + column - 1;

	long long ans = 20151125;
	for (long long i = 0; i < prev_elems; i++) {
		ans = (ans * 252533) % 33554393;
	}

	std::cout << ans << '\n';
	return 0;
}
