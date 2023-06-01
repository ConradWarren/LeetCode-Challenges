#include <vector>

class Solution {
public:
int xorBeauty(std::vector<int>& nums) {

	int bitmask = 0;
	
	for (int i = 0; i < nums.size(); i++) {
		bitmask ^= nums[i];
	}

	return bitmask;
}
};
