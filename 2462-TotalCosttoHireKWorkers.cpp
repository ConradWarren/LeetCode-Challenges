#include <priority_queue>
#include <vector>

class Solution {
public:
long long totalCost(std::vector<int>& costs, int k, int candidates) {

	std::priority_queue < std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater <std::pair<int, int>>> min_heap;
	std::vector<bool> used_idx(costs.size(), false);
	int left_bound = candidates-1;
	int right_bound = costs.size() - candidates;
	long long sum = 0;
	bool overlap = false;

	for (int i = 0; i <= left_bound && i < costs.size(); i++) {
		used_idx[i] = true;
		min_heap.push({ costs[i], i });
	}

	for (int i = right_bound; i < costs.size(); i++) {

		if (used_idx[i]) overlap = true;

		else {
			used_idx[i] = true;
			min_heap.push({ costs[i], i });
		}
	}

	for (int i = 0; i < k; i++) {

		sum += min_heap.top().first;

		if (overlap) min_heap.pop();
		
		else if (min_heap.top().second <= left_bound) {
			left_bound++;
			min_heap.pop();

			if (used_idx[left_bound]) overlap = true;
			else {
				min_heap.push({ costs[left_bound], left_bound });
				used_idx[left_bound] = true;
			}
		}
		else {
			right_bound--;
			min_heap.pop();

			if (used_idx[right_bound]) overlap = true;
			else {
				min_heap.push({ costs[right_bound], right_bound });
				used_idx[right_bound] = true;
			}
		}
	}
	return sum;;
}
};
