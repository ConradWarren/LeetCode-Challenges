class Solution {
public:
double new21Game(int n, int k, int maxPts) {

	std::vector<double> dp(n + maxPts + 1, 0.0);
	double last_sum = 0.0;

	for (int i = k; i <= n; i++) {
		dp[i] = 1.0;
	}

	last_sum = std::accumulate(dp.begin() + k, dp.begin() + k + maxPts, 0.0);

	for (int i = k - 1; i >= 0; i--) {
		dp[i] = last_sum;
		dp[i] /= maxPts;
		last_sum += dp[i];
		last_sum -= dp[i + maxPts];
	}

	return dp[0];
}
};
