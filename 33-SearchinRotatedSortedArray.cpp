#include <vector>

class Solution {
public:
int search(std::vector<int>& nums, int target) {

	int low = 0;
	int high = nums.size();
	int mid = (low + high) / 2;
	int pivot = 0;

	while (low < high) {

		if (nums[mid] > nums.back()) {
			low = mid + 1;
		}
		else if (nums[mid] < nums.back()) {
			high = mid;
			pivot = mid;
		}else{
			pivot = (nums.back() > nums.front()) ? 0 : nums.size()-1;
			break;
		}

		mid = (low + high) / 2;
	}

	if (nums[pivot] == target) {
		return pivot;
	}
	if (nums.back() == target) {
		return nums.size() - 1;
	}


	if (target > nums.back()) {
		low = 0;
		high = pivot;
	}
	else {
		low = pivot;
		high = nums.size();
	}
	mid = (low + high) / 2;
	while (low < high) {

		if (nums[mid] == target) {
			return mid;
		}

		if (nums[mid] < target) {
			low = mid + 1;
		}
		else {
			high = mid;
		}

		mid = (low + high) / 2;
	}
	return (nums[low] == target) ? low : -1;
}
};
