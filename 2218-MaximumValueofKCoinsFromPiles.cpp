#include <vector>

class Solution {
public:
int solve(std::vector<std::vector<int>>& piles, std::vector <std::vector<int>>& memo, int idx, int k) {

	if (idx >= piles.size() || k <= 0) return 0;
	
	if (memo[idx][k] != -1) return memo[idx][k];
	
	int score = 0;
	int best = 0;
	best = max(best, solve(piles, memo, idx + 1, k));

	for (int i = 0; i < piles[idx].size() && i < k; i++) {
		score += piles[idx][i];
		best = max(best, solve(piles, memo, idx + 1, k - (i + 1)) + score);
	}

	memo[idx][k] = best;
	return best;
}

int maxValueOfCoins(std::vector<std::vector<int>>& piles, int k) {

	std::vector<std::vector<int>> memo(piles.size(), std::vector<int>(k+1, -1));

	return solve(piles, memo, 0, k);
}
};
