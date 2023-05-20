#include <string>
#include <vector>
#include <queue>
#include <unordered_map>

class Solution {
public:
double Breadth_First_Search(std::string& node, std::string& target_node, std::unordered_map<std::string, std::vector<std::pair<std::string, double>>>& graph) {

	std::queue<std::pair<std::string, double>> node_que;
	std::unordered_map<std::string, bool> used_nodes;

	node_que.push({ node, 1.0 });

	while (!node_que.empty()) {

		std::string current_node = node_que.front().first;
		double multiplyer = node_que.front().second;
		node_que.pop();
		used_nodes[current_node] = true;

		for (int i = 0; i < graph[current_node].size(); i++) {

			if (used_nodes[graph[current_node][i].first]) continue;
			
			if (graph[current_node][i].first == target_node) return multiplyer * graph[current_node][i].second;
			
			node_que.push({ graph[current_node][i].first,(multiplyer * graph[current_node][i].second) });
		}
	}
	return -1.0;
}


std::vector<double> calcEquation(std::vector<std::vector<std::string>>& equations, std::vector<double>& values, std::vector<std::vector<std::string>>& queries) {

	std::unordered_map<std::string, std::vector<std::pair<std::string, double>>> graph;
	std::vector<double> result(queries.size());

	for (int i = 0; i < equations.size(); i++) {
		graph[equations[i][0]].push_back({ equations[i][1], values[i] });
		graph[equations[i][1]].push_back({ equations[i][0], (1/values[i])});
	}

	for (int i = 0; i < queries.size(); i++) {

		if (graph.find(queries[i][0]) == graph.end() || graph.find(queries[i][1]) == graph.end()) result[i] = -1.0;
		
		else if (queries[i][0] == queries[i][1]) result[i] = 1.0;
		
		else result[i] = Breadth_First_Search(queries[i][0], queries[i][1], graph);
	}
	return result;
}
};
