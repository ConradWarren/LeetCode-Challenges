class Solution {
public:
void Find_all_Subsets(std::vector<int>& nums, int idx, int last_xor_total, int& output) {

	int current;
	for (int i = idx; i < nums.size(); i++) {
		current = last_xor_total ^ nums[i];
		output += current;
		Find_all_Subsets(nums, i + 1, current, output);
	}
}



int subsetXORSum(std::vector<int>& nums) {

	int result = 0;
	Find_all_Subsets(nums, 0, 0, result);

	return result;
}
};
