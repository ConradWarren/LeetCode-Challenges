#include <vector>
#include <queue>

class Solution {
public:
bool Breath_First_Search(std::vector<std::vector<int>>& graph, int node, std::vector<int>& state) {

	int current_node = 0;
	std::queue<int> que_nodes;

	que_nodes.push(node);
	state[node] = 1;

	while (!que_nodes.empty()) {
		current_node = que_nodes.front();
		que_nodes.pop();
		for (int i = 0; i < graph[current_node].size(); i++) {
			if (state[graph[current_node][i]] == 0) {
				que_nodes.push(graph[current_node][i]);
				state[graph[current_node][i]] = (state[current_node] == 1) ? 2 : 1;
			}
			else if (state[graph[current_node][i]] == state[current_node]) return false;
		}
	}

	return true;
}

bool isBipartite(std::vector<std::vector<int>>& graph) {

	std::vector<int> state(graph.size(), 0);

	for (int i = 0; i < state.size(); i++) {

		if (state[i] == 0 && !Breath_First_Search(graph, i, state)) return false;
	
	}
	return true;
}
};
