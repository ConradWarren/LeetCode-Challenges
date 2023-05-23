#include <vector>

class Solution {
public:
int coinChange(std::vector<int>& coins, int amount) {

	std::vector<int> dp(amount + 1, INT_MAX);
	dp[0] = 0;

	for (int i = 0; i < coins.size(); i++) {
		for (int j = 0; j + coins[i] <= amount; j++) {
			if (dp[j] != INT_MAX) dp[j + coins[i]] = (dp[j + coins[i]] < dp[j] + 1) ? dp[j + coins[i]] : dp[j] + 1;
		}
	}

	return (dp.back() != INT_MAX) ? dp.back() : -1;
}
};
