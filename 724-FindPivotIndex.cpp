#include <vector>

class Solution {
public:
int pivotIndex(std::vector<int>& nums) {

	int right_sum = std::accumulate(nums.begin(), nums.end(), 0);
	int left_sum = 0;

	for (int i = 0; i < nums.size(); i++) {

		left_sum += nums[i];
		right_sum -= nums[i];

		if (left_sum - nums[i] == right_sum) {
			return i;
		}

	}

	

	return -1;
}
};
