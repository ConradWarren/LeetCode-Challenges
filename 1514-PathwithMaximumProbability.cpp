#include <vector>
#include <queue>

class Solution {
public:
double maxProbability(int n, std::vector<std::vector<int>>& edges, std::vector<double>& succProb, int start, int end) {

	std::vector<std::vector<std::pair<int, double>>> graph(n);
	std::vector<double> cache(n, 0);
	std::queue<int> node_que;


	for (int i = 0; i < edges.size(); i++) {
		graph[edges[i][0]].push_back({edges[i][1], succProb[i]});
		graph[edges[i][1]].push_back({edges[i][0], succProb[i]});
	}

	node_que.push(start);
	cache[start] = 1.0;

	while (!node_que.empty()) {

		int node = node_que.front();

		node_que.pop();

		for (int i = 0; i < graph[node].size(); i++) {

			if (graph[node][i].second * cache[node] > cache[graph[node][i].first]) {

				cache[graph[node][i].first] = graph[node][i].second * cache[node];

				node_que.push(graph[node][i].first);
			}

		}
	
	}

	return cache[end];
}
};
