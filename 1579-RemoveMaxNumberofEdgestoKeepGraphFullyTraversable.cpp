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

void Union(int node_1,int node_2, std::vector<int>& parent_nodes) {
	int node_1_group = Union_Find(node_1, parent_nodes);
	int node_2_group = Union_Find(node_2, parent_nodes);
	parent_nodes[node_1_group] = node_2_group;
}



int maxNumEdgesToRemove(int n, std::vector<std::vector<int>>& edges) {

	std::vector<int> parents_a(n+1);
	std::vector<int> parents_b(n+1);
	

	for (int i = 1; i <= n; i++) {
		parents_a[i] = i;
		parents_b[i] = i;
	}

	std::sort(edges.rbegin(), edges.rend());

	int used_edges = 0;
	int idx = 0;

	while (idx < edges.size() && edges[idx][0] == 3) {
		
		if (Union_Find(edges[idx][1], parents_a) != Union_Find(edges[idx][2], parents_a)) {
			used_edges++;
			Union(edges[idx][1], edges[idx][2], parents_a);
		}
		idx++;
	}

	parents_b = parents_a;

	while (idx < edges.size() && edges[idx][0] == 2) {

		if (Union_Find(edges[idx][1], parents_b) != Union_Find(edges[idx][2], parents_b)) {
			used_edges++;
			Union(edges[idx][1], edges[idx][2], parents_b);
		}
		idx++;
	}

	while (idx < edges.size() && edges[idx][0] == 1) {
		if (Union_Find(edges[idx][1], parents_a) != Union_Find(edges[idx][2], parents_a)) {
			used_edges++;
			Union(edges[idx][1], edges[idx][2], parents_a);
		}
		idx++;
	}
	
	for (int i = 2; i <= n; i++) {
		if (Union_Find(i, parents_a) != Union_Find(1, parents_a)) return -1;
		
		if (Union_Find(i, parents_b) != Union_Find(1, parents_b)) return -1;
		
	}
	return edges.size() - used_edges;
}
};
