#include <bits/stdc++.h>

int main() {
	std::string input;
	std::getline(std::cin, input);

	int level = 0;
	for (const char &c : input) {
		switch (c) {
		case '(':
			level += 1;
			break;
		case ')':
			level -= 1;
			break;
		}
	}

	std::cout << level << '\n';
	return 0;
}
