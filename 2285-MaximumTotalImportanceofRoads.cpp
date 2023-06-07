#include <vector>

class Solution {
public:
long long maximumImportance(int n, std::vector<std::vector<int>>& roads) {

	std::vector<int> n_degree(n, 0);
	long long result = 0LL;

	for (int i = 0; i < roads.size(); i++) {
		n_degree[roads[i][0]]++;
		n_degree[roads[i][1]]++;
	}

	std::sort(n_degree.begin(), n_degree.end());

	for (int i = 0; i < n; i++) {
		result += ((long long)(i + 1) * (long long)(n_degree[i]));
	}
	return result;
}
};
