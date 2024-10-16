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

	std::pair<int, int> santa = {0, 0};
	std::pair<int, int> robo = {0, 0};
	std::set<std::pair<int, int>> visited;
	visited.insert({0, 0});

	int i = 0;
	for (const char &c : input) {
		std::pair<int, int> &current = i % 2 == 0 ? santa : robo;

		switch (c) {
		case '^':
			current.first += 1;
			break;
		case 'v':
			current.first -= 1;
			break;
		case '<':
			current.second -= 1;
			break;
		case '>':
			current.second += 1;
			break;
		}

		visited.insert(current);
		i++;
	}

	std::cout << visited.size() << '\n';
	return 0;
}
