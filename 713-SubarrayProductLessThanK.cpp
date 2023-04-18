
class Solution {
public:
int numSubarrayProductLessThanK(std::vector<int>& nums, int k) {

	if (k == 0) {
		return 0;
	}

	int current_product = 1;
	int total_sub_arrays = (nums.size() * (nums.size() + 1)) / 2;
	int back_idx = 0;

	for (int i = 0; i < nums.size(); i++) {

		current_product *= nums[i];

		while (current_product >= k && back_idx <= i) {
			total_sub_arrays -= (nums.size() - i);
			current_product /= nums[back_idx];
			back_idx++;
		}
	}

	return total_sub_arrays;
}
};
