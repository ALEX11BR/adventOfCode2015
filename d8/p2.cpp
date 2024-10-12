#include <bits/stdc++.h>

int main() {
	std::string input;

	int ans = 0;
	while (std::getline(std::cin, input)) {
		ans += 2;
		for (int i = 0; i < input.size(); i++) {
			switch (input[i]) {
			case '\"':
			case '\\':
				ans += 1;
			}
		}
	}

	std::cout << ans << '\n';
	return 0;
}
