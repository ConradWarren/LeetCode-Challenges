#include <vector>

class Solution {
public:
int search(std::vector<int>& nums, int target) {

	int low = 0;
	int high = nums.size();
	int mid = (low + high) / 2;

	while (low < high){

		if (nums[mid] == target) return mid;
		
		if (nums[mid] > nums.back()) low = mid + 1;
		
		else high = mid;
		
		mid = (low + high) / 2;
	}
	
	if (nums[low] == target) return low;
	
	if (target > nums.back()) {
		high = low;
		low = 0;
	}
	else high = nums.size();
	
	while (low < high) {

		mid = (low + high) / 2;
		if (nums[mid] == target) return mid;
		
		if (nums[mid] < target) low = mid+1;
		
		else high = mid;
	}
	return -1;
}
};
