#include <bits/stdc++.h>

std::string increment(std::string in) {
	int i = in.size() - 1;

	in[i]++;
	while (in[i] > 'z') {
		in[i] = 'a';

		if (i == 0) {
			break;
		}
		i--;
		in[i]++;
	}
	return in;
}

bool check_pass(const std::string &in) {
	int repeating_pairs = 0;
	bool increasing_trifecta = false;

	for (int i = 0; i < in.size(); i++) {
		if (std::strchr("iol", in[i]) != NULL) {
			return false;
		}
	}

	for (int i = 1; i < in.size(); i++) {
		if (in[i - 1] == in[i]) {
			repeating_pairs++;
			i++;
		}
	}

	for (int i = 2; i < in.size(); i++) {
		if (in[i - 2] + 2 == in[i - 1] + 1 && in[i] == in[i - 1] + 1) {
			increasing_trifecta = true;
			break;
		}
	}

	return increasing_trifecta && repeating_pairs >= 2;
}

int main() {
	std::string input;
	std::getline(std::cin, input);

	do {
		input = increment(input);
	} while (!check_pass(input));

	std::cout << input << '\n';
	return 0;
}
