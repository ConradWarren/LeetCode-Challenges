class Solution {
public:
int Solve_Max(std::vector<std::vector<std::pair<int, int>>>& options, int idx, std::vector<int>& cache) {

	if (idx >= options.size()) {
		return 0;
	}

	if (cache[idx] != -1) {
		return cache[idx];
	}

	if (options.empty()) {
		cache[idx] = Solve_Max(options, idx + 1, cache);
		return cache[idx];
	}

	int current = Solve_Max(options, idx+1, cache);
	int best = current;

	for (int i = 0; i < options[idx].size(); i++) {
		current = options[idx][i].second + Solve_Max(options, options[idx][i].first + 1, cache);
		best = (best > current) ? best : current;
	}

	cache[idx] = best;

	return cache[idx];
}


int maximizeTheProfit(int n, std::vector<std::vector<int>>& offers) {

	std::vector<std::vector<std::pair<int, int>>> options(n);
	std::vector<int> cache(n, -1);

	for (int i = 0; i < offers.size(); i++) {
		options[offers[i][0]].push_back({ offers[i][1], offers[i][2] });
	}

	return Solve_Max(options, 0, cache);
}
};
