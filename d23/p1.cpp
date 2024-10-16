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

	std::vector<std::string> instructions;
	while (std::getline(std::cin, input)) {
		instructions.push_back(input);
	}

	int i = 0;
	std::map<std::string, int> reg;
	reg["a"] = 0;
	reg["b"] = 0;

	while (i < instructions.size()) {
		if (instructions[i].substr(0, 3) == "hlf") {
			reg[instructions[i].substr(4)] /= 2;
			i++;
		} else if (instructions[i].substr(0, 3) == "tpl") {
			reg[instructions[i].substr(4)] *= 3;
			i++;
		} else if (instructions[i].substr(0, 3) == "inc") {
			reg[instructions[i].substr(4)]++;
			i++;
		} else if (instructions[i].substr(0, 3) == "jmp") {
			i += std::stoi(instructions[i].substr(4));
		} else if (instructions[i].substr(0, 3) == "jie") {
			if (reg[instructions[i].substr(4, 1)] % 2 == 0) {
				i += std::stoi(instructions[i].substr(7));
			} else {
				i++;
			}
		} else if (instructions[i].substr(0, 3) == "jio") {
			if (reg[instructions[i].substr(4, 1)] == 1) {
				i += std::stoi(instructions[i].substr(7));
			} else {
				i++;
			}
		}
	}

	std::cout << reg["b"] << '\n';
	return 0;
}
