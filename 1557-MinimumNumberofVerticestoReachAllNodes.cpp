#include <vector>

class Solution {
public:
std::vector<int> findSmallestSetOfVertices(int n, std::vector<std::vector<int>>& edges) {

	std::vector<int> counts(n, 0);
	std::vector<int> result;

	for (int i = 0; i < edges.size(); i++) {
		counts[edges[i][1]]++;
	}

	for (int i = 0; i < n; i++) {

		if (!counts[i]) result.push_back(i);

	}

	return result;
}
};
