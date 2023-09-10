#include <vector>

class Solution {
public:
int Solve_Min_Operations(std::vector<int>& nums_1, std::vector<int>& nums_2, int idx, int last_1, int last_2,bool last_swaped, std::vector<std::vector<int>>& cache) {

	if (idx >= nums_1.size()) {
		return 0;
	}

	if (cache[(last_swaped) ? 0 : 1][idx] != -1) {
		return cache[(last_swaped) ? 0 : 1][idx];
	}

	int skip = (last_1 < nums_1[idx] && last_2 < nums_2[idx]) ? Solve_Min_Operations(nums_1, nums_2, idx + 1, nums_1[idx], nums_2[idx],false, cache) : INT_MAX;

	int swap = (last_1 < nums_2[idx] && last_2 < nums_1[idx]) ? 1 + Solve_Min_Operations(nums_1, nums_2, idx + 1, nums_2[idx], nums_1[idx],true, cache) : INT_MAX;
	

	cache[(last_swaped) ? 0 : 1][idx] = (skip < swap) ? skip : swap;

	return (skip < swap) ? skip : swap;
}

int minSwap(std::vector<int>& nums1, std::vector<int>& nums2) {

	std::vector<std::vector<int>> cache(2, std::vector<int>(nums1.size(), -1));
	
	return Solve_Min_Operations(nums1, nums2, 0, -1, -1, false, cache);
}
};
