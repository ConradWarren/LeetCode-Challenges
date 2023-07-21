#include <vector>

class Solution {
public:
int findNumberOfLIS(std::vector<int>& nums) {

	std::vector<int> dp_path(nums.size(), 1);
	std::vector<int> dp_counts(nums.size(), 1);
	int max_length = 0;
	int count = 0;

	for (int i = 0; i < nums.size(); i++) {

		for (int j = 0; j < i; j++) {

			if(nums[j] >= nums[i]) {
				continue;
			}

			if (dp_path[j] + 1 > dp_path[i]) {
				dp_path[i] = dp_path[j] + 1;
				dp_counts[i] = dp_counts[j];
			}
			else if (dp_path[j]+1 == dp_path[i]) {
				dp_counts[i] += dp_counts[j];
			}
		}
	}

	for (int i = 0; i < dp_path.size(); i++) {
		max_length = (max_length > dp_path[i]) ? max_length : dp_path[i];
	}

	for (int i = 0; i < dp_path.size(); i++) {
		count += (dp_path[i] == max_length) ? dp_counts[i] : 0;
	}


	return count;
}
};
