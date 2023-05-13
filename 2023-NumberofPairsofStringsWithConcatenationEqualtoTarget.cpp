#include <vector>

class Solution {
public:
int numOfPairs(std::vector<std::string>& nums, std::string target) {

	int result = 0;

	for (int i = 0; i < nums.size(); i++) {

		if (nums[i][0] != target[0] || nums[i] != target.substr(0, nums[i].size())) continue;
		
		for (int j = 0; j < nums.size(); j++) {

			if (j == i || target[nums[i].length()] != nums[j][0]) continue;
			
			if (nums[j] == target.substr(nums[i].length())) result++;
		}
	}

	return result;
}
};
