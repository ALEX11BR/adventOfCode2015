#include <bits/stdc++.h>

bool good_str(const std::string &str) {
	bool has_pair = false;
	bool has_double = false;

	for (int i = 0; i < str.size(); i++) {
		if (i > 1 && str[i] == str[i - 2]) {
            has_double = true;
        }

        if (!has_pair) {
            for (int j = i + 2; j <str.size(); j++) {
                if (str[i] ==str[j] && str[i+1] == str[j+1]) {
                    has_pair = true;
                    break;
                }
            }
        }
	}

	return has_double && has_pair;
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
