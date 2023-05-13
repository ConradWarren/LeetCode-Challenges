#include <vector>

class Solution {
public:
int countGoodStrings(int low, int high, int zero, int one) {

	std::vector<int> dp(high + 1, 0);
	int result = 0;

	dp[0] = 1;

	for (int i = 0; i < dp.size(); i++) {

		if (!dp[i]) continue;

		dp[i] %= 1000000007;
		
		if (i + zero <= high) dp[i + zero] += dp[i];
		
		if (i + one <= high) dp[i + one] += dp[i];
	}

	for (int i = low; i <= high; i++) {
		result += dp[i];
		result %= 1000000007;
	}

	return result;
}
};
