class Solution {
public:
bool checkArray(std::vector<int>& nums, int k) {

	std::vector<int> delta_arr(nums.size() + k + 1, 0);

	int offset = 0;

	for (int i = 0; i < nums.size()-k+1; i++) {

		offset += delta_arr[i];

		nums[i] -= offset;

		if (nums[i] < 0) {
			return false;
		}

		delta_arr[i + k] -= nums[i];

		offset += nums[i];
		nums[i] = 0;
	}

	for (int i = nums.size() - k + 1; i < nums.size(); i++) {
		offset += delta_arr[i];

		nums[i] -= offset;

		if (nums[i] != 0) {
			return false;
		}
	}

	return true;
}
};
