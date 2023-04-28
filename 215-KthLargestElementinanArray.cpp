#include <vector>

class Solution {
public:
int findKthLargest(std::vector<int>& nums, int k) {

	std::vector<int> count(20001, 0);

	for (int i = 0; i < nums.size(); i++) {
		count[nums[i] + 10000]++;
	}

	for (int i = 20000; i >= 0; i--) {

		k -= count[i];
		if (k <= 0) {
			return i - 10000;
		}
	}


	return 0;
}
};
