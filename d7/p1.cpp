#include <bits/stdc++.h>

struct WireValues {
	std::map<std::string, std::vector<std::string>> values;
	std::map<std::string, unsigned int> cache;

	unsigned int evaluate(std::string key) {
		if (values[key][1] == "ID") {
			return get_value(values[key][2]);
		}
		if (values[key][1] == "NOT") {
			return ~get_value(values[key][2]);
		}
		if (values[key][1] == "AND") {
			return get_value(values[key][0]) & get_value(values[key][2]);
		}
		if (values[key][1] == "OR") {
			return get_value(values[key][0]) | get_value(values[key][2]);
		}
		if (values[key][1] == "LSHIFT") {
			return get_value(values[key][0]) << get_value(values[key][2]);
		}
		if (values[key][1] == "RSHIFT") {
			return get_value(values[key][0]) >> get_value(values[key][2]);
		}

		std::cerr << "ERROR\n";
		return 0;
	}
	unsigned int get_value(std::string key) {
		if (key.find_first_not_of("1234567890") == std::string::npos) {
			return std::stoi(key);
		}

		if (cache.find(key) == cache.end()) {
			cache[key] = evaluate(key);
		}
		return cache[key];
	}
};

int main() {
	std::string input;

	WireValues values;

	while (std::getline(std::cin, input)) {
		std::string token, destination;
		std::vector<std::string> tokens;
		std::stringstream line_stream(input);

		while (line_stream >> token) {
			if (token == "->") {
				break;
			}
			tokens.push_back(token);
		}
		line_stream >> destination;

		if (tokens.size() == 1) {
			tokens.insert(tokens.begin(), "ID");
		}
		if (tokens.size() == 2) {
			tokens.insert(tokens.begin(), "1");
		}

		values.values[destination] = tokens;
	}

	std::cout << values.evaluate("a") << '\n';
	return 0;
}
