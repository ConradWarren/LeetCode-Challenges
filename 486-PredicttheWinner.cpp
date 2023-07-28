#include <vector>

class Solution {
public:
int Nega_Max_Search(std::vector<int>& nums, int left_edge, int right_edge, std::vector<std::vector<int>>& cache) {

	if (left_edge > right_edge) {
		return 0;
	}

	if (cache[left_edge][right_edge] != -1) {
		return cache[left_edge][right_edge];
	}

	int takes_left = nums[left_edge] - Nega_Max_Search(nums, left_edge + 1, right_edge, cache);
	int takes_right = nums[right_edge] - Nega_Max_Search(nums, left_edge, right_edge-1, cache);

	return (takes_left > takes_right) ? takes_left : takes_right;
}

bool PredictTheWinner(std::vector<int>& nums) {
	
	std::vector<std::vector<int>> cache(nums.size(), std::vector<int>(nums.size(), -1));

	return (Nega_Max_Search(nums, 0, nums.size() - 1, cache) >= 0);
}
};
