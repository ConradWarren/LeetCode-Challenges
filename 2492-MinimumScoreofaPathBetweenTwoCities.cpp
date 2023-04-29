#include <vector>

class Solution {
public:
void Depth_First_Search(int current_node, std::vector<std::vector<std::pair<int, int>>>& graph, int& min_path, std::vector<bool>& cache) {

	if (cache[current_node]) return;
	
	cache[current_node] = true;

	for (int i = 0; i < graph[current_node].size(); i++) {
		min_path = (graph[current_node][i].second < min_path) ? graph[current_node][i].second : min_path;
		Depth_First_Search(graph[current_node][i].first, graph, min_path, cache);
	}
}

int minScore(int n, std::vector<std::vector<int>>& roads) {
	
	std::vector<bool> cache(n + 1, false);
	std::vector<std::vector<std::pair<int, int>>> graph(n + 1);
	int min_path = INT_MAX;
	
	for (int i = 0; i < roads.size(); i++) {
		graph[roads[i][0]].push_back({ roads[i][1], roads[i][2] });
		graph[roads[i][1]].push_back({ roads[i][0], roads[i][2] });
	}
	
	Depth_First_Search(1, graph, min_path, cache);

	return min_path;
}
    
};
