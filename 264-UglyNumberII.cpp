#include <vector>

class Solution {
public:
int nthUglyNumber(int n) {

	std::vector<int> nums(n);
	int idx_1 = 0;
	int idx_2 = 0;
	int idx_3 = 0;

	nums[0] = 1;
	
	for (int i = 1; i < n; i++) {

		int option_1 = nums[idx_1] * 2;
		int option_2 = nums[idx_2] * 3;
		int option_3 = nums[idx_3] * 5;

		if (option_1 < option_2 && option_1 < option_3) {
			if (option_1 == nums[i - 1]) {
				idx_1++;
				i--;
				continue;
			}
			nums[i] = option_1;
			idx_1++;
		}
		else if (option_2 < option_3) {
			if (option_2 == nums[i - 1]) {
				idx_2++;
				i--;
				continue;
			}
			nums[i] = option_2;
			idx_2++;
		}
		else {
			if (option_3 == nums[i - 1]) {
				idx_3++;
				i--;
				continue;
			}
			nums[i] = option_3;
			idx_3++;
		}
	}
	return nums.back();
}
};
