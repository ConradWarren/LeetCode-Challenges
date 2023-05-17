#include <vector>

class Solution {
public:
int lengthOfLIS(std::vector<int>& nums){

	std::vector<int> sequence_lengths(nums.size(), 1);
	int longest_sequence = 1;

	for (int i = 1; i < nums.size(); i++) {

		for (int j = 0; j < i; j++) {
			if (nums[j] < nums[i]) {
				sequence_lengths[i] = (sequence_lengths[i] > sequence_lengths[j] + 1) ? sequence_lengths[i] : sequence_lengths[j] + 1;
			}
		}
		longest_sequence = (longest_sequence > sequence_lengths[i]) ? longest_sequence : sequence_lengths[i];
	}

	return longest_sequence;
}
};
