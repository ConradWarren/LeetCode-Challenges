#include <vector>

class Solution {
public:

int Get_Group(std::vector<int>& groups, int x) {

	if (groups[x] == x) {
		return x;
	}
	groups[x] = Get_Group(groups, groups[x]);
	return groups[x];
}

int Union(std::vector<int>& groups, std::vector<int>& n_degree, int x, int y) {

	int group_x = Get_Group(groups, x);
	int group_y = Get_Group(groups, y);

	if (group_x == group_y) {
		return n_degree[group_x];
	}

	if (n_degree[group_x] >= n_degree[group_y]) {
		n_degree[group_x] += n_degree[group_y];
		groups[group_y] = group_x;
		return n_degree[group_x];
	}
	else {
		n_degree[group_y] += n_degree[group_x];
		groups[group_x] = group_y;
		return n_degree[group_y];
	}
}

int Get_Score(std::vector<std::vector<int>>& edges, int n, int removed_edge, int required_edge) {

	std::vector<int> groups(n);
	std::vector<int> n_degree(n, 1);
	int connected_nodes = 0;
	int current = 0;
	int score = 0;
	int group_1 = 0;
	int group_2 = 0;

	for (int i = 0; i < n; i++) {
		groups[i] = i;
	}

	if (required_edge != -1) {
		group_1 = Get_Group(groups, edges[required_edge][0]);
		group_2 = Get_Group(groups, edges[required_edge][1]);

		score += edges[required_edge][2];

		current = Union(groups, n_degree, edges[required_edge][0], edges[required_edge][1]);
		connected_nodes = (connected_nodes > current) ? connected_nodes : current;
	}

	for (int i = 0; i < edges.size(); i++) {

		group_1 = Get_Group(groups, edges[i][0]);
		group_2 = Get_Group(groups, edges[i][1]);

		if (group_1 == group_2 || i == removed_edge) {
			continue;
		}

		score += edges[i][2];

		current = Union(groups, n_degree, edges[i][0], edges[i][1]);
		connected_nodes = (connected_nodes > current) ? connected_nodes : current;
	}

	return (connected_nodes == n) ? score : INT_MAX;
}

std::vector<std::vector<int>> findCriticalAndPseudoCriticalEdges(int n, std::vector<std::vector<int>>& edges) {

	int mst_score = 0;
	int current_score = 0;
	bool hit_flag = false;

	std::vector<bool> used_edges(edges.size(), false);
	std::vector<bool> critical(edges.size(), false);
	std::vector<std::vector<int>> result(2);

	for (int i = 0; i < edges.size(); i++) {
		edges[i].push_back(i);
	}

	std::sort(edges.begin(), edges.end(), [](const std::vector<int>& a, const std::vector<int>& b) {return a[2] < b[2]; });

	mst_score = Get_Score(edges, n, -1, -1);

	for (int i = 0; i < edges.size(); i++) {

		current_score = Get_Score(edges, n, i, -1);

		if (current_score > mst_score) {
			critical[i] = true;
			result[0].push_back(edges[i][3]);
		}
	}

	for (int i = 0; i < edges.size(); i++) {
		
		if (critical[i]) continue;
		
		current_score = Get_Score(edges, n, i, i);
		if (current_score == mst_score) {
			result[1].push_back(edges[i][3]);
		}
	}

	return result;
}
};
