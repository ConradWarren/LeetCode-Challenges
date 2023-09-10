class Solution {
public:
int countOrders(int n) {
	
	std::vector<long long> dp(n + 1, 0);
	dp[0] = 1;

	for (int i = 1; i <= n; i++) {
		dp[i] = (dp[i - 1] * (i * (i + (i - 1)))) % ((long long)(1e9) + 7LL);
	}

	return dp.back();
}
};
