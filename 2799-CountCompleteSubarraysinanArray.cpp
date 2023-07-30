#include <vector>
#include <unordered_map>

class Solution {
public:
int countCompleteSubarrays(std::vector<int>& nums) {

	std::unordered_map<int, int> num_occurances;
	int target = 0;
	int current = 0;
	int back_idx = 0;
	int result = 0;

	for (int i = 0; i < nums.size(); i++) {

		num_occurances[nums[i]]++;
		if (num_occurances[nums[i]] == 1) {
			target++;
		}
	}

	num_occurances.clear();

	for (int i = 0; i < nums.size(); i++) {

		num_occurances[nums[i]]++;
		if (num_occurances[nums[i]] == 1) {
			current++;
		}

		while (current == target) {

			result += (nums.size() - i);
			num_occurances[nums[back_idx]]--;
			if (num_occurances[nums[back_idx]] == 0) {
				current--;
			}
			back_idx++;
		}
	}

	return result;
}
};
