#include <bits/stdc++.h>

int main() {
	std::string input;
	std::getline(std::cin, input);

	std::pair<int, int> current = {0, 0};
	std::set<std::pair<int, int>> visited;
	visited.insert({0, 0});

	for (const char &c : input) {
		switch (c) {
		case '^':
			current.first += 1;
			break;
		case 'v':
			current.first -= 1;
			break;
		case '<':
			current.second -= 1;
			break;
		case '>':
			current.second += 1;
			break;
		}

		visited.insert(current);
	}

	std::cout << visited.size() << '\n';
	return 0;
}
