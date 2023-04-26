class Solution {
public:
int Depth_First_Search(std::vector<std::vector<int>>& graph, std::vector<bool>& visted_nodes, int node) {

	if (visted_nodes[node]) return 0;
	
	visted_nodes[node] = true;

	int total_nodes = 1;

	for (int i = 0; i < graph[node].size(); i++) {
		total_nodes += Depth_First_Search(graph, visted_nodes, graph[node][i]);
	}

	return total_nodes;
}

int reachableNodes(int n, std::vector<std::vector<int>>& edges, std::vector<int>& restricted) {

	std::vector<bool> visted_nodes(n, false);
	std::vector<std::vector<int>> graph(n);

	for (int i = 0; i < edges.size(); i++) {
		graph[edges[i][0]].push_back(edges[i][1]);
		graph[edges[i][1]].push_back(edges[i][0]);
	}

	for (int i = 0; i < restricted.size(); i++) {
		visted_nodes[restricted[i]] = true;
	}

	return Depth_First_Search(graph, visted_nodes, 0);
}

};
