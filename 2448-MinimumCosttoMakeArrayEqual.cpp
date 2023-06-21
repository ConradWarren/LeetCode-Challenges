#include <vector>

class Solution {
public:
long long minCost(std::vector<int>& nums, std::vector<int>& cost) {

	std::vector<std::pair<int, int>> sortable_nums(nums.size());
	std::vector<long long> increment_cost(nums.size(), 0);
	std::vector<long long> decrement_cost(nums.size(), 0);
	long long rolling_cost = 0LL;
	long long best_cost = LONG_MAX;

	for (int i = 0; i < sortable_nums.size(); i++) {
		sortable_nums[i].first = nums[i];
		sortable_nums[i].second = cost[i];
	}

	std::sort(sortable_nums.begin(), sortable_nums.end());
	
	for (int i = 1; i < sortable_nums.size(); i++) {
		rolling_cost += (long long)(sortable_nums[i - 1].second);
		increment_cost[i] = rolling_cost * (long long)(sortable_nums[i].first - sortable_nums[i - 1].first);
		increment_cost[i] += increment_cost[i - 1];
	}

	rolling_cost = 0LL;
	for (int i = sortable_nums.size() - 2; i >= 0; i--) {
		rolling_cost += (long long)(sortable_nums[i + 1].second);
		decrement_cost[i] = rolling_cost * (long long)(sortable_nums[i + 1].first - sortable_nums[i].first);
		decrement_cost[i] += decrement_cost[i + 1];
	}

	for (int i = 0; i < increment_cost.size(); i++) {
		rolling_cost = increment_cost[i] + decrement_cost[i];
		best_cost = (best_cost < rolling_cost) ? best_cost : rolling_cost;
	}

	return best_cost;
}

};
