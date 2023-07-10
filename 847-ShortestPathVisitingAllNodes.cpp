#include <vector>

class Solution {
public:
void Solve_Min_Path(std::vector<std::vector<int>>& graph,int node, int distance, int bit_mask,int& best, std::vector<std::vector<int>>& cache){

	bit_mask &= ~(1 << node);

	if (bit_mask == 0) {
		best = (best < distance) ? best : distance;
		return;
	}

	if (cache[bit_mask][node] <= distance) return;
	
	if (distance >= best) return;
	
	cache[bit_mask][node] = distance;

	for (int i = 0; i < graph[node].size(); i++) {
		Solve_Min_Path(graph, graph[node][i], distance + 1, bit_mask, best, cache);
	}
}

int shortestPathLength(std::vector<std::vector<int>>& graph) {
	
	int visted_node_bitmask = (1 << graph.size()) - 1;

	std::vector<std::vector<int>> cache(visted_node_bitmask + 1, std::vector<int>(graph.size(), INT_MAX));

	int result = INT_MAX;

	for (int i = 0; i < graph.size(); i++) {
		Solve_Min_Path(graph, i, 0, visted_node_bitmask, result, cache);
	}
	
	return result;
}
};
