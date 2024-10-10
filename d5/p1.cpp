#include <bits/stdc++.h>

bool good_str(const std::string &str) {
	int vowels = 0;
	bool has_double = false;
	char prev = 0;

	if (str.find("ab") != std::string::npos || str.find("cd") != std::string::npos ||
		str.find("pq") != std::string::npos || str.find("xy") != std::string::npos) {
		return false;
	}

	for (const char &c : str) {
		if (std::strchr("aeiou", c) != NULL) {
			vowels++;
		}

		if (prev == c) {
			has_double = true;
		}
		prev = c;
	}

	return has_double && vowels >= 3;
}

int main() {
	std::string input;

	int ans = 0;
	while (std::getline(std::cin, input)) {
		if (good_str(input)) {
			ans++;
		}
	}

	std::cout << ans << '\n';
	return 0;
}
