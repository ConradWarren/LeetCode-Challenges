#include <vector>

class Solution {
public:
std::vector<int> runningSum(std::vector<int>& nums) {

	int rolling_sum = 0;
	for (int i = 0; i < nums.size(); i++) {
		rolling_sum += nums[i];
		nums[i] = rolling_sum;
	}

	return nums;
}
};
