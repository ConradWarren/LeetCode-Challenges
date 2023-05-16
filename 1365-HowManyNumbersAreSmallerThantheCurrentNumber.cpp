class Solution {
public:
std::vector<int> smallerNumbersThanCurrent(std::vector<int>& nums) {

	std::vector<int> result(nums.size(), 0);
	std::vector<std::pair<int, int>> sortable_nums(nums.size());
	int equal_num_count = 0;

	for (int i = 0; i < nums.size(); i++) {
		sortable_nums[i].first = nums[i];
		sortable_nums[i].second = i;
	}

	std::sort(sortable_nums.begin(), sortable_nums.end());

	for (int i = 1; i < sortable_nums.size(); i++) {

		equal_num_count = (sortable_nums[i].first == sortable_nums[i - 1].first) ? equal_num_count + 1 : 0;

		result[sortable_nums[i].second] = i - equal_num_count;
	}

	return result;
}
};
