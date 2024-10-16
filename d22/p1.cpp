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

struct Game {
	int enemy_hp, enemy_damage;
	int hp = 50, mana = 500, armor = 0, mana_spent = 0;
	int turns_shield = 0, turns_poison = 0, turns_recharge = 0;

	void apply_effects() {
		if (turns_shield > 0) {
			armor = 7;
			turns_shield--;
		} else {
			armor = 0;
		}

		if (turns_poison > 0) {
			enemy_hp -= 3;
			turns_poison--;
		}

		if (turns_recharge > 0) {
			mana += 101;
			turns_recharge--;
		}
	}

	void get_attacked() {
		hp -= std::max(1, enemy_damage - armor);
	}

	bool spend_mana(int cost) {
		if (cost > mana) {
			return false;
		}

		mana -= cost;
		mana_spent += cost;

		return true;
	}

	bool player_action(int action) {
		switch (action) {
		case 0: // Magic Missile
			if (!spend_mana(53)) {
				return false;
			}
			enemy_hp -= 4;
			break;
		case 1: // Drain
			if (!spend_mana(73)) {
				return false;
			}
			enemy_hp -= 2;
			hp += 2;
			break;
		case 2: // Shield
			if (turns_shield > 0) {
				return false;
			}
			if (!spend_mana(113)) {
				return false;
			}
			turns_shield = 6;
			break;
		case 3: // Poison
			if (turns_poison > 0) {
				return false;
			}
			if (!spend_mana(173)) {
				return false;
			}
			turns_poison = 6;
			break;
		case 4: // Recharge
			if (turns_recharge > 0) {
				return false;
			}
			if (!spend_mana(229)) {
				return false;
			}
			turns_recharge = 5;
			break;
		}

		return true;
	}
};

int main() {
	std::string input;
	Game game;

	std::getline(std::cin, input);
	game.enemy_hp = std::stoi(input.substr(input.find(':') + 2));

	std::getline(std::cin, input);
	game.enemy_damage = std::stoi(input.substr(input.find(':') + 2));

	int ans = INT_MAX;
	std::queue<Game> q;
	std::multiset<int> spents;

	q.push(game);
	spents.insert(0);

	while (!q.empty()) {
		if (*spents.cbegin() >= ans) {
			break;
		}
		game = q.front();
		q.pop();
		spents.erase(game.mana_spent);
		if (ans <= game.mana_spent) {
			continue;
		}

		game.apply_effects();
		if (game.enemy_hp <= 0) {
			ans = std::min(ans, game.mana_spent);
			continue;
		}

		for (int i = 0; i < 5; i++) {
			Game g = game;
			if (!g.player_action(i)) {
				continue;
			}
			if (g.enemy_hp <= 0) {
				ans = std::min(ans, g.mana_spent);
				continue;
			}

			g.apply_effects();
			if (g.enemy_hp <= 0) {
				ans = std::min(ans, g.mana_spent);
				continue;
			}

			g.get_attacked();
			if (g.hp <= 0) {
				continue;
			}
			if (g.enemy_hp <= 0) {
				ans = std::min(ans, g.mana_spent);
				continue;
			}

			q.push(g);
			spents.insert(g.mana_spent);
		}
	}

	std::cout << ans << '\n';
	return 0;
}
