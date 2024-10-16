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
#include <openssl/md5.h>

bool good_hash(unsigned char *hash) {
	return hash[0] == 0 && hash[1] == 0 && (hash[2] & 0xf0) == 0;
}

int main() {
	std::string input;
	std::getline(std::cin, input);

	int i = 0;
	while (true) {
		std::string maybe_key = input + std::to_string(i);
		unsigned char *hash = MD5((unsigned char *)maybe_key.c_str(), maybe_key.size(), NULL);

		if (good_hash(hash)) {
			break;
		}

		i++;
	}

	std::cout << i << '\n';
	return 0;
}
