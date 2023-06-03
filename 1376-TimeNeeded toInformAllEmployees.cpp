#include <vector>

class Solution {
public:
int Depth_First_Search(std::vector<std::vector<int>>& graph,std::vector<int>& times, int node) {

	if (graph[node].empty()) return 0;
	
	int max_time = 0;
	int current_time = 0;
	for (int i = 0; i < graph[node].size(); i++) {
		current_time = times[node] + Depth_First_Search(graph, times, graph[node][i]);
		max_time = (max_time > current_time) ? max_time : current_time;
	}

	return max_time;
}

int numOfMinutes(int n, int headID, std::vector<int>& manager, std::vector<int>& informTime) {

	std::vector<std::vector<int>> graph(n);

	for (int i = 0; i < manager.size(); i++) {

		if (manager[i] == -1) continue;
		
		graph[manager[i]].push_back(i);
	}

	return Depth_First_Search(graph, informTime, headID);
}
};
