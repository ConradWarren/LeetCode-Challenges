#include <vector>

class Solution {
public:
int Solve_Max(std::vector<int>& nums, int idx, std::vector<int>& cache) {

	if (idx >= nums.size())return 0;
	
	if (cache[idx] != -1) return cache[idx];
	
	int skips_house = Solve_Max(nums, idx + 1, cache);

	int robs_house = nums[idx] + Solve_Max(nums, idx + 2, cache);

	cache[idx] = (skips_house > robs_house) ? skips_house : robs_house;

	return cache[idx];
}


int rob(std::vector<int>& nums) {

	if (nums.size() == 1) return nums[0];
	
	std::vector<int> cache_1(nums.size(), -1);
	std::vector<int> cache_2(nums.size()-1, -1);

	int option_1 = Solve_Max(nums, 1, cache_1);
	nums.pop_back();
	int option_2 = Solve_Max(nums, 0, cache_2);

	return (option_1 > option_2) ? option_1 : option_2;
}
};
