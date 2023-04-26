#include <vector>

class Solution {
public:
std::vector<int> targetIndices(std::vector<int>& nums, int target) {
	
	std::vector<int> result;
	int low = 0;
	int high = nums.size();
	int mid = (low + high)/2;

	std::sort(nums.begin(), nums.end());

	while (low < high) {

		if (nums[mid] < target) low = mid + 1;
		
		else if (nums[mid] > target || (mid > 0 && nums[mid] == target && nums[mid-1] == target)) high = mid;
		
		else {
			result.push_back(mid);
			break;
		}
		mid = (low + high) / 2;
	}

	if (result.empty()) return result;
	
	for (int i = result[0]+1; i < nums.size(); i++) {
		if (nums[i] == target) result.push_back(i);
		
		else break;
	}
	return result;
}
};
