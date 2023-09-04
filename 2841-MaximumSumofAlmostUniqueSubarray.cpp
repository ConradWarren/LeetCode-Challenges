class Solution {
public:
long long maxSum(std::vector<int>& nums, int m, int k) {

	std::unordered_map<int, int> num_occurances;
	int current = 0;
	int back_idx = 0;
	long long result = 0;
	long long sum = 0;
	
	for (int i = 0; i < k; i++) {
		num_occurances[nums[i]]++;
		sum += nums[i];
		if (num_occurances[nums[i]] == 1) {
			current++;
		}
	}

	if (current >= m) {
		result = sum;
	}

	for (int i = k; i < nums.size(); i++) {

		num_occurances[nums[i]]++;
		sum += nums[i];
		if (num_occurances[nums[i]] == 1) {
			current++;
		}

		num_occurances[nums[back_idx]]--;
		sum -= nums[back_idx];
		if (num_occurances[nums[back_idx]] == 0) {
			current--;
		}

		
		if (current >= m && sum > result) {
			result = sum;
		}
		
		back_idx++;
	}

	return result;
}
};
