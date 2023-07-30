#include <vector>

class Solution {
public:
long long maxArrayValue(std::vector<int>& nums) {
	

	long long current_largest = nums.back();

	for (int i = nums.size() - 2; i >= 0; i--) {


		if (nums[i] > current_largest) {
			current_largest = nums[i];
		}
		else {
			current_largest += nums[i];
		}

	}

	return current_largest;
}
};
