class Solution {
public:
int findMin(std::vector<int>& nums) {
	
	int low = 0;
	int high = nums.size();
	int mid = 0;

	while (low < nums.size() && nums[low] == nums.back()) {
		low++;
	}
	if (low >= nums.size()) {
		return nums.back();
	}

	while (low < high) {

		mid = (low + high) / 2;

		if (nums[mid] > nums.back()) {
			low = mid + 1;
		}
		else {
			high = mid;
		}
		mid = (low + high) / 2;
	}

	return nums[low];
}
};
