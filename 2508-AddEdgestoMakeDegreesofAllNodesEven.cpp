#include <vector>
#include <unordered_map>
#include <unordered_set>

class Solution {
public:

bool Connect_Four_Nodes(std::vector<int>& nodes,int idx, std::vector<std::unordered_set<int>>& edges, std::unordered_map<int, bool>& connected_nodes) {

	if (idx >= 4) return true;
	
	if (connected_nodes[idx]) return Connect_Four_Nodes(nodes, idx + 1, edges, connected_nodes);
	
	connected_nodes[idx] = true;
	for (int i = idx + 1; i < 4; i++) {

		if (edges[idx].find(nodes[i]) == edges[idx].end()) {

			connected_nodes[i] = true;

			if (Connect_Four_Nodes(nodes, idx+1, edges, connected_nodes)) return true;
			
			connected_nodes[i] = false;
		}
	}
	connected_nodes[idx] = false;
	return false;
}


bool isPossible(int n, std::vector<std::vector<int>>& edges) {

	std::vector<std::vector<int>> graph(n + 1);
	std::vector<int> n_degree(n + 1, 0);
	std::vector<int> odd_edge_nodes;
	std::vector<std::unordered_set<int>> needed_edges(4);
	std::unordered_map<int, bool> connected_edges;

	for (int i = 0; i < edges.size(); i++) {
		graph[edges[i][0]].push_back(edges[i][1]);
		graph[edges[i][1]].push_back(edges[i][0]);
		n_degree[edges[i][0]]++;
		n_degree[edges[i][1]]++;
	}

	for (int i = 1; i <= n; i++) {
		if (n_degree[i] % 2 == 1) odd_edge_nodes.push_back(i);
	}

	if (odd_edge_nodes.empty()) return true;
	
	if (odd_edge_nodes.size() > 4 || odd_edge_nodes.size() % 2 == 1) {
		return false;
	}

	if (odd_edge_nodes.size() == 2) {
		int node_1 = odd_edge_nodes[0];
		int node_2 = odd_edge_nodes[1];
		std::unordered_map<int, bool> used_nodes;

		for (int i = 0; i < graph[node_1].size(); i++) {
			used_nodes[graph[node_1][i]] = true;
		}

		if (!used_nodes[node_2]) return true;
		
		for (int i = 0; i < graph[node_2].size(); i++) {
			used_nodes[graph[node_2][i]] = true;
		}

		for (int i = 1; i <= n; i++) {
			if (n_degree[i] % 2 == 0 && !used_nodes[i]) return true;
		}
		return false;
	}

	for (int i = 0; i < odd_edge_nodes.size(); i++) {
		for (int j = 0; j < graph[odd_edge_nodes[i]].size(); j++) {
			needed_edges[i].insert(graph[odd_edge_nodes[i]][j]);
		}
	}
	
	return Connect_Four_Nodes(odd_edge_nodes, 0, needed_edges, connected_edges);
}
};
