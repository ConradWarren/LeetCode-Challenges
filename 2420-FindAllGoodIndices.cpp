class Solution {
public:
std::vector<int> goodIndices(std::vector<int>& nums, int k) {

	std::vector<bool> valid_non_increasing_idx(nums.size(), false);
	std::vector<int> result;

	int count = 1;


	for (int i = 1; i < nums.size(); i++) {

		if (count >= k) valid_non_increasing_idx[i] = true;
		
		if (nums[i] <= nums[i - 1]) count++;
		
		else count = 1;
	}
	count = 1;
	for (int i = nums.size() - 2; i >= 0; i--) {

		if (count >= k && valid_non_increasing_idx[i]) result.push_back(i);
		
		if (nums[i] <= nums[i + 1]) count++;
		
		else count = 1;
	}

	std::reverse(result.begin(), result.end());

	return result;
}
};
