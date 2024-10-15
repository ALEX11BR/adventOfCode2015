#include <bits/stdc++.h>

int main() {
	int input;
	std::cin >> input;

	std::vector<long long> presents(input + 1);
	for (int i = 1; i <= input; i++) {
		for (int j = i; j <= input; j += i) {
			presents[j] += i;
		}
	}

	for (int i = 1; i < input; i++) {
		if (presents[i] >= (input / 10)) {
			std::cout << i << '\n';
			return 0;
		}
	}

	std::cout << input << '\n';
	return 0;
}
