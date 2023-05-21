#include <vector>

class Solution {
public:
long long findTheArrayConcVal(std::vector<int>& nums) {

	long long sum = 0;
	int low = 0;
	int high = nums.size() - 1;

	while (low < high) {
		sum += std::stoi(std::to_string(nums[low]) + std::to_string(nums[high]));
		low++;
		high--;
	}

	if (low == high) sum += nums[low];
	
	return sum;
}
};
