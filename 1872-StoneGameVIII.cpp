#include <vector>

int stoneGameVIII(std::vector<int>& stones) {

	if (stones.size() == 2) {
		return stones[0] + stones[1];
	}

	std::vector<int> dp(stones.size(), 0);

	for (int i = 1; i < stones.size(); i++) {
		stones[i] += stones[i - 1];
	}

	dp.back() = stones.back();

	for (int i = stones.size() - 2; i >= 1; i--) {
		dp[i] = (stones[i] - dp[i + 1] > dp[i + 1]) ? stones[i] - dp[i + 1] : dp[i + 1];
	}

	return dp[1];
}
