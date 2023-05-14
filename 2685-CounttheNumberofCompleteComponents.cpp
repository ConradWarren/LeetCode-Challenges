#include <vector>
#include <unordered_map>

class Solution {
public:
	void Breadth_First_Search(std::vector<std::vector<int>> graph, std::vector<int>& groups, int node, int group) {

		std::queue<int> q_nodes;

		q_nodes.push(node);

		while (!q_nodes.empty()) {

			int current_node = q_nodes.front();
			groups[current_node] = group;
			q_nodes.pop();

			for (int i = 0; i < graph[current_node].size(); i++) {

				if (groups[graph[current_node][i]]) continue;

				q_nodes.push(graph[current_node][i]);
			}
		}
	}

	int countCompleteComponents(int n, std::vector<std::vector<int>>& edges) {

		std::vector<std::vector<int>> graph(n);
		std::vector<int> groups(n, 0);
		std::vector<int> edge_counts(n, 0);
		std::vector<int> current_group;
		std::unordered_map<int, std::vector<int>> grouped_nodes;
		int group_number = 0;
		int result = 0;

		for (int i = 0; i < edges.size(); i++) {
			graph[edges[i][0]].push_back(edges[i][1]);
			graph[edges[i][1]].push_back(edges[i][0]);
			edge_counts[edges[i][0]]++;
			edge_counts[edges[i][1]]++;
		}

		for (int i = 0; i < groups.size(); i++) {

			if (groups[i]) {
				grouped_nodes[groups[i]].push_back(i);
			}
			else {
				group_number++;
				Breadth_First_Search(graph, groups, i, group_number);
				grouped_nodes[groups[i]].push_back(i);
			}

		}
		for (auto& x : grouped_nodes) {
			current_group = x.second;
			bool valid_flag = true;

			for (int i = 0; i < current_group.size(); i++) {
				if (edge_counts[current_group[i]] != current_group.size() - 1) {
					valid_flag = false;
					break;
				}
			}

			if (valid_flag) result++;
		}

		return result;
	}
};
