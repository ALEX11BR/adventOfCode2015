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

	int level = 0;
	for (const char &c : input) {
		switch (c) {
		case '(':
			level += 1;
			break;
		case ')':
			level -= 1;
			break;
		}
	}

	std::cout << level << '\n';
	return 0;
}
