class Solution {
public:
int minSubArrayLen(int target, std::vector<int>& nums) {

	int back_idx = 0;
	int sum = 0;
	int min_length = nums.size() + 1;

	for (int i = 0; i < nums.size(); i++) {

		sum += nums[i];

		while (sum >= target) {
			min_length = (min_length < (i - back_idx + 1)) ? min_length : (i - back_idx + 1);
			sum -= nums[back_idx];
			back_idx++;
		}
	}

	return (min_length == nums.size() + 1) ? 0 : min_length;
}
};
