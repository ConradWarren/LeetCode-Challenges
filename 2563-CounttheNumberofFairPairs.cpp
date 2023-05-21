class Solution {
public:
long long countFairPairs(std::vector<int>& nums, int lower, int upper) {

	long long pair_counts = 0;

	std::sort(nums.begin(), nums.end());

	for (int i = 0; i < nums.size(); i++) {

		int low = i + 1;
		int high = nums.size();
		int mid = (low + high) / 2;
		int lower_bound = 0;
		int upper_bound = 0;

		while (low < high) {
			if (nums[i] + nums[mid] >= lower) high = mid;
			
			else low = mid + 1;
			
			mid = (high + low) / 2;
		}

		lower_bound = high;

		if (lower_bound == nums.size() || nums[i] + nums[lower_bound] > upper) continue;
		
		low = lower_bound;
		high = nums.size();
		mid = (low + high) / 2;

		while (low < high) {

			if (nums[i] + nums[mid] <= upper) low = mid + 1;
			
			else high = mid;
			
			mid = (low + high) / 2;
		}

		upper_bound = low - 1;

		pair_counts += (upper_bound - lower_bound + 1);
	}

	return pair_counts;
}
};
