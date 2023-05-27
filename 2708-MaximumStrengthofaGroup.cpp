#include <vector>

class Solution {
public:
long long maxStrength(std::vector<int>& nums) {

	int non_zero_count = 0;
	long long product = 1;
	int smallest_negative = INT_MIN;

	for (int i = 0; i < nums.size(); i++) {
		if (nums[i] != 0) {
			product *= nums[i];
			non_zero_count++;
		}
	}

	if (non_zero_count == 0) return 0;
	
	if (product > 0) return product;
	
	if (product < 0 && non_zero_count == 1) return (nums.size() == 1) ? product : 0;
	
	for (int i = 0; i < nums.size(); i++) {
		if (nums[i] < 0) smallest_negative = (smallest_negative > nums[i]) ? smallest_negative : nums[i];
	}

	return product / smallest_negative;
}
};
