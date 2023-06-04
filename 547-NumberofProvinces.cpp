#include <vector>
#include <queue>

class Solution {
public:
void Breadth_First_Search(std::vector<std::vector<int>>& graph,std::vector<bool>& visted_nodes, int node){

	std::queue<int> node_queue;
	int current_node = 0;

	node_queue.push(node);
	visted_nodes[node] = true;

	while (!node_queue.empty()) {

		current_node = node_queue.front();
		node_queue.pop();
		
		for (int i = 0; i < graph[current_node].size(); i++) {
			if (!visted_nodes[graph[current_node][i]]) {
				visted_nodes[graph[current_node][i]] = true;
				node_queue.push(graph[current_node][i]);
			}
		}
	}
}
int findCircleNum(std::vector<std::vector<int>>& isConnected) {

	std::vector<std::vector<int>> graph(isConnected.size());
	std::vector<bool> visted_nodes(isConnected.size(), false);
	int unconnected_groups = 0;

	for (int i = 0; i < isConnected.size(); i++) {
		for (int j = 0; j < isConnected.size(); j++) {

			if (i != j && isConnected[i][j]) graph[i].push_back(j);
		}
	}

	for (int i = 0; i < visted_nodes.size(); i++) {

		if (visted_nodes[i]) continue;

		unconnected_groups++;
		Breadth_First_Search(graph, visted_nodes, i);
	}

	return unconnected_groups;
}
};
