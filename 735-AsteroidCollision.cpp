#include <vector>
#include <stack>

class Solution {
public:
std::vector<int> asteroidCollision(std::vector<int>& asteroids) {

	std::stack<int> nums;
	std::vector<int> result;
	int idx = 0;

	for (int i = 0; i < asteroids.size(); i++) {

		while (!nums.empty() && asteroids[i] < 0 && nums.top() > 0 && abs(asteroids[i]) > abs(nums.top())) {
			nums.pop();
		}

		if (nums.empty() || nums.top() < 0 || asteroids[i] > 0) {
			nums.push(asteroids[i]);
		}
		else if (-asteroids[i] == nums.top()) {
			nums.pop();
		}

	}

	result.resize(nums.size());
	idx = nums.size() - 1;

	while (!nums.empty()) {
		result[idx] = nums.top();
		idx--;
		nums.pop();
	}

	return result;
}
};
