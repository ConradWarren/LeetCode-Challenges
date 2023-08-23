#include <vector>

class Solution {
public:
int Find_Min_Operations(std::vector<int>& nums, int idx, int last_valid, std::vector<std::vector<int>>& cache) {

	if (idx >= nums.size()) {
		return 0;
	}

	if (cache[last_valid][idx] != -1) {
		return cache[last_valid][idx];
	}

	int skip = (nums[idx] >= last_valid) ? Find_Min_Operations(nums, idx + 1, nums[idx], cache) : INT_MAX;

	int change = 1 + Find_Min_Operations(nums, idx + 1, last_valid, cache);

	cache[last_valid][idx] = (skip < change) ? skip : change;

	return (skip < change) ? skip : change;
}

int minimumOperations(std::vector<int>& nums) {

	std::vector<std::vector<int>> cache(4, std::vector<int>(nums.size(), -1));

	return Find_Min_Operations(nums, 0, 1, cache);
}
};
