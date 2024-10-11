#include <bits/stdc++.h>

int main() {
	std::string input;
	std::regex line_regex("(turn on|turn off|toggle) ([0-9]*),([0-9]*) through ([0-9]*),([0-9]*)");
	std::smatch line_match;

	auto on = [](bool x) { return true; };
	auto off = [](bool x) { return false; };
	auto toggle = [](bool x) { return !x; };

	std::vector<std::vector<bool>> lights(1000, std::vector<bool>(1000, false));
	while (std::getline(std::cin, input)) {
		std::regex_match(input, line_match, line_regex);

		int ls = std::stoi(line_match[2]);
		int cs = std::stoi(line_match[3]);
		int le = std::stoi(line_match[4]);
		int ce = std::stoi(line_match[5]);

		auto fn = (line_match[1] == "toggle") ? toggle : (line_match[1] == "turn on") ? on : off;
		for (int i = ls; i <= le; i++) {
			for (int j = cs; j <= ce; j++) {
				lights[i][j] = fn(lights[i][j]);
			}
		}
	}

	int ans = 0;
	for (int i = 0; i < 1000; i++) {
		for (int j = 0; j < 1000; j++) {
			ans += (int)lights[i][j];
		}
	}

	std::cout << ans << '\n';
	return 0;
}
