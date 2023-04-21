class Solution {
public:
int Solve(std::vector<int>& group, std::vector<int>& profit, int profit_left, int people_left, int idx,
		  std::vector<std::vector<std::vector<int>>>& cache) {

	if (people_left < 0) return 0; 
	
	if (idx == group.size()) {
		if (profit_left <= 0) return 1;
		else return 0;
	}

	if (profit_left < 0) profit_left = 0;
	
	if (cache[profit_left][people_left][idx] != -1) return cache[profit_left][people_left][idx];
	
	int takes_job = Solve(group, profit, profit_left - profit[idx], people_left - group[idx], idx + 1, cache) % 1000000007;
	int leaves_job = Solve(group, profit, profit_left, people_left, idx + 1, cache)% 1000000007;

	cache[profit_left][people_left][idx] = ((takes_job + leaves_job) % 1000000007);

	return cache[profit_left][people_left][idx];
}

int profitableSchemes(int n, int minProfit, std::vector<int>& group, std::vector<int>& profit) {

	std::vector<std::vector<std::vector<int>>> cache(minProfit + 1, std::vector<std::vector<int>>(n + 1, std::vector<int>(group.size(), -1)));

	return Solve(group, profit, minProfit, n, 0, cache);
}
};
