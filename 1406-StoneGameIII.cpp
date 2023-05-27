#include <vector>

class Solution {
public:
int Solve(int idx, std::vector<int>& nums, std::vector<int>& cache) {

	if (idx >= nums.size()) return 0;
	
	if (cache[idx] != INT_MIN) return cache[idx];
	
	int sum = 0;
	int best_score = INT_MIN;
	int score = 0;
	
	for (int i = idx; i < idx + 3 && i < nums.size(); i++) {

		sum += nums[i];

		score = sum - Solve(i + 1, nums, cache);
		
		best_score = (best_score > score) ? best_score : score;
	}

	cache[idx] = best_score;

	return best_score;
}

std::string stoneGameIII(std::vector<int>& stoneValue) {

	std::vector<int> cache(stoneValue.size(), INT_MIN);

	int score = Solve(0, stoneValue, cache);

	return (score == 0) ? "Tie" : (score < 0) ? "Bob" : "Alice";
}
};
