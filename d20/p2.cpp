#include <bits/stdc++.h>

int main() {
	int input;
	std::cin >> input;

	std::vector<long long> presents(input + 1);
	for (int i = 1; i <= input; i++) {
		for (int j = 1; j <= 50 && i * j <= input; j++) {
			presents[j * i] += i * 11;
		}
	}

	for (int i = 1; i < input; i++) {
		if (presents[i] >= input) {
			std::cout << i << '\n';
			return 0;
		}
	}

	std::cout << input << '\n';
	return 0;
}
