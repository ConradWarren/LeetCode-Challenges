#include <vector>

class Solution {
public:
int maxScore(std::vector<int>& nums) {

	long long sum = 0;
	int score = 0;

	std::sort(nums.rbegin(), nums.rend());

	for (int i = 0; i < nums.size(); i++) {

		sum += nums[i];

		if (sum > 0) score++;
		
		else if (sum < 0) break;
	}
	return score;
}
};
