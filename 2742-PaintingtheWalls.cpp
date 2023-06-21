#include <vector>

class Solution {
public:
int Find_Min(std::vector<int>& cost, std::vector<int>& time, int idx, int n, std::vector<std::vector<int>>& cache) {

	if (n <= 0) return 0;
	
	if (idx >= cost.size()) return int(1e9);
	
	if (cache[n][idx] != -1) return cache[n][idx];
	
	int skip = Find_Min(cost, time, idx + 1, n, cache);
	int takes = cost[idx] + Find_Min(cost, time, idx + 1, n - time[idx] - 1, cache);

	cache[n][idx] = (takes < skip) ? takes : skip;

	return cache[n][idx];
}

int paintWalls(std::vector<int>& cost, std::vector<int>& time) {

	int n = cost.size();

	std::vector<std::vector<int>> cache(n + 1, std::vector<int>(n, -1));

	return Find_Min(cost, time, 0, n, cache);
}
};
