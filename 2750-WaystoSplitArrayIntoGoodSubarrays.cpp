#include <vector>

class Solution {
public:
int numberOfGoodSubarraySplits(std::vector<int>& nums) {

	int mod = int(1e9) + 7;
	long long array_count = 1;
	long long zero_count = 0;
	
	int idx = 0;
	for (idx = 0; idx < nums.size(); idx++) {
		if (nums[idx] == 1) {
			break;
		}
	}

	if (idx >= nums.size()) {
		return 0;
	}

	for (int i = idx + 1; i < nums.size(); i++) {

		if (nums[i] == 1) {
			array_count *= (zero_count + 1);
			array_count %= mod;
			zero_count = 0;
		}
		else {
			zero_count++;
		}
	}

	return int(array_count);
}
};
