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

struct Racer {
	int speed;
	int time;
	int rest;

	int distance_at_time(int t) {
		int cycle = time + rest;
		int cycles = t / cycle;
		int remainder = t % cycle;

		int distance = cycles * speed * time + speed * std::min(time, remainder);
		return distance;
	}
};

int main() {
	std::string line;
	std::regex line_regex("[^0-9]*([0-9]*)[^0-9]*([0-9]*)[^0-9]*([0-9]*)[^0-9]*");
	std::smatch line_match;

	int ans = 0;
	std::vector<Racer> racers;
	while (std::getline(std::cin, line)) {
		std::regex_match(line, line_match, line_regex);

		int speed = std::stoi(line_match[1]);
		int time = std::stoi(line_match[2]);
		int rest = std::stoi(line_match[3]);

		racers.push_back({speed, time, rest});
	}

	std::vector<int> points(racers.size(), 0);
	for (int t = 1; t <= 2503; t++) {
		std::vector<int> winners;
		int winning_distance = -1;

		for (int i = 0; i < racers.size(); i++) {
			int distance = racers[i].distance_at_time(t);

			if (distance > winning_distance) {
				winners = std::vector<int>();
				winning_distance = distance;
			}
			if (distance == winning_distance) {
				winners.push_back(i);
			}
		}

		for (const int &winner : winners) {
			points[winner]++;
		}
	}

	std::cout << *std::max_element(points.begin(), points.end()) << '\n';
	return 0;
}
