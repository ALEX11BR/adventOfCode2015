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

		int vol = l * w * h;
		int p1 = 2 * (l + w);
		int p2 = 2 * (l + h);
		int p3 = 2 * (h + w);

		ans += vol + std::min({p1, p2, p3});
	}

	std::cout << ans << '\n';
	return 0;
}
