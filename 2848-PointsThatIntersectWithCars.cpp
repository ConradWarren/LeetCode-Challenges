class Solution {
public:
int numberOfPoints(std::vector<std::vector<int>>& nums) {

	int right_edge = 0;
	int result = 0;
	std::sort(nums.begin(), nums.end());


	for (int i = 0; i < nums.size(); i++) {

		if (nums[i][1] <= right_edge) continue;
		
		right_edge = (nums[i][0] > right_edge) ? nums[i][0] - 1 : right_edge;

		result += (nums[i][1] - right_edge);
		right_edge = nums[i][1];
	}

	return result;
}
};
