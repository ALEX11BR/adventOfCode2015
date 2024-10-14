#include <bits/stdc++.h>

std::vector<int> quantities;
int sum;
int backtracking(const std::vector<std::vector<int>> &ingredients) {
	if (ingredients.size() == quantities.size()) {
		if (sum != 100) {
			return 0;
		}

		int calories = 0;
		for (int j = 0; j < quantities.size(); j++) {
			calories += ingredients[j][4] * quantities[j];
		}
		if (calories != 500) {
			return 0;
		}

		int ans = 1;
		for (int i = 0; i < 4; i++) {
			int component = 0;
			for (int j = 0; j < quantities.size(); j++) {
				component += ingredients[j][i] * quantities[j];
			}

			ans *= std::max(component, 0);
		}

		return ans;
	}

	int ans = 0;
	for (int i = (quantities.size() == ingredients.size() - 1) ? 100 - sum : 0; i <= 100 - sum; i++) {
		quantities.push_back(i);
		sum += i;

		ans = std::max(ans, backtracking(ingredients));

		sum -= i;
		quantities.pop_back();
	}
	return ans;
}

int main() {
	std::string line;
	std::regex number_regex("[-0-9]+");
	std::smatch number_match;

	std::vector<std::vector<int>> ingredients;
	while (std::getline(std::cin, line)) {
		std::vector<int> parameters;

		while (std::regex_search(line, number_match, number_regex)) {
			parameters.push_back(std::stoi(number_match.str()));
			line = number_match.suffix();
		}
		ingredients.push_back(parameters);
	}

	std::cout << backtracking(ingredients) << '\n';
	return 0;
}
