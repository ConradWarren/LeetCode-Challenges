#include <vector>

class Solution {
public:
int maximumSum(std::vector<int>& nums) {

	std::vector<std::pair<int, int>> sum_of_digits(nums.size());
	int best = -1;

	for (int i = 0; i < nums.size(); i++) {
		int temp = nums[i];
		while (temp) {
			sum_of_digits[i].first += (temp % 10);
			temp /= 10;
		}
		sum_of_digits[i].second = nums[i];
	}

	std::sort(sum_of_digits.begin(), sum_of_digits.end());

	for (int i = 0; i < sum_of_digits.size()-1; i++) {

		if (sum_of_digits[i].first == sum_of_digits[i + 1].first) {
			best = max(best, sum_of_digits[i].second + sum_of_digits[i + 1].second);
		}

	}

	return best;
}
};
