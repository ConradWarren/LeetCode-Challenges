#include <vector>

class Solution {
public:
int longestArithSeqLength(std::vector<int>& nums) {

	std::vector<std::vector<int>> cache(1001, std::vector<int>(nums.size(), 1));
	int longest_sequence = 1;
	
	for (int i = nums.size() - 1; i >= 0; i--) {

		for (int j = i + 1; j < nums.size(); j++) {

			cache[nums[i] - nums[j] + 500][i] = (cache[nums[i] - nums[j] + 500][i] > cache[nums[i] - nums[j] + 500][j] + 1) ? cache[nums[i] - nums[j] + 500][i] : cache[nums[i] - nums[j] + 500][j] + 1;

			longest_sequence = (longest_sequence > cache[nums[i] - nums[j] + 500][i]) ? longest_sequence : cache[nums[i] - nums[j] + 500][i];
		}

	}

	return longest_sequence;
}
};
