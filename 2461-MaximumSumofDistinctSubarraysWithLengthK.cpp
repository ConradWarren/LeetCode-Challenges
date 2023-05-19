#include <vector>
#include <unordered_map>

class Solution {
public:
long long maximumSubarraySum(std::vector<int>& nums, int k) {

	int current_length = 0;
	int back_idx = 0;
	long long sum = 0;
	long long max_sum = 0;
	std::unordered_map<int, int> num_occurances;

	for (int i = 0; i < nums.size(); i++) {
		num_occurances[nums[i]]++;
		current_length++;
		sum += nums[i];

		while (num_occurances[nums[i]] > 1) {
			num_occurances[nums[back_idx]]--;
			sum -= nums[back_idx];
			current_length--;
			back_idx++;
		}

		if (current_length == k) {
			max_sum = (max_sum > sum) ? max_sum : sum;
			current_length--;
			num_occurances[nums[back_idx]]--;
			sum -= nums[back_idx];
			back_idx++;
		}
	}
	return max_sum;
}
};
