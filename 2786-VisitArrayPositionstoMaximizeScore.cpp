#include <vector>

class Solution {
public:
long long Solve_Max_Score(std::vector<int>& nums, int idx,int last_valid, int x, std::vector<std::vector<long long>>& cache) {

	if (idx >= nums.size()) {
		return 0;
	}

	if (nums[idx] % 2 == last_valid % 2 && cache[0][idx] != -1) {
		return cache[0][idx];
	}
	else if (nums[idx] % 2 != last_valid % 2 && cache[1][idx] != -1) {
		return cache[1][idx];
	}

	long long skip = Solve_Max_Score(nums, idx + 1, last_valid, x, cache);

	long long takes = Solve_Max_Score(nums, idx + 1, nums[idx], x, cache)+nums[idx];
	takes -= (nums[idx]%2 == last_valid%2) ? 0 : x;
	
	if (nums[idx]%2 == last_valid%2) {
		cache[0][idx] = (skip > takes) ? skip : takes;
	}
	else {
		cache[1][idx] = (skip > takes) ? skip : takes;
	}

	return (skip > takes) ? skip : takes;
}

long long maxScore(std::vector<int>& nums, int x) {

	std::vector<std::vector<long long>> cache(2, std::vector<long long>(nums.size(), -1));

	return Solve_Max_Score(nums, 1, nums[0], x, cache) + nums[0];
}
};
