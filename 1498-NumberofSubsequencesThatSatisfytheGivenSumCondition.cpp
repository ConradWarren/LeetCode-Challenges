#include <vector>

class Solution {
public:
int numSubseq(std::vector<int>& nums, int target) {
	std::vector<int> number_of_sequences(nums.size());
	int low = 0;
	int high = nums.size() - 1;
	int result = 0;

	std::sort(nums.begin(), nums.end());

	number_of_sequences[0] = 1;
	for (int i = 1; i < nums.size(); i++) {
		number_of_sequences[i] = (number_of_sequences[i - 1] * 2) % 1000000007;
	}

	while (low <= high) {

		if (nums[low] + nums[high] <= target) {
			result += number_of_sequences[high - low];
			result %= 1000000007;
			low++;
		}
		else {
			high--;
		}


	}

	return result;
}
};
