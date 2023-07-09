class Solution {
public:
int Find_Largest_Subarry(std::vector<int>& nums_1, std::vector<int>& nums_2, int last_num, int idx, std::vector<int>& cache) {

	if (idx >= nums_1.size()) {
		return 0;
	}

	if (last_num > nums_1[idx] && last_num > nums_2[idx]) {
		return 0;
	}

	if (last_num <= nums_1[idx] && last_num > nums_2[idx]) {
		return 1 + Find_Largest_Subarry(nums_1, nums_2, nums_1[idx], idx + 1, cache);
	}

	if (last_num > nums_1[idx] && last_num <= nums_2[idx]) {
		return 1 + Find_Largest_Subarry(nums_1, nums_2, nums_2[idx], idx + 1, cache);
	}

	if (cache[idx] != -1) {
		return cache[idx];
	}

	int takes_num_1 = 1 + Find_Largest_Subarry(nums_1, nums_2, nums_1[idx], idx + 1, cache);
	int takes_num_2 = 1 + Find_Largest_Subarry(nums_1, nums_2, nums_2[idx], idx + 1, cache);

	cache[idx] = (takes_num_1 > takes_num_2) ? takes_num_1 : takes_num_2;

	return cache[idx];
}

int maxNonDecreasingLength(std::vector<int>& nums1, std::vector<int>& nums2) {


	std::vector<int> cache(nums1.size(), -1);

	int result = 0;
	int current = 0;

	for (int i = 0; i < nums1.size(); i++) {

		if (cache[i] != -1) {
			continue;
		}

		current = Find_Largest_Subarry(nums1, nums2, -1, i, cache);
		result = (result > current) ? result : current;

	}

	return result;
}
};
