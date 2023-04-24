class Solution {
public:

int Find_Max(std::vector<int>& nums, int low, int high) {

	if (low > high) return INT_MIN;

	int product = 1;
	for (int i = low; i <= high; i++) {
		product *= nums[i];
	}
	if (product > 0) return product;
	
	int option_1 = product;
	int option_2 = product;

	int idx = low;

	while (option_1 < 0 && idx < high) {
		option_1 /= nums[idx];
		idx++;
	}

	while (option_2 < 0 && high > low) {
		option_2 /= nums[high];
		high--;
	}

	return (option_1 > option_2) ? option_1 : option_2;
}

int maxProduct(std::vector<int>& nums) {

	int last_valid_back_idx = -1;
	int best_sub_array = nums[0];
	bool found_zero_flag = false;

	for (int i = 0; i < nums.size(); i++) {

		if (nums[i] != 0 && last_valid_back_idx == -1) last_valid_back_idx = i;
	
		else if (nums[i] == 0 && last_valid_back_idx != -1) {

			found_zero_flag = true;

			best_sub_array = max(best_sub_array, Find_Max(nums, last_valid_back_idx, i - 1));

			last_valid_back_idx = -1;
		}
	}

	if (last_valid_back_idx != -1) {
		best_sub_array = max(best_sub_array, Find_Max(nums, last_valid_back_idx, nums.size() - 1));
	}

	if (best_sub_array < 0 && found_zero_flag) return 0;
	
	return best_sub_array;
}
};
