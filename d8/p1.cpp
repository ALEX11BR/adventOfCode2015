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

	int ans = 0;
	while (std::getline(std::cin, input)) {
		ans += 2;
		for (int i = 1; i < input.size() - 1; i++) {
			if (input[i] == '\\') {
				ans++;
				if (input[i + 1] == 'x') {
					ans += 2;
					i += 3;
				} else {
					i += 1;
				}
			}
		}
	}

	std::cout << ans << '\n';
	return 0;
}
