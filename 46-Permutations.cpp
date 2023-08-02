#include <vector>

class Solution {
public:
void permutation_builder(std::vector<int>& nums, std::vector<bool> used_idx,std::vector<int>& current, std::vector<std::vector<int>>& result) {

	if (current.size() == nums.size()) {
		result.push_back(current);
		return;
	}

	for (int i = 0; i < nums.size(); i++) {

		if (used_idx[i]) {
			continue;
		}
		
		used_idx[i] = true;
		current.push_back(nums[i]);
		permutation_builder(nums, used_idx, current, result);
		current.pop_back();
		used_idx[i] = false;
	}
}

std::vector<std::vector<int>> permute(std::vector<int>& nums) {

	std::vector<bool> used_idx(nums.size(), false);
	std::vector<std::vector<int>> result;
	std::vector<int> current;

	permutation_builder(nums, used_idx, current, result);

	return result;
}
};
