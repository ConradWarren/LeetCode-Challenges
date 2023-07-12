#include <vector>

class Solution {
public:
bool Depth_First_Search(std::vector<std::vector<int>>& graph, std::vector<bool>& visted_nodes, int node, std::vector<bool>& cache, std::vector<bool>& has_cache) {

	if (has_cache[node]) return cache[node];
	
	if (graph[node].size() == 0) {
		has_cache[node] = true;
		cache[node] = true;
		return true;
	}

	if (visted_nodes[node]) {
		has_cache[node] = true;
		cache[node] = false;
		return false;
	}

	visted_nodes[node] = true;

	for (int i = 0; i < graph[node].size(); i++) {

		if (!Depth_First_Search(graph, visted_nodes, graph[node][i], cache, has_cache)) {
			has_cache[node] = true;
			cache[node] = false;
			visted_nodes[node] = false;
			return false;
		}
	}
	has_cache[node] = true;
	cache[node] = true;
	visted_nodes[node] = false;
	return true;
}

std::vector<int> eventualSafeNodes(std::vector<std::vector<int>>& graph) {

	std::vector<bool> visted_nodes(graph.size(), false);
	std::vector<int> result;
	std::vector<bool> cache(graph.size());
	std::vector<bool> has_cache(graph.size(), false);
	
	for (int i = 0; i < graph.size(); i++) {
		if (Depth_First_Search(graph, visted_nodes, i, cache, has_cache)) {
			result.push_back(i);
		}
	}

	return result;
}
};
