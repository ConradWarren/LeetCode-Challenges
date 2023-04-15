#include <stack>

class Solution {
public:
bool find132pattern(std::vector<int>& nums) {
	
	std::stack<std::pair<int, int>> stack;

	int lowest = nums[0];

	for (int i = 0; i < nums.size(); i++) {

		while (!stack.empty() && nums[i] >= stack.top().second) {
			stack.pop();
		}
		if (!stack.empty() && nums[i] > stack.top().first && nums[i] < stack.top().second) {
			return true;
		}

		stack.push({lowest, nums[i]});

		if (nums[i] < lowest) {
			lowest = nums[i];
		}

	}

	return false;
}

};
