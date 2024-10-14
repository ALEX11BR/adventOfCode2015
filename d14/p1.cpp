#include <bits/stdc++.h>

int main() {
	std::string line;
	std::regex line_regex("[^0-9]*([0-9]*)[^0-9]*([0-9]*)[^0-9]*([0-9]*)[^0-9]*");
	std::smatch line_match;

	int ans = 0;
	while (std::getline(std::cin, line)) {
		std::regex_match(line, line_match, line_regex);

		int speed = std::stoi(line_match[1]);
		int time = std::stoi(line_match[2]);
		int rest = std::stoi(line_match[3]);

		int cycle = time + rest;
		int cycles = 2503 / cycle;
		int remainder = 2503 % cycle;

		int distance = cycles * speed * time + speed * std::min(time, remainder);
		ans = std::max(ans, distance);
	}

	std::cout << ans << '\n';
	return 0;
}
