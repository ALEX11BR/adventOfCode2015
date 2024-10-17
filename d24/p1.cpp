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

struct Group {
	int size = INT_MAX;
	long long quantum = 1;

	bool operator<(const Group &rhs) const {
		if (size == rhs.size) {
			return quantum < rhs.quantum;
		}
		return size < rhs.size;
	}

	Group operator+(const int &rhs) const {
		return {size + 1, quantum * rhs};
	}
};

long long knapsack(const std::vector<int> &weights, int target) {
	std::vector<Group> dyn(target + 1);

	for (const int &weight : weights) {
		std::vector<Group> new_dyn = dyn;
		for (int i = 1; i <= target; i++) {
			if (weight == i) {
				new_dyn[i] = {1, weight};
			}
			if (weight < i && dyn[i - weight].size != INT_MAX) {
				new_dyn[i] = std::min(new_dyn[i], dyn[i - weight] + weight);
			}
		}
		dyn = new_dyn;
	}

	return dyn[target].quantum;
}

int main() {
	int num, sum = 0;

	std::vector<int> weights;
	while (std::cin >> num) {
		weights.push_back(num);
		sum += num;
	}

	std::cout << knapsack(weights, sum / 3) << '\n';
	return 0;
}
