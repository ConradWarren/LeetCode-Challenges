#include <vector>

class Solution {
public:
int Solve_Max_Mcore(std::vector<int>& multipliers, std::vector<int>& nums, int low, int high, int idx, std::vector<std::vector<int>>& cache) {
	
	if (idx >= multipliers.size()) {
		return 0;
	}

	if (cache[low][high] != -1) {
		return cache[low][high];
	}
	
	int score_low = (multipliers[idx] * nums[low]) + Solve_Max_Mcore(multipliers, nums, low+1, high, idx+1, cache);
	int score_high = (multipliers[idx] * nums[nums.size()-1-high]) + Solve_Max_Mcore(multipliers, nums, low, high + 1, idx + 1, cache);

	cache[low][high] = (score_low > score_high) ? score_low : score_high;

	return cache[low][high];
}

int maximumScore(std::vector<int>& nums, std::vector<int>& multipliers) {

	std::vector<std::vector<int>> cache(multipliers.size(), std::vector<int>(multipliers.size(), -1));

	return Solve_Max_Mcore(multipliers, nums, 0, 0, 0, cache);
}
};
