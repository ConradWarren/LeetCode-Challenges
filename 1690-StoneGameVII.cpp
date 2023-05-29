#include <vector>

class Solution {
public:
int Solve_Score(std::vector<int>& stones, int low, int high, int sum, std::vector<std::vector<int>>& cache) {

	if (low >= high) {
		return 0;
	}

	if(cache[low][high] != INT_MIN) {
		return cache[low][high];
	}

	int option_1 = sum - stones[low] - Solve_Score(stones, low + 1, high, sum - stones[low], cache);
	int option_2 = +sum - stones[high] - Solve_Score(stones, low, high-1, sum - stones[high], cache);

	cache[low][high] = (option_1 > option_2) ? option_1 : option_2;

	return cache[low][high];
}

int stoneGameVII(std::vector<int>& stones) {

	int sum = std::accumulate(stones.begin(), stones.end(), 0);

	std::vector<std::vector<int>> cache(stones.size(), std::vector<int>(stones.size(), INT_MIN));

	return Solve_Score(stones, 0, stones.size() - 1, sum, cache);
}
};
