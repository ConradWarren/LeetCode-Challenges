#include <vector>

class Solution {
public:
int Solve_Max(std::vector<int>& nums, int idx, std::vector<int>& cache) {

	if (idx >= nums.size()) {
		return 0;
	}

	if (cache[idx] != -1) {
		return cache[idx];
	}

	int skips_house = Solve_Max(nums, idx + 1, cache);

	int robs_house = nums[idx] + Solve_Max(nums, idx + 2, cache);

	cache[idx] = (skips_house > robs_house) ? skips_house : robs_house;

	return cache[idx];
}


int rob(std::vector<int>& nums) {

	std::vector<int> cache(nums.size(), -1);

	return Solve_Max(nums, 0, cache);
}
};
