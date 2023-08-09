#include <vector>

class Solution {
public:
bool Is_Valid(std::vector<int>& nums, int target,int p, std::vector<int>& cache) {

	
	for (int i = 0; i < nums.size()-1 && p; i++) {

		if (cache[i] == target) {
			continue;
		}

		if (nums[i + 1] - nums[i] <= target) {
			p--;
			cache[i + 1] = target;
		}
	}

	return (p == 0);
}

int minimizeMax(std::vector<int>& nums, int p) {
	
	std::vector<int> cache(nums.size(), -1);
	int low = 0;
	int high = 0;
	int mid = 0;

	std::sort(nums.begin(), nums.end());

	high = nums.back() - nums.front() + 1;
	
	while (low < high) {

		mid = (low + high) / 2;

		if (Is_Valid(nums, mid, p, cache)) {
			high = mid;
		}
		else {
			low = mid + 1;
		}
	}

	return high;
}
};
