#include <vector>

class Solution {
public:
int edgeScore(std::vector<int>& edges) {

	std::vector<long long> edge_scores(edges.size(), 0);
	int highest_node = 0;
	
	for (int i = 0; i < edges.size(); i++) {
		edge_scores[edges[i]] += i;
	}

	for (int i = 0; i < edge_scores.size(); i++) {
		highest_node = (edge_scores[highest_node] >= edge_scores[i]) ? highest_node : i;
	}

	return highest_node;
}
};
