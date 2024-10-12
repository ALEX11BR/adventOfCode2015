#include <bits/stdc++.h>

int main() {
	std::string input;
	std::regex num_regex("[0-9-]+");
	int ans = 0;

	std::getline(std::cin, input);

	std::sregex_iterator number_iterator(input.begin(), input.end(), num_regex);
	for (std::sregex_iterator i = number_iterator; i != std::sregex_iterator(); i++) {
		ans += std::stoi(i->str());
	}

	std::cout << ans << '\n';
	return 0;
}
