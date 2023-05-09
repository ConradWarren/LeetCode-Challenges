class Solution {
public:
void Merge_Sort(std::vector<std::string>& nums, int low, int high) {

	if (low >= high) {
		return;
	}

	int mid = (low + high) / 2;

	Merge_Sort(nums, low, mid);
	Merge_Sort(nums, mid+1,high);

	int idx_1 = low;
	int idx_2 = mid+1;
	std::vector<std::string> sorted_nums(high - low + 1);

	while (idx_1 <= mid && idx_2 <= high) {

		int current_idx = 0;

		while (current_idx < nums[idx_1].length() && current_idx < nums[idx_2].length() && nums[idx_1][current_idx] == nums[idx_2][current_idx]) {
			current_idx++;
		}

		if (current_idx >= nums[idx_1].length() || current_idx >= nums[idx_2].length()) {
			unsigned long long temp_1_first = std::stoull(nums[idx_1] + nums[idx_2]);
			unsigned long long temp_2_first = std::stoull(nums[idx_2] + nums[idx_1]);

			if (temp_1_first > temp_2_first) {

				sorted_nums[idx_1 + idx_2 - low - mid - 1] = nums[idx_1];
				idx_1++;

			}
			else {
				sorted_nums[idx_1 + idx_2 - low - mid - 1] = nums[idx_2];
				idx_2++;
			}
		}
		else if (nums[idx_1][current_idx] > nums[idx_2][current_idx]) {
			sorted_nums[idx_1 + idx_2 - low - mid - 1] = nums[idx_1];
			idx_1++;
		}
		else {
			sorted_nums[idx_1 + idx_2 - low - mid - 1] = nums[idx_2];
			idx_2++;
		}

	}

	while (idx_1 <= mid) {
		sorted_nums[idx_1 + idx_2 - low - mid - 1] = nums[idx_1];
		idx_1++;
	}
	while (idx_2 <= high) {
		sorted_nums[idx_1 + idx_2 - low - mid - 1] = nums[idx_2];
		idx_2++;
	}

	for (int i = 0; i < sorted_nums.size(); i++) {
		nums[i + low] = sorted_nums[i];
	}

}


std::string largestNumber(std::vector<int>& nums) {

	std::vector<std::string> sortable_nums(nums.size());
	std::string result;

	bool found_non_zero = false;
	for (int i = 0; i < sortable_nums.size(); i++) {
		if (nums[i]) {
			found_non_zero = true;
		}
		sortable_nums[i] = std::to_string(nums[i]);
	}

	if (!found_non_zero) {
		return "0";
	}

	Merge_Sort(sortable_nums, 0, sortable_nums.size() - 1);

	
	for (int i = 0; i < sortable_nums.size(); i++) {
		result += sortable_nums[i];
	}

	return result;
}
};
