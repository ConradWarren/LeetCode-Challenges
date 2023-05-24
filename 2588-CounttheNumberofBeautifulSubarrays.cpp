#include <vector>

class Solution {
public:
long long beautifulSubarrays(std::vector<int>& nums) {

	std::unordered_map<int, int> xor_occurances;
	int current_num = 0;
	long long result = 0;

	xor_occurances[0] = 1;

	for (int i = 0; i < nums.size(); i++) {

		current_num ^= nums[i];

		result += xor_occurances[current_num];

		xor_occurances[current_num]++;
	}

	return result;
}
};
