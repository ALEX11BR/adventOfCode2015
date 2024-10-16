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
	std::regex line_regex("(turn on|turn off|toggle) ([0-9]*),([0-9]*) through ([0-9]*),([0-9]*)");
	std::smatch line_match;

	auto on = [](int x) { return x + 1; };
	auto off = [](int x) { return std::max(0, x - 1); };
	auto toggle = [](int x) { return x + 2; };

	std::vector<std::vector<int>> lights(1000, std::vector<int>(1000, 0));
	while (std::getline(std::cin, input)) {
		std::regex_match(input, line_match, line_regex);

		int ls = std::stoi(line_match[2]);
		int cs = std::stoi(line_match[3]);
		int le = std::stoi(line_match[4]);
		int ce = std::stoi(line_match[5]);

		auto fn = (line_match[1] == "toggle") ? toggle : (line_match[1] == "turn on") ? on : off;
		for (int i = ls; i <= le; i++) {
			for (int j = cs; j <= ce; j++) {
				lights[i][j] = fn(lights[i][j]);
			}
		}
	}

	long long ans = 0;
	for (int i = 0; i < 1000; i++) {
		for (int j = 0; j < 1000; j++) {
			ans += lights[i][j];
		}
	}

	std::cout << ans << '\n';
	return 0;
}
