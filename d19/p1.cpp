#include <bits/stdc++.h>

int main() {
	std::string input;
	std::map<std::string, std::vector<std::string>> transforms;

	while (true) {
		std::getline(std::cin, input);
		if (input.empty()) {
			break;
		}

		int eq_pos = input.find_first_of('=');

		std::string from = input.substr(0, eq_pos - 1);
		std::string to = input.substr(eq_pos + 3);

		if (transforms.find(from) == transforms.end()) {
			transforms[from] = std::vector<std::string>();
		}
		transforms[from].push_back(to);
	}

	std::getline(std::cin, input);

	std::set<std::string> combinations;

	for (const auto &el : transforms) {
		for (int i = 0; i < input.size(); i++) {
			if (input.substr(i, el.first.size()) == el.first) {
				for (const auto &dest : el.second) {
					std::string res = input;
					combinations.insert(res.replace(i, el.first.size(), dest));
				}
			}
		}
	}

	std::cout << combinations.size() << '\n';
	return 0;
}
