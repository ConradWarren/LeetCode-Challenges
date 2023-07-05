#include <vector>

class Solution {
public:
int longestSubarray(std::vector<int>& nums) {

	int last_subarray_length = 0;
	int current_subarray_length = 0;
	int best_subarray_length = 0;
	int all_one_flag = 1;
	
	for (int i = 0; i < nums.size(); i++) {

		if (nums[i] != 1) {
			all_one_flag = 0;
			best_subarray_length = (best_subarray_length > current_subarray_length + last_subarray_length) ? best_subarray_length : current_subarray_length + last_subarray_length;

			last_subarray_length = current_subarray_length;
			current_subarray_length = 0;
		}
		else {
			current_subarray_length++;
		}
	}
	best_subarray_length = (best_subarray_length > current_subarray_length + last_subarray_length) ? best_subarray_length : current_subarray_length + last_subarray_length;

	return best_subarray_length - all_one_flag;
}
};
