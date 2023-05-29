#include <vector>

class Solution {
public:
int Solve(std::vector<int>& piles, int low, int high, std::vector<std::vector<int>>& cache) {
	
	if (low > high) {
		return 0;
	}

	if (cache[low][high] != -1) {
		return cache[low][high];
	}

	int takes_front = piles[low] - Solve(piles, low + 1, high, cache);

	int takes_back = piles[high] - Solve(piles, low, high - 1, cache);

	cache[low][high] = (takes_front > takes_back) ? takes_front : takes_back;

	return cache[low][high];
}

bool stoneGame(std::vector<int>& piles) {

	std::vector<std::vector<int>> cache(piles.size(), std::vector<int>(piles.size(), -1));

	int score = Solve(piles, 0, piles.size() - 1, cache);

	return (score < 0) ? false : true;
}
};
