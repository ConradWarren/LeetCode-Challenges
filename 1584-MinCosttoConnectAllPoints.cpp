#include <vector>
#include <priority_queue>

class Solution {
public:
int minCostConnectPoints(std::vector<std::vector<int>>& points) {
	
	std::vector<std::vector<int>> graph(points.size(), std::vector<int>(points.size(), 0));
	std::vector<bool> visted_nodes(points.size(), false);
	std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> min_heap;
	
	int node = 0;
	int result = 0;

	for (int i = 0; i < points.size(); i++) {
		for (int j = i+1; j < points.size(); j++) {
			graph[i][j] = std::abs(points[i][0] - points[j][0]) + std::abs(points[i][1] - points[j][1]);
			graph[j][i] = std::abs(points[i][0] - points[j][0]) + std::abs(points[i][1] - points[j][1]);
		}
	}

	for (int i = 0; i < graph[0].size(); i++) {
		min_heap.push({ graph[0][i], i });
	}

	visted_nodes[0] = true;

	while (!min_heap.empty()) {

		node = min_heap.top().second;
		result += min_heap.top().first;
		min_heap.pop();
		visted_nodes[node] = true;

		for (int i = 0; i < graph[node].size(); i++) {

			if (visted_nodes[i]) {
				continue;
			}
			min_heap.push({ graph[node][i], i });
		}

		while (!min_heap.empty() && visted_nodes[min_heap.top().second]) {
			min_heap.pop();
		}
	}

	return result;
}
};
