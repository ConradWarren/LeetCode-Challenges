class Solution {
public:
long long maximumOr(std::vector<int>& nums, int k) {

	long long common_bitmask = 0;
	long long max_bitmask = ((long long)(nums[0]) << k);
	int max_idx = 0;

	for (int i = 1; i < nums.size(); i++) {

		if ((common_bitmask | nums[max_idx] | ((long long)(nums[i]) << k)) > (common_bitmask | max_bitmask | nums[i])) {
			common_bitmask |= nums[max_idx];
			max_idx = i;
			max_bitmask = ((long long)(nums[i]) << k);
		}
		else {
			common_bitmask |= nums[i];
		}

	}

	return common_bitmask | max_bitmask;
}
};
