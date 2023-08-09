#include <vector>
#include <priority_queue>

class Solution {
public:
std::vector<int> minInterval(std::vector<std::vector<int>>& intervals, std::vector<int>& queries) {

	int idx = 0;
	std::vector<int> result(queries.size(), -1);
	std::vector<std::pair<int, int>> sortable_queries(queries.size());
	std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> min_heap;

	for (int i = 0; i < queries.size(); i++) {
		sortable_queries[i].first = queries[i];
		sortable_queries[i].second = i;
	}
	std::sort(sortable_queries.begin(), sortable_queries.end());
	std::sort(intervals.begin(), intervals.end());

	for (int i = 0; i < sortable_queries.size(); i++) {

		while (idx < intervals.size() && intervals[idx][0] <= sortable_queries[i].first) {
			min_heap.push({ intervals[idx][1] - intervals[idx][0] + 1 ,intervals[idx][1] });
			idx++;
		}

		while (!min_heap.empty() && min_heap.top().second < sortable_queries[i].first) {
			min_heap.pop();
		}

		if (!min_heap.empty()) {
			result[sortable_queries[i].second] = min_heap.top().first;
		}
	}
	
	return result;
}
};
