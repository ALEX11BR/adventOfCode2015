#include <bits/stdc++.h>

std::array<std::array<int, 8>, 8> gains;

std::vector<int> permutation;
std::vector<bool> used(8, false);

int backtracking() {
	int ans = INT_MIN;

	if (permutation.size() == 8) {
		ans = 0;
		for (int i = 0; i < 7; i++) {
			ans += gains[permutation[i]][permutation[i + 1]];
		}
		for (int i = 1; i < 8; i++) {
			ans += gains[permutation[i]][permutation[i - 1]];
		}
		ans += gains[permutation[0]][permutation[7]] + gains[permutation[7]][permutation[0]];
		return ans;
	}

	for (int i = 0; i < 8; i++) {
		if (!used[i]) {
			permutation.push_back(i);
			used[i] = true;

			ans = std::max(ans, backtracking());

			used[i] = false;
			permutation.pop_back();
		}
	}
	return ans;
}

int main() {
	std::string input;
	std::regex line_regex("([^ ]*) would ([^ ]*) ([^ ]*) .* ([^ ]*)\\.");
	std::smatch line_match;

	std::map<std::string, int> name_id;

	while (std::getline(std::cin, input)) {
		std::regex_match(input, line_match, line_regex);

		std::string name1 = line_match[1];
		std::string name2 = line_match[4];
		int gain = std::stoi(line_match[3]) * (line_match[2] == "lose" ? -1 : 1);

		if (name_id.find(name1) == name_id.end()) {
			name_id[name1] = name_id.size();
		}
		if (name_id.find(name2) == name_id.end()) {
			name_id[name2] = name_id.size();
		}

		gains[name_id[name1]][name_id[name2]] = gain;
	}

	std::cout << backtracking() << '\n';
	return 0;
}
