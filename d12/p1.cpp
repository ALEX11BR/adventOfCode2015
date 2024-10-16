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
	std::regex num_regex("[0-9-]+");
	int ans = 0;

	std::getline(std::cin, input);

	std::sregex_iterator number_iterator(input.begin(), input.end(), num_regex);
	for (std::sregex_iterator i = number_iterator; i != std::sregex_iterator(); i++) {
		ans += std::stoi(i->str());
	}

	std::cout << ans << '\n';
	return 0;
}
