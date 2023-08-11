#include <vector>

class Solution {
public:
int change(int amount, std::vector<int>& coins) {

	std::vector<int> dp(amount + 1, 0);
	int current = 0;
	dp[0] = 1;

	for (int j = 0; j < coins.size(); j++) {
		for (int i = 0; i + coins[j] <= amount; i++) {
			
			if (dp[i]) {
				dp[i + coins[j]] += dp[i];
			}

		}
	}
	

	return dp.back();
}
};
