#include <vector>
#include <queue>

class Solution {
public:
int minimumTime(int n, std::vector<std::vector<int>>& relations, std::vector<int>& time) {

	std::vector<std::vector<int>> grid(n + 1);
	std::vector<int> edge_counts(n + 1, 0);
	std::vector<int> calculated_time(n+1, 0);
	std::queue<int> node_queue;

	for (int i = 0; i < relations.size(); i++) {
		grid[relations[i][0]].push_back(relations[i][1]);
		edge_counts[relations[i][1]]++;
	}

	for (int i = 1; i < edge_counts.size(); i++) {
		if (edge_counts[i] == 0) node_queue.push(i);
	}

	int best_time = 0;
	while (!node_queue.empty()) {

		calculated_time[node_queue.front()] += time[node_queue.front() - 1];
		best_time = max(best_time, calculated_time[node_queue.front()]);

		for (int i = 0; i < grid[node_queue.front()].size(); i++) {

			calculated_time[grid[node_queue.front()][i]] = max(calculated_time[grid[node_queue.front()][i]], calculated_time[node_queue.front()]);

			edge_counts[grid[node_queue.front()][i]]--;

			if (edge_counts[grid[node_queue.front()][i]] == 0) node_queue.push(grid[node_queue.front()][i]);
		}
		node_queue.pop();
	}
	return best_time;
}
};
