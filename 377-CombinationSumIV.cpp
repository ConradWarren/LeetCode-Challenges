class Solution {
public:
int combinationSum4(std::vector<int>& nums, int target) {

	std::vector<unsigned int> dp(target + 1, 0);
	dp[0] = 1;
	

	for (int i = 0; i < dp.size(); i++) {

		if (dp[i] == 0) {
			continue;
		}

		for (int j = 0; j < nums.size(); j++) {
			if (nums[j] + i >= dp.size()) {
				continue;
			}

			dp[i + nums[j]] += dp[i];
		}

	}

	return dp.back();
}
};
