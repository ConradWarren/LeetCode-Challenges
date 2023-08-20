#include <vector<=>

class Solution {
public:
int longestEqualSubarray(std::vector<int>& nums, int k) {

	std::vector<std::pair<int, int>> sortable_nums(nums.size());
	int back_idx = 0;
	int skips = 0;
	int result = 1;
	
	for (int i = 0; i < nums.size(); i++) {
		sortable_nums[i].first = nums[i];
		sortable_nums[i].second = i;
	}
	std::sort(sortable_nums.begin(), sortable_nums.end());

	for (int i = 1; i < sortable_nums.size(); i++) {

		if (sortable_nums[i].first != sortable_nums[back_idx].first) {
			back_idx = i;
			skips = 0;
		}
		else {
			skips += sortable_nums[i].second - sortable_nums[i - 1].second - 1;
		}

		while (skips > k) {
			skips -= sortable_nums[back_idx + 1].second - sortable_nums[back_idx].second - 1;
			back_idx++;
		}

		result = (result > (i - back_idx + 1)) ? result : (i - back_idx + 1);
	}

	return result;
}
};
