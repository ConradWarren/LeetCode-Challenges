#include <vector>

class Solution {
public:
int maxDotProduct(std::vector<int>& nums1, std::vector<int>& nums2) {

	std::vector<std::vector<int>> dp(nums1.size() + 1, std::vector<int>(nums2.size() + 1, -10000000));

	for (int i = nums1.size() - 1; i >= 0; i--) {

		for (int j = nums2.size() - 1; j >= 0; j--) {

			dp[i][j] = (nums1[i] * nums2[j]);
			
			dp[i][j] += (dp[i + 1][j + 1] < 0) ? 0 : dp[i + 1][j + 1];

			dp[i][j] = (dp[i][j] > dp[i + 1][j]) ? dp[i][j] : dp[i+1][j];

			dp[i][j] = (dp[i][j] > dp[i][j+1]) ? dp[i][j] : dp[i][j+1];
		}
	}


	return dp[0][0];
}
};
