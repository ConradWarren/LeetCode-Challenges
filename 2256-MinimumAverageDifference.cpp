#include <vector>

class Solution {
public:
int minimumAverageDifference(std::vector<int>& nums) {

	int min_avg_diff = INT_MAX;
	int min_avg_diff_idx = -1;

	long long left_sum = std::accumulate(nums.begin(), nums.end(), 0LL);
	long long right_sum = 0;

	for (int i = 0; i < nums.size(); i++) {

		left_sum -= nums[i];
		right_sum += nums[i];

		long long current_avg_diff = (nums.size() - i - 1 > 0) ? ((right_sum / (i + 1)) - (left_sum / (nums.size() - i - 1))) : right_sum / (i + 1);
		current_avg_diff = (current_avg_diff < 0) ? -current_avg_diff : current_avg_diff;

		if (min_avg_diff > current_avg_diff) {
			min_avg_diff = current_avg_diff;
			min_avg_diff_idx = i;
		}
		
	}

	return min_avg_diff_idx;
}
};
