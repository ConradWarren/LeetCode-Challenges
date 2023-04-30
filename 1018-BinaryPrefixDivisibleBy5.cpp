#include <vector>

class Solution {
public:
std::vector<bool> prefixesDivBy5(std::vector<int>& nums) {

	std::vector<bool> result(nums.size(), false);

	int current_value = 0;

	for (int i = 0; i < nums.size(); i++) {

		current_value = (current_value * 2) + nums[i];
		current_value %= 5;

		if (!current_value) {
			result[i] = true;
		}

	}

	return result;
}
};
