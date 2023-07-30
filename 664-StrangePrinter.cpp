#include <vector>

class Solution {
public:
int Solve(std::string& s, int left, int right, std::vector<std::vector<int>>& cache) {

	if (left == right) {
		return 1;
	}

	if (left > right) {
		return 0;
	}

	if (cache[left][right] != -1) {
		return cache[left][right];
	}

	int best = 1 + Solve(s, left + 1, right, cache);
	int current = 0;

	for (int i = left + 1; i <= right; i++) {
		if (s[left] == s[i]) {
			current = Solve(s, left, i - 1, cache) + Solve(s, i + 1, right, cache);
			best = (best < current) ? best : current;
		}
	}

	cache[left][right] = best;

	return best;
}


int strangePrinter(std::string s) {
	
	std::vector<std::vector<int>> cache(s.length(), std::vector<int>(s.length(), -1));

	return Solve(s, 0, s.length() - 1, cache);
}
};
