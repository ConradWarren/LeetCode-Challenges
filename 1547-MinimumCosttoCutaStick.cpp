#include <vector>

class Solution {
public:
int Solve_Min_Costs(std::vector<int>& cuts, int low, int high, std::vector<std::vector<int>>& cache) {

	if (low + 1 >= high) return 0;
	
	if (cache[low][high] != -1) return cache[low][high];
	
	int min_cost = INT_MAX;
	int cost = 0;
	for (int i = low + 1; i < high; i++) {
		cost = (cuts[high] - cuts[low]) + Solve_Min_Costs(cuts, low, i, cache) + Solve_Min_Costs(cuts, i, high, cache);
		min_cost = (min_cost < cost) ? min_cost : cost;
	}

	cache[low][high] = min_cost;

	return min_cost;
}

int minCost(int n, std::vector<int>& cuts) {

	std::vector<std::vector<int>> cache(cuts.size()+2, std::vector<int>(cuts.size()+2, -1));

	std::sort(cuts.begin(), cuts.end());
	cuts.insert(cuts.begin(), 0);
	cuts.push_back(n);
	
	return Solve_Min_Costs(cuts, 0, cuts.size() - 1, cache);
}
};
