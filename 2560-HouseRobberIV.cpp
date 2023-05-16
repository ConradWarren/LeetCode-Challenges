bool Is_Valid_Capability(std::vector<int>& nums, int k, int capablity) {

	int idx = 0;

	while (idx < nums.size() && k > 0) {

		if (nums[idx] <= capablity) {
			k--;
			idx += 2;
		}
		else idx++;
	}

	return (k == 0) ? true: false;
}

int minCapability(std::vector<int>& nums, int k) {

	int high = INT_MIN;
	int low = INT_MAX;
	int mid = 0;

	for (int i = 0; i < nums.size(); i++) {
		high = (high > nums[i]) ? high : nums[i];
		low = (low < nums[i]) ? low : nums[i];
	}

	while (low < high) {
		
		mid = (low + high) / 2;

		if (Is_Valid_Capability(nums, k, mid)) high = mid;
		
		else low = mid + 1;
		
	}

	return high;
}
