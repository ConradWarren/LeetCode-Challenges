#include <vector>

class Solution {
public:
bool Solve(std::vector<int>& nums, int idx, std::vector<bool>& cache) {

	if (idx >= nums.size()) {
		return true;
	}

	if (!cache[idx]) {
		return false;
	}

	if (idx + 1 < nums.size() && nums[idx] == nums[idx + 1] && Solve(nums, idx+2, cache)) {
		return true;
	}
	if (idx + 2 < nums.size() && nums[idx] == nums[idx + 1] && nums[idx] == nums[idx+2] && Solve(nums, idx + 3, cache)) {
		return true;
	}
	if (idx + 2 < nums.size() && nums[idx]+1 == nums[idx + 1] && nums[idx + 1]+1 == nums[idx + 2] && Solve(nums, idx + 3, cache)) {
		return true;
	}

	cache[idx] = false;
	return false;
}


bool validPartition(std::vector<int>& nums) {

	std::vector<bool> cache(nums.size(), true);
	
	return Solve(nums, 0, cache);
}
};
