#include <vector>

class Solution {
public:
std::vector<int> getAverages(std::vector<int>& nums, int k) {

	if (k == 0) return nums;
	
	std::vector<int> result(nums.size(), -1);

	if ((2 * k) >= nums.size()) return result;
	
	long long sum = 0;
	int back_idx = 0;

	for (int i = 0; i <= 2 * k && i < nums.size(); i++) {
		sum += nums[i];
	}

	result[k] = sum / ((2 * k) + 1);

	for (int i = (2 * k)+1; i < nums.size(); i++) {
		sum -= nums[back_idx];
		sum += nums[i];
		back_idx++;
		result[i - k] = sum / ((2 * k) + 1);
	}

	return result;
}
};
