class Solution {
public:
int Solve(int idx, int m, std::vector<int>& piles, std::vector<std::vector<int>>& cache) {

	if (idx >= piles.size()) {
		return 0;
	}

	if (cache[idx][m] != -1) {
		return cache[idx][m];
	}

	int sum = 0;
	int max_sum = INT_MIN;
	int next_m = 0;
	int next_sum = 0;
	
	for (int j = 0; j < m * 2 && idx + j < piles.size(); j++) {

		sum += piles[idx + j];
		next_m = (j + 1 > m) ? j + 1 : m;
		next_sum = Solve(idx + j + 1, next_m, piles, cache);

		max_sum = (max_sum > sum - next_sum) ? max_sum : sum - next_sum;
	}

	cache[idx][m] = max_sum;

	return max_sum;
}


int stoneGameII(std::vector<int>& piles) {

	std::vector<std::vector<int>> cache(piles.size(), std::vector<int>(piles.size()+1, -1));

	int pile_sum = std::accumulate(piles.begin(), piles.end(), 0);


	pile_sum += Solve(0, 1, piles, cache);


	return (pile_sum / 2);
}
};
