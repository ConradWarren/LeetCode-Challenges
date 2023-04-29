#include <vector>

class Solution {
public:
int Union_Find(int node, std::vector<int>& parent_nodes) {

	if (parent_nodes[node] == node) {
		return node;
	}
	parent_nodes[node] = Union_Find(parent_nodes[node], parent_nodes);
	return parent_nodes[node];
}

void Union(int node_1, int node_2, std::vector<int>& parent_nodes, std::vector<int>& group_sizes) {

	int node_1_group = Union_Find(node_1, parent_nodes);
	int node_2_group = Union_Find(node_2, parent_nodes);

	if (node_1_group != node_2_group) {

		if (group_sizes[node_1_group] < group_sizes[node_2_group]) {
			parent_nodes[node_1_group] = node_2_group;
			group_sizes[node_2_group] += group_sizes[node_1_group];
		}
		else {
			parent_nodes[node_2_group] = node_1_group;
			group_sizes[node_1_group] += group_sizes[node_2_group];
		}
	}

}


std::vector<bool> distanceLimitedPathsExist(int n, std::vector<std::vector<int>>& edgeList, std::vector<std::vector<int>>& queries) {

	std::vector<int> parent_nodes(n);
	std::vector<int> group_sizes(n, 1);
	std::vector<bool> result(queries.size(), false);

	for (int i = 0; i < parent_nodes.size(); i++) {
		parent_nodes[i] = i;
	}

	for (int i = 0; i < queries.size(); i++) {
		queries[i].push_back(i);
	}

	std::sort(queries.begin(), queries.end(), [&](auto const& a, auto const& b) {return a[2] < b[2]; });
	std::sort(edgeList.begin(), edgeList.end(), [&](auto const& a, auto const& b) {return a[2] < b[2]; });

	int idx = 0;
	for (int i = 0; i < queries.size(); i++) {

		while (idx < edgeList.size() && edgeList[idx][2] < queries[i][2]) {
			Union(edgeList[idx][0], edgeList[idx][1], parent_nodes, group_sizes);
			idx++;
		}

		if (Union_Find(queries[i][0], parent_nodes) == Union_Find(queries[i][1], parent_nodes)) {
			result[queries[i][3]] = true;
		}

	}

	return result;
}
};
