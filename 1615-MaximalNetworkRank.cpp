#include <vector>

class Solution {
public:
int maximalNetworkRank(int n, std::vector<std::vector<int>>& roads) {

	std::vector<std::vector<bool>> graph(n, std::vector<bool>(n, false));
	std::vector<int> n_degree(n, 0);
	int result = 0;
	int current = 0;

	for (int i = 0; i < roads.size(); i++) {
		n_degree[roads[i][0]]++;
		n_degree[roads[i][1]]++;
		graph[roads[i][0]][roads[i][1]] = true;
		graph[roads[i][1]][roads[i][0]] = true;
	}
	
	for (int i = 0; i < n; i++) {
		for (int j = i+1; j < n; j++) {
			current = (graph[i][j]) ? n_degree[i] + n_degree[j] - 1 : n_degree[i] + n_degree[j];
			result = (result > current) ? result : current;
		}
	}

	return result;
}
};
