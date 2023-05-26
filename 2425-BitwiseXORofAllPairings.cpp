#include <vector>

class Solution {
public:
int xorAllNums(std::vector<int>& nums1, std::vector<int>& nums2) {

	if (nums1.size() % 2 == 0 && nums2.size() % 2 == 0) return 0;
	
	if (nums1.size() % 2 == 1 && nums2.size() % 2 == 0) return xorAllNums(nums2, nums1);
	
	int result = 0;

	for (int i = 0; i < nums1.size(); i++) {
		result ^= nums1[i];
	}

	if (nums1.size() % 2 == 0) return result;
	
	for (int i = 0; i < nums2.size(); i++) {
		result ^= nums2[i];
	}

	return result;
}
};
