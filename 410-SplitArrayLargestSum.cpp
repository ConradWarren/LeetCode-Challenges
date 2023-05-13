class Solution {
public:
bool Is_Possible(std::vector<int>& nums, int k, int max) {

	int sum = 0;
	for (int i = 0; i < nums.size(); i++) {

		if (sum + nums[i] <= max) sum += nums[i];
		
		else {
			sum = nums[i];
			k--;

			if (k <= 0) return false;
		}
	}
	return true;
}

int splitArray(std::vector<int>& nums, int k) {

	int high = std::accumulate(nums.begin(), nums.end() - k +1, 0);
	int low = 0;
	int mid = 0;

	for (int i = nums.size() - k + 1; i < nums.size(); i++) {
		high = (high > nums[i]) ? high : nums[i];
	}
	for (int i = 0; i < nums.size(); i++) {
		low = (low > nums[i]) ? low : nums[i];
	}

	mid = (low + high) / 2;

	while (low < high) {

		if (Is_Possible(nums, k, mid)) high = mid;
		
		else low = mid + 1;
		
		mid = (low + high) / 2;
	}

	return high;
}
};
