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
	std::vector<int> sizes;

	int size;
	while (std::cin >> size) {
		sizes.push_back(size);
	}

	int ans = 0;
	for (int i = 0; i < (1 << sizes.size()); i++) {
		int amount = 0;
		for (int j = 0; j < sizes.size(); j++) {
			if (i & (1 << j)) {
				amount += sizes[j];
			}
		}

		if (amount == 150) {
			ans++;
		}
	}

	std::cout << ans << '\n';
	return 0;
}
