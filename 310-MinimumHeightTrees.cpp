#include <vector>
#include <queue> 

class Solution {
public:
std::vector<int> findMinHeightTrees(int n, std::vector<std::vector<int>>& edges) {

	std::vector<std::vector<int>> graph(n);

	std::vector<int> edge_counts(n, 0);

	std::vector<bool> removed_nodes(n, false);

	std::vector<int> result;

	std::queue<int> nodes_to_remove;

	for (int i = 0; i < edges.size(); i++) {
		graph[edges[i][0]].push_back(edges[i][1]);
		graph[edges[i][1]].push_back(edges[i][0]);

		edge_counts[edges[i][0]]++;
		edge_counts[edges[i][1]]++;
	}
	
	int unreduced_nodes = -1;
	int temp_unreduced_nodes = n;

	while (unreduced_nodes != temp_unreduced_nodes) {

		unreduced_nodes = temp_unreduced_nodes;

		for (int i = 0; i < n; i++) {
			if (edge_counts[i] == 1) {
				nodes_to_remove.push(i);
				temp_unreduced_nodes--;
			} 
		}

		if (temp_unreduced_nodes == 0) {
			break;
		}

		while (!nodes_to_remove.empty()) {
			removed_nodes[nodes_to_remove.front()] = true;

			for (int i = 0; i < graph[nodes_to_remove.front()].size(); i++) {
				if (!removed_nodes[graph[nodes_to_remove.front()][i]]) {
					edge_counts[graph[nodes_to_remove.front()][i]]--;
				}
			}
			edge_counts[nodes_to_remove.front()]--;
			nodes_to_remove.pop();
		}
		
	}
	
	for (int i = 0; i < n; i++) {
		if (!removed_nodes[i]) {
			result.push_back(i);
		}
	}

	return result;
}
};
