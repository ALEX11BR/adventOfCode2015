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

	while (true) {
		std::getline(std::cin, input);
		if (input.empty()) {
			break;
		}
	}

	std::getline(std::cin, input);

	int ans = -1;
	for (int i = 0; i < input.size(); i++) {
		ans++;

		if (input[i] == 'Y') {
			ans -= 2;
		} else if (input.substr(i, 2) == "Rn") {
			ans -= 2;
		}

		if (std::isupper(input[i]) && i + 1 < input.size() && std::islower(input[i + 1])) {
			i += 1;
		}
	}

	std::cout << ans << '\n';
	return 0;
}
