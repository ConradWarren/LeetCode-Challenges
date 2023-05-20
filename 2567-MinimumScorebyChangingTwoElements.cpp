#include <vector>

class Solution {
public:
int minimizeSum(std::vector<int>& nums) {

	std::sort(nums.begin(), nums.end());


	int option_1 = std::abs(nums[0] - nums[nums.size() - 3]);
	int option_2 = std::abs(nums[2] - nums[nums.size() - 1]);
	int option_3 = std::abs(nums[1] - nums[nums.size() - 2]);

	return (option_1 < option_2) ? ((option_3 < option_1) ? option_3 : option_1) : ((option_3 < option_2) ? option_3 : option_2);
}
};
