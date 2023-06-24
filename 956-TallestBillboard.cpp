#include <vector>

class Solution {
public:
int Max_Two_Equal_Sums(std::vector<int>& nums, int idx, int offset, std::vector<std::vector<int>>& cache) {
	
	if (idx >= nums.size()) return (offset == 0) ? 0 : INT_MIN;

	if (cache[std::abs(offset)][idx] != -1) return cache[std::abs(offset)][idx];
	
	int skip = Max_Two_Equal_Sums(nums, idx + 1, offset, cache);
	int add_to_offset = Max_Two_Equal_Sums(nums, idx + 1, offset + nums[idx], cache) + nums[idx];
	int subtract_from_offset = Max_Two_Equal_Sums(nums, idx + 1, offset - nums[idx], cache) + nums[idx];

	cache[std::abs(offset)][idx] = (skip > add_to_offset && skip > subtract_from_offset) ? skip : (add_to_offset > subtract_from_offset) ? add_to_offset : subtract_from_offset;

	return cache[std::abs(offset)][idx];
}

int tallestBillboard(std::vector<int>& rods) {

	int sum = std::accumulate(rods.begin(), rods.end(), 0);
	std::vector<std::vector<int>> cache(sum, std::vector<int>(rods.size(), -1));
	
	return Max_Two_Equal_Sums(rods, 0, 0, cache) / 2;
}
};
