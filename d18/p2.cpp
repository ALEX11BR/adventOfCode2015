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

int count_neighbors(const std::vector<std::vector<bool>> &lights, int i, int j) {
	int ans = 0;

	for (int ii = -1; ii < 2; ii++) {
		for (int jj = -1; jj < 2; jj++) {
			if ((ii == 0 && jj == 0) || i + ii < 0 || i + ii >= 100 || j + jj < 0 || j + jj >= 100) {
				continue;
			}

			if (lights[i + ii][j + jj]) {
				ans++;
			}
		}
	}

	return ans;
}

int main() {
	std::string input;

	std::vector<std::vector<bool>> lights;
	while (std::getline(std::cin, input)) {
		std::vector<bool> light_line;

		for (const char &c : input) {
			if (c == '#') {
				light_line.push_back(true);
			} else {
				light_line.push_back(false);
			}
		}

		lights.push_back(light_line);
	}

	for (int t = 0; t < 100; t++) {
		lights[0][0] = true;
		lights[0][99] = true;
		lights[99][0] = true;
		lights[99][99] = true;
		auto new_lights = lights;

		for (int i = 0; i < 100; i++) {
			for (int j = 0; j < 100; j++) {
				int neighbors = count_neighbors(lights, i, j);

				new_lights[i][j] = neighbors == 3 || (neighbors == 2 && lights[i][j]);
			}
		}

		lights = new_lights;
	}

	int ans = 0;
	lights[0][0] = true;
	lights[0][99] = true;
	lights[99][0] = true;
	lights[99][99] = true;
	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++) {
			if (lights[i][j]) {
				ans++;
			}
		}
	}
	std::cout << ans << '\n';
	return 0;
}
