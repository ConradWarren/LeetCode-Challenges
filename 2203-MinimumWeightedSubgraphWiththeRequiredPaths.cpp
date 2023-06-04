#include <vector>
#include <queue>

class Solution {
public:
void Djiksitas(std::vector<std::vector<std::pair<int, int>>>& graph, std::vector<long long>& distances, int node) {

	std::queue<int> node_queue;
	int current_node = 0;
	
	distances[node] = 0;
	node_queue.push(node);

	while (!node_queue.empty()) {

		current_node = node_queue.front();
		node_queue.pop();

		for (int i = 0; i < graph[current_node].size(); i++) {
			if (distances[graph[current_node][i].second] > graph[current_node][i].first + distances[current_node]) {
				distances[graph[current_node][i].second] = graph[current_node][i].first + distances[current_node];
				node_queue.push(graph[current_node][i].second);
			}
		}
	}
}

long long minimumWeight(int n, std::vector<std::vector<int>>& edges, int src1, int src2, int dest) {

	std::vector<std::vector<std::pair<int, int>>> graph(n);
	std::vector<std::vector<std::pair<int, int>>> reverse_graph(n);
	std::vector<long long> src1_distances(n, LONG_MAX);
	std::vector<long long> src2_distances(n, LONG_MAX);
	std::vector<long long> reverse_distances(n, LONG_MAX);
	long long min_distance = LONG_MAX;

	for (int i = 0; i < edges.size(); i++) {
		graph[edges[i][0]].push_back({edges[i][2], edges[i][1] });
		reverse_graph[edges[i][1]].push_back({edges[i][2], edges[i][0] });
	}

	for (int i = 0; i < n; i++) {
		std::sort(graph[i].begin(), graph[i].end());
		std::sort(reverse_graph[i].begin(), reverse_graph[i].end());
	}

	Djiksitas(graph, src1_distances, src1);
	Djiksitas(graph, src2_distances, src2);
	Djiksitas(reverse_graph, reverse_distances, dest);

	for (int i = 0; i < reverse_distances.size(); i++) {

		if (reverse_distances[i] == LONG_MAX || src1_distances[i] == LONG_MAX || src2_distances[i] == LONG_MAX) continue;
		
		min_distance = (min_distance < reverse_distances[i] + src1_distances[i] + src2_distances[i]) ? min_distance : reverse_distances[i] + src1_distances[i] + src2_distances[i];
	}
	return (min_distance == LONG_MAX) ? -1 : min_distance;
}
};
