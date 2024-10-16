#include <algorithm>
#include <array>
#include <cctype>
#include <climits>
#include <cmath>
#include <cstring>
#include <deque>
#include <iostream>
#include <map>
#include <random>
#include <regex>
#include <queue>
#include <set>
#include <sstream>
#include <streambuf>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

std::string look_and_say(std::string in) {
	std::string ans;
	char prev_letter = in[0];
	int prev_times = 1;

	for (int i = 1; i < in.size(); i++) {
		if (prev_letter == in[i]) {
			prev_times++;
		} else {
			ans += std::to_string(prev_times);
			ans += prev_letter;

			prev_letter = in[i];
			prev_times = 1;
		}
	}
	ans += std::to_string(prev_times);
	ans += prev_letter;

	return ans;
}

int main() {
	std::string input;
	std::getline(std::cin, input);

	for (int i = 0; i < 40; i++) {
		input = look_and_say(input);
	}

	std::cout << input.size() << '\n';
	return 0;
}
