class Solution {
public:
int longestSubarray(std::vector<int>& nums) {

	int max_num = 0;
	int longest_length = 1;

	for (int i = 0; i < nums.size(); i++) {
		max_num = (max_num > nums[i]) ? max_num : nums[i];
	}

	for (int i = 0; i < nums.size(); i++) {

		if (nums[i] != max_num) continue;
		
		int current_num = max_num;
		int idx = i - 1;

		while (idx >= 0 && (nums[idx] & current_num) == max_num) {
			idx--;
		}
		longest_length = (longest_length > i - idx) ? longest_length : i - idx;
		idx = i + 1;

		while (idx < nums.size() && (nums[idx] & current_num) == max_num) {
			idx++;
		}
		longest_length = (longest_length > idx - i) ? longest_length : idx - i;
		i = idx;
	}
	return longest_length;
}
};
