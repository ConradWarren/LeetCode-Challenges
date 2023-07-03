#include <vector>

class Solution {
public:
int longestAlternatingSubarray(std::vector<int>& nums, int threshold) {

	int longest_sub_array = 0;
	int current_sub_array = 0;
	int target = 0;

	for (int i = 0; i < nums.size(); i++) {
		
		if (nums[i] % 2 == target && nums[i] <= threshold) {
			current_sub_array++;
			target ^= 1;
		}
		else if(nums[i]%2 == 0 && nums[i] <= threshold) {
			current_sub_array = 1;
			target = 1;
		}
		else {
			current_sub_array = 0;
			target = 0;
		}

		longest_sub_array = (longest_sub_array > current_sub_array) ? longest_sub_array : current_sub_array;
	}


	return longest_sub_array;
}
};
