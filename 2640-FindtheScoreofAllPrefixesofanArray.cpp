#include <vector>

class Solution {
public:
std::vector<long long> findPrefixScore(std::vector<int>& nums) {

	int current_max = 0;
	std::vector<long long> result(nums.size());

	for (int i = 0; i < nums.size(); i++) {
		current_max = (current_max > nums[i]) ? current_max : nums[i];
		result[i] = nums[i] + current_max;
	}

	for (int i = 1; i < result.size(); i++) {
		result[i] += result[i - 1];
	}

	return result;
}
};
