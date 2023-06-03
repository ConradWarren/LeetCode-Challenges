#include <vector>

class Solution {
public:
long long minOperations(std::vector<int>& nums1, std::vector<int>& nums2, int k) {
    
	if (k == 0) return (nums1 == nums2) ? 0 : -1;

	std::vector<int> diffrences(nums1.size());
	long long sum = 0;
	long long operations = 0;

	for (int i = 0; i < diffrences.size(); i++) {
		diffrences[i] = nums1[i] - nums2[i];
        if (diffrences[i] % k != 0) return -1;
        sum += diffrences[i];
        operations += std::abs(diffrences[i] / k);
	}

	return (sum != 0) ? -1 : operations/2;
}
};
