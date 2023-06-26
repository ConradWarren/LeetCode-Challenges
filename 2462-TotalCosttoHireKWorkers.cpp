#include <priority_queue>
#include <vector>

class Solution {
public:
long long totalCost(std::vector<int>& costs, int k, int candidates) {

	std::priority_queue <int, std::vector<int>,  std::greater<int>> heap_left;
	std::priority_queue <int, std::vector<int>,  std::greater<int>> heap_right;
	
	int idx_left = candidates - 1;
	int idx_right = costs.size() - candidates;
	long long result = 0;
	
	for (int i = 0; i <= idx_left && i < idx_right; i++) {
		heap_left.push(costs[i]);
	}

	for (int i = costs.size() - 1; i >= idx_right; i--) {
		heap_right.push(costs[i]);
	}

	while (k) {
		if (heap_left.empty()) {
			result += heap_right.top();
			heap_right.pop();
		}
		else if (heap_right.empty()) {
			result += heap_left.top();
			heap_left.pop();
		}
		else if (heap_left.top() <= heap_right.top()) {
			result += heap_left.top();
			heap_left.pop();
			idx_left++;
			if (idx_left < idx_right) heap_left.push(costs[idx_left]);
		}
		else {
			result += heap_right.top();
			heap_right.pop();
			idx_right--;
			if (idx_left < idx_right) heap_right.push(costs[idx_right]);
		}
		k--;
	}
	return result;
}
};
