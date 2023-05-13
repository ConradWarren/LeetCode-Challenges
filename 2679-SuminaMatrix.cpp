#include <vector>

class Solution {
public:
int matrixSum(std::vector<std::vector<int>>& nums) {

	int score = 0;
	int current_highest = 0;

	for (int i = 0; i < nums.size(); i++) {
		std::sort(nums[i].rbegin(), nums[i].rend());
	}

	for (int i = 0; i < nums[0].size(); i++) {
		current_highest = 0;
		for (int j = 0; j < nums.size(); j++) {
			current_highest = (current_highest > nums[j][i]) ? current_highest : nums[j][i];
		}
		score += current_highest;
	}

	return score;
}
};
