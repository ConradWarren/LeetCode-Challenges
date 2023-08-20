#include <vector>
#include <queue>

class Solution {
public:
std::vector<int> sortItems(int n, int m, std::vector<int>& group, std::vector<std::vector<int>>& beforeItems) {

	int idx = m;
	int current_node = 0;
	int current_group = 0;
	std::vector<int> result(n);
	std::vector<int> group_result;
	std::vector<std::vector<int>> group_edges;
	std::vector<std::vector<int>> edges(n);
	std::vector<std::queue<int>> grouped_queues;
	std::vector<int> n_degree(n);
	std::vector<int> group_degree;
	std::queue<int> node_queue;

	for (int i = 0; i < group.size(); i++) {
		if (group[i] == -1) {
			group[i] = idx;
			idx++;
		}
	}
	
	group_result.resize(idx);
	group_edges.resize(idx);
	group_degree.resize(idx, 0);
	grouped_queues.resize(idx);

	idx = 0;

	for (int i = 0; i < beforeItems.size(); i++) {
		for (int j = 0; j < beforeItems[i].size(); j++) {
			if (group[beforeItems[i][j]] != group[i]) {
				group_degree[group[i]]++;
				group_edges[group[beforeItems[i][j]]].push_back(group[i]);
			}
			else {
				n_degree[i]++;
				edges[beforeItems[i][j]].push_back(i);
			}
		}
	}

	for (int i = 0; i < group_degree.size(); i++) {
		if (group_degree[i] == 0) {
			node_queue.push(i);
		}
	}
	for (int i = 0; i < n_degree.size(); i++) {
		if (n_degree[i] == 0) {
			grouped_queues[group[i]].push(i);
		}
	}
	
	while (!node_queue.empty()) {

		current_node = node_queue.front();
		group_result[idx] = current_node;
		idx++;
		node_queue.pop();

		for (int i = 0; i < group_edges[current_node].size(); i++) {
			group_degree[group_edges[current_node][i]]--;
			if (group_degree[group_edges[current_node][i]] == 0) {
				node_queue.push(group_edges[current_node][i]);
			}
		}
	}

	idx = 0;

	for (int i = 0; i < group_result.size(); i++) {

		current_group = group_result[i];

		while (!grouped_queues[current_group].empty()){

			current_node = grouped_queues[current_group].front();
			result[idx] = current_node;
			idx++;
			grouped_queues[current_group].pop();

			for (int j = 0; j < edges[current_node].size(); j++) {

				n_degree[edges[current_node][j]]--;
				if (n_degree[edges[current_node][j]] == 0) {
					grouped_queues[current_group].push(edges[current_node][j]);
				}
			}
		}
	}
	if (idx < result.size()) {
		return {};
	}

	return result;
}

};
