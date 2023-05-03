#include <vector>

class Solution {
public:
int waysToSplitArray(std::vector<int>& nums) {

	long long left_sum = 0;
	long long right_sum = std::accumulate(nums.begin(), nums.end(), 0ULL);
	int result = 0;

	for (int i = 0; i < nums.size()-1; i++) {

		left_sum += nums[i];
		right_sum -= nums[i];

		if (left_sum >= right_sum) {
			result++;
		}

	}

	return result;
}
};
