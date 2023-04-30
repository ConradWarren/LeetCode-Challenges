#include <vector>

class Solution {
public:
long long countOperationsToEmptyArray(std::vector<int>& nums) {

	std::vector<std::pair<int, int>> sortable_nums(nums.size());
	int current_idx = -1;
	int removed_elements = 0;
	long long operation_count = 0;

	for (int i = 0; i < nums.size(); i++) {
		sortable_nums[i].first = nums[i];
		sortable_nums[i].second = i;
	}

	std::sort(sortable_nums.begin(), sortable_nums.end());

	for (int i = 0; i < sortable_nums.size(); i++) {

		if (sortable_nums[i].second < current_idx) {
			operation_count += (nums.size() - removed_elements);
			removed_elements = i;
			current_idx = sortable_nums[i].second;
		}
		else current_idx = sortable_nums[i].second;
		
	}
	operation_count += (nums.size() - removed_elements);

	return operation_count;
}
};
