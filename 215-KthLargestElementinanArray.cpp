#include <vector>

class Solution {
public:
int findKthLargest(std::vector<int>& nums, int k) {

	int smallest_num = INT_MAX;
	int largest_num = INT_MIN;
	std::vector<int> counts;

	for (int i = 0; i < nums.size(); i++) {
		smallest_num = (smallest_num < nums[i]) ? smallest_num : nums[i];
		largest_num = (largest_num > nums[i]) ? largest_num : nums[i];
	}

	counts.resize(std::abs(largest_num)+std::abs(smallest_num) + 1, 0);


	for (int i = 0; i < nums.size(); i++) {
		counts[nums[i] + std::abs(smallest_num)]++;
	}

	for (int i = counts.size() - 1; i >= 0; i--) {
		if (counts[i]) {
			k -= counts[i];
			if (k <= 0) return i - std::abs(smallest_num);
		}
	}
	return 0;
}
};
