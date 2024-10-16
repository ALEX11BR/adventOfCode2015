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

struct Stats {
	int hp, damage, armor;

	Stats operator+(const Stats &rhs) {
		return {hp + rhs.hp, damage + rhs.damage, armor + rhs.armor};
	}

	void fight_with(const Stats &other) {
		hp -= std::max(0, other.damage - armor);
	}
};

bool simulate(Stats player, Stats boss) {
	while (true) {
		boss.fight_with(player);
		if (boss.hp <= 0) {
			return true;
		}

		player.fight_with(boss);
		if (player.hp <= 0) {
			return false;
		}
	}
}

int main() {
	std::string input;
	Stats boss, player = {100, 0, 0};

	std::getline(std::cin, input);
	boss.hp = std::stoi(input.substr(input.find(':') + 2));

	std::getline(std::cin, input);
	boss.damage = std::stoi(input.substr(input.find(':') + 2));

	std::getline(std::cin, input);
	boss.armor = std::stoi(input.substr(input.find(':') + 2));

	int ans = INT_MAX;
	std::vector<Stats> weapons{
		{8, 4, 0}, {10, 5, 0}, {25, 6, 0}, {40, 7, 0}, {74, 8, 0},
	};
	std::vector<Stats> armors{
		{0, 0, 0}, {13, 0, 1}, {31, 0, 2}, {53, 0, 3}, {75, 0, 4}, {102, 0, 5},
	};
	std::vector<Stats> rings{
		{25, 1, 0}, {50, 2, 0}, {100, 3, 0}, {20, 0, 1}, {40, 0, 2}, {80, 0, 3}, {0, 0, 0},
	};

	for (const auto &weapon : weapons) {
		for (const auto &armor : armors) {
			for (int i = 0; i < rings.size(); i++) {
				for (int j = std::min(i + 1, (int)rings.size() - 1); j < rings.size(); j++) {
					Stats this_player = player + weapon + armor + rings[i] + rings[j];
					this_player.hp = player.hp;

					if (simulate(this_player, boss)) {
						ans = std::min(ans, weapon.hp + armor.hp + rings[i].hp + rings[j].hp);
					}
				}
			}
		}
	}

	std::cout << ans << '\n';
	return 0;
}
