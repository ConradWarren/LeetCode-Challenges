#include <vector>

class Solution {
public:
int Solve_Min_ASCII(std::string& s1, std::string& s2, int idx_1, int idx_2, std::vector<std::vector<int>>& cache) {

	if (idx_1 >= s1.length() && idx_2 >= s2.length()) {
		return 0;
	}

	if (cache[idx_1][idx_2] != -1) {
		return cache[idx_1][idx_2];
	}

	if (idx_1 >= s1.length()) {
		cache[idx_1][idx_2] = std::accumulate(s2.begin() + idx_2, s2.end(), 0);
		return cache[idx_1][idx_2];
	}
	if (idx_2 >= s2.length()) {
		cache[idx_1][idx_2] = std::accumulate(s1.begin() + idx_1, s1.end(), 0);
		return cache[idx_1][idx_2];
	}

	if (s1[idx_1] == s2[idx_2]) {
		return Solve_Min_ASCII(s1, s2, idx_1 + 1, idx_2 + 1, cache);
	}

	int remove_1 = Solve_Min_ASCII(s1, s2, idx_1 + 1, idx_2, cache) + s1[idx_1];
	int remove_2 = Solve_Min_ASCII(s1, s2, idx_1, idx_2+1, cache) + s2[idx_2];

	cache[idx_1][idx_2] = (remove_1 < remove_2) ? remove_1 : remove_2;

	return cache[idx_1][idx_2];
}

int minimumDeleteSum(std::string s1, std::string s2) {

	std::vector<std::vector<int>> cache(s1.length()+1, std::vector<int>(s2.length()+1, -1));

	return Solve_Min_ASCII(s1, s2, 0, 0, cache);
}
};
