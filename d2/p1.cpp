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
	std::string line;
	std::regex line_regex("(.*)x(.*)x(.*)");
	std::smatch line_match;
	long long ans = 0;

	while (std::getline(std::cin, line)) {
		std::regex_match(line, line_match, line_regex);
		int l = std::stoi(line_match[1].str());
		int w = std::stoi(line_match[2].str());
		int h = std::stoi(line_match[3].str());

		int s1 = l * w;
		int s2 = l * h;
		int s3 = h * w;

		ans += 2 * s1 + 2 * s2 + 2 * s3 + std::min({s1, s2, s3});
	}

	std::cout << ans << '\n';
	return 0;
}
