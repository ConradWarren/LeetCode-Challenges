#include <vector>

class Solution {
public:
int maximumBeauty(std::vector<int>& nums, int k) {

	std::sort(nums.begin(), nums.end());

	int back_idx = 0;
	int max_length = 0;

	for (int i = 0; i < nums.size(); i++) {

		while (nums[back_idx] + (2 * k) < nums[i]) {
			back_idx++;
		}

		max_length = (max_length > (i - back_idx + 1)) ? max_length : (i - back_idx + 1);
	}

	return max_length;
}
};
