class Solution {
public:
int Solve_Max_Jumps(std::vector<int>& nums, int idx, int target, std::vector<int>& cache) {

	if (idx + 1 == nums.size()) {
		return 0;
	}

	if (cache[idx] != -1) {
		return cache[idx];
	}

	int jumps = INT_MIN;
	int temp = 0;

	for (int i = idx + 1; i < nums.size(); i++) {

		if (nums[i] - nums[idx] < -target || nums[i] - nums[idx] > target) {
			continue;
		}
		
		temp = 1 + Solve_Max_Jumps(nums, i, target, cache);

		jumps = (jumps > temp) ? jumps : temp;
	}

	cache[idx] = jumps;

	return jumps;
}

int maximumJumps(std::vector<int>& nums, int target) {

	std::vector<int> cache(nums.size() - 1, -1);

	int result = Solve_Max_Jumps(nums,0 , target, cache);
	return (result > 0) ? result : -1;
}
};
