#include <bits/stdc++.h>

int main() {
	std::string line;
	std::regex line_regex("Sue [0-9]+: ([^:]*): ([0-9]+), ([^:]*): ([0-9]+), ([^:]*): ([0-9]+)");
	std::smatch line_match;

	std::vector<std::map<std::string, int>> aunts;
	while (std::getline(std::cin, line)) {
		std::regex_match(line, line_match, line_regex);

		std::map<std::string, int> current_aunt;
		current_aunt[line_match[1]] = std::stoi(line_match[2]);
		current_aunt[line_match[3]] = std::stoi(line_match[4]);
		current_aunt[line_match[5]] = std::stoi(line_match[6]);

		aunts.push_back(current_aunt);
	}

	std::map<std::string, int> target;
	target["children"] = 3;
	target["cats"] = 7;
	target["samoyeds"] = 2;
	target["pomeranians"] = 3;
	target["akitas"] = 0;
	target["vizslas"] = 0;
	target["goldfish"] = 5;
	target["trees"] = 3;
	target["cars"] = 2;
	target["perfumes"] = 1;

	for (int i = 0; i < aunts.size(); i++) {
		bool is_ok = true;
		for (const auto &prop : aunts[i]) {
			if (prop.second != target[prop.first]) {
				is_ok = false;
			}
		}

		if (is_ok) {
			std::cout << i + 1 << '\n';
			return 0;
		}
	}

	return 1;
}
