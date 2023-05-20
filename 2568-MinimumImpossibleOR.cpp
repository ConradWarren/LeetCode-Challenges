#include <vector>

class Solution {
public:
int minImpossibleOR(std::vector<int>& nums) {

	int single_bit_bitmask = 0;
	int most_signifigant_bit = 1;
	int result = 1;

	std::sort(nums.begin(), nums.end());

	if (nums.front() > 1) return 1;
	
	for (int i = 0; i < nums.size(); i++) {

		while (most_signifigant_bit < nums[i]) {
			most_signifigant_bit <<= 1;
		}

		if (most_signifigant_bit == nums[i]) {
			single_bit_bitmask |= most_signifigant_bit;
			most_signifigant_bit <<= 1;
		}
	}

	while (result & single_bit_bitmask) {
		result <<= 1;
	}

	return result;
}
};
