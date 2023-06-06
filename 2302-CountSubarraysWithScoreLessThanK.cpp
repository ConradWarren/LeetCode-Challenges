#include <vector>

class Solution {
public:
long long countSubarrays(std::vector<int>& nums, long long k) {

	int back_idx = 0;
	long long score = 0;
	long long sum = 0;
	long long result = ((long long)(nums.size()) * (long long)(nums.size() + 1)) / 2;;

	for (int i = 0; i < nums.size(); i++) {

		sum += nums[i];
		score = sum * (long long)(i - back_idx + 1);

		while (score >= k) {
			result -= (nums.size() - i);
			sum -= nums[back_idx];
			back_idx++;
			score = sum * (long long)(i - back_idx + 1);
		}
	}

	return result;
}
};
