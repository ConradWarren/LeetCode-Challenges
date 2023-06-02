#include <vector>

class Solution {
public:
int Depth_First_Search(std::vector<std::vector<int>>& graph, int node, std::vector<int>& searched_nodes, std::vector<bool>& used_nodes) {

	if (used_nodes[node]) return 0;
	
	used_nodes[node] = true;

	if (searched_nodes[node] != -1) return searched_nodes[node];
	
	int longest_path = 1;

	for (int i = 0; i < graph[node].size(); i++) {
		longest_path += Depth_First_Search(graph, graph[node][i], searched_nodes, used_nodes);
	}

	searched_nodes[node] = longest_path;

	return longest_path;
}


int maximumDetonation(std::vector<std::vector<int>>& bombs) {

	std::vector<std::vector<int>> graph(bombs.size());
	std::vector<int> searched_nodes(bombs.size(), -1);
	std::vector<bool> used_nodes(bombs.size(), false);

	long long distance_x = 0;
	long long distance_y = 0;
	long long total_distance = 0;
	int result = 0;
	

	for (int i = 0; i < bombs.size(); i++) {

		for (int j = 0; j < bombs.size(); j++) {

			if (i == j) continue;
			
			distance_x = bombs[i][0] - bombs[j][0];
			distance_y = bombs[i][1] - bombs[j][1];

			total_distance = (distance_x * distance_x) + (distance_y * distance_y);

			if (total_distance <= ((long long)(bombs[i][2]) * (long long)(bombs[i][2])) ) graph[i].push_back(j);
			
		}
	}
	
	for (int i = 0; i < bombs.size(); i++) {
		
		if(searched_nodes[i] == -1) {
			used_nodes.clear();
			used_nodes.resize(bombs.size(), false);
			searched_nodes.clear();
			searched_nodes.resize(bombs.size(), -1);
			Depth_First_Search(graph, i, searched_nodes, used_nodes);
		}

		result = (result > searched_nodes[i]) ? result : searched_nodes[i];
	}
	return result;
}
};
