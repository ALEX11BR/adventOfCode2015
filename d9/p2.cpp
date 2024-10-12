#include <bits/stdc++.h>

std::array<std::array<int, 8>, 8> distances;

std::vector<int> permutation;
std::vector<bool> set(8);

int backtracking() {
	int ans = 0;

	if (permutation.size() == 8) {
		ans = 0;
		for (int i = 0; i < permutation.size() - 1; i++) {
			ans += distances[permutation[i]][permutation[i + 1]];
		}

		return ans;
	}

	for (int i = 0; i < 8; i++) {
		if (!set[i]) {
			permutation.push_back(i);
			set[i] = true;

			ans = std::max(ans, backtracking());

			set[i] = false;
			permutation.pop_back();
		}
	}
	return ans;
}

int main() {
	std::string input;
	std::regex line_regex("(.*) to (.*) = (.*)");
	std::smatch line_match;

	std::map<std::string, int> city_id;

	while (std::getline(std::cin, input)) {
		std::string city1, city2;
		int distance;

		std::regex_match(input, line_match, line_regex);
		city1 = line_match[1];
		city2 = line_match[2];
		distance = std::stoi(line_match[3]);

		if (city_id.find(city1) == city_id.end()) {
			city_id[city1] = city_id.size();
		}
		if (city_id.find(city2) == city_id.end()) {
			city_id[city2] = city_id.size();
		}
		distances[city_id[city1]][city_id[city2]] = distance;
		distances[city_id[city2]][city_id[city1]] = distance;
	}

	std::cout << backtracking() << '\n';
	return 0;
}
