#include <vector>
#include <numeric>

class Solution {
public:
int minOperations(std::vector<int>& nums, int x) {
	
	int target = std::accumulate(nums.begin(), nums.end(), 0) - x;
	int back_idx = 0;
	int current = 0;
	int result = INT_MAX;

	if (target < 0) return -1;

	for (int i = 0; i < nums.size(); i++) {
		
		target -= nums[i];

		while (target < 0){
			target += nums[back_idx];
			back_idx++;
		}

		if (target == 0) {
			current = back_idx + nums.size() - 1 - i;
			result = (result < current) ? result : current;
		}
	}

	return (result != INT_MAX) ? result : -1;
}
};
