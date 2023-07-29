#include <vector>

class TreeAncestor {

public:
	TreeAncestor(int n, std::vector<int>& parent) {
		idx = 0; 
		while ((1 << idx) <= n) {
			idx++;
		}
		
		node_map.resize(n, std::vector<int>(idx, -1));
		
		for (int i = 1; i < n; i++) {
			node_map[i][0] = parent[i];
		}
		
		for (int j = 1; j < idx; j++) {
			for (int i = 0; i < n; i++) {
				if (node_map[i][j - 1] == -1) {
					node_map[i][j] = -1;
				}
				else {
					node_map[i][j] = node_map[node_map[i][j - 1]][j - 1];
				}
			}
		}
	}

	int getKthAncestor(int node, int k) {

		for (int i = 0; i < idx; i++) {
			if (k & (1 << i)) {
				node = node_map[node][i];
				if (node == -1) {
					return node;
				}
			}
		}
		return node;
	}

private:
	std::vector<std::vector<int>> node_map;
	int idx;
};
