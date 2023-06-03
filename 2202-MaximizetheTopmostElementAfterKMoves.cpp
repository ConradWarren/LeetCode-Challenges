#include <vector>

class Solution {
public:
int maximumTop(std::vector<int>& nums, int k) {

	if (nums.empty() || nums.size() == 1 && k % 2) return -1;
	
	if (k == 0) return nums.front();
	
	std::vector<std::pair<int, int>> sortable_nums(nums.size());

	for (int i = 0; i < nums.size(); i++) {
		sortable_nums[i].first = nums[i];
		sortable_nums[i].second = i;
	}

	std::sort(sortable_nums.rbegin(), sortable_nums.rend());

	for (int i = 0; i < sortable_nums.size(); i++) {
		if (sortable_nums[i].second == k || sortable_nums[i].second + 1 < k) {
			return sortable_nums[i].first;
		}
	}
	return -1;
}
};
