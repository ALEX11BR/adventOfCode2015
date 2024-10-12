#include <bits/stdc++.h>

int main() {
	std::string input;
	std::regex num_regex("[0-9-]+");
	int ans = 0;

	std::getline(std::cin, input);

	std::vector<int> object_starts;
	int remove_object = -1;
	for (int i = 0; i < input.size(); i++) {
		switch (input[i]) {
		case '{':
			object_starts.push_back(i);
			break;
		case ':':
			if (remove_object == -1 && input.substr(i + 1, 5) == "\"red\"") {
				remove_object = object_starts.size();
			}
			break;
		case '}':
			if (remove_object == object_starts.size()) {
				remove_object = -1;

				for (int j = object_starts.back(); j <= i; j++) {
					input[j] = ' ';
				}
			}
			object_starts.pop_back();
			break;
		}
	}

	std::sregex_iterator number_iterator(input.begin(), input.end(), num_regex);
	for (std::sregex_iterator i = number_iterator; i != std::sregex_iterator(); i++) {
		ans += std::stoi(i->str());
	}

	std::cout << ans << '\n';
	return 0;
}
