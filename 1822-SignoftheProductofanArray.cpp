class Solution {
public:
int arraySign(std::vector<int>& nums) {

	bool negative_count = false;
	for (int i = 0; i < nums.size(); i++) {
		if (nums[i] < 0) {
			negative_count ^= true;
		} 
		else if (nums[i] == 0) {
			return 0;
		} 
	}

	return (negative_count) ? -1 : 1;
}
};
