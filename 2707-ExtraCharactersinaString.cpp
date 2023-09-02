#include <vector>

class Solution {
public:
int Solve_Min(std::string& s, int idx, std::vector<std::string>& dictionary, std::vector<int>& cache) {

	if (idx >= s.length()) {
		return 0;
	}

	if (cache[idx] != -1) {
		return cache[idx];
	}

	int current = 1 + Solve_Min(s, idx + 1, dictionary, cache);
	int best = current;

	for (int i = 0; i < dictionary.size(); i++) {

		if (s.substr(idx, dictionary[i].length()) != dictionary[i]) {
			continue;
		}

		current = Solve_Min(s, idx + dictionary[i].length(), dictionary, cache);
		best = (best < current) ? best : current;
	}

	cache[idx] = best;
	return best;
}

int minExtraChar(std::string s, std::vector<std::string>& dictionary) {
	
	std::vector<int> cache(s.length(), -1);

	return Solve_Min(s, 0, dictionary, cache);
}
};
