#include <vector>

class Solution {
public:
int Solve_Game(std::vector<int>& stones, std::vector<int>& sums, int low, int high, std::vector<std::vector<int>>& cache) {

	if (low >= high) return 0;
	
	if (cache[low][high] != -1) return cache[low][high];
	
	int right_sum = (low == 0) ? sums[high] : sums[high] - sums[low - 1];
	int left_sum = 0;

	int max_score = 0;
	int score = 0;
	int option_1 = 0;
	int option_2 = 0;

	for (int i = low; i < high; i++) {

		left_sum += stones[i];
		right_sum -= stones[i];

		if (left_sum < right_sum) score = Solve_Game(stones, sums, low, i, cache) + left_sum;
		
		else if (left_sum > right_sum) score = Solve_Game(stones, sums, i+1, high, cache) + right_sum;
		
		else {
			option_1 = Solve_Game(stones, sums, low, i, cache) + left_sum;
			option_2 = Solve_Game(stones, sums, i + 1, high, cache) + right_sum;
			score = (option_1 > option_2) ? option_1 : option_2;
		}
		max_score = (max_score > score) ? max_score : score;
	}

	cache[low][high] = max_score;

	return max_score;
}

int stoneGameV(std::vector<int>& stoneValue) {

	std::vector<int> sums(stoneValue.size());
	std::vector<std::vector<int>> cache(stoneValue.size(), std::vector<int>(stoneValue.size(), -1));

	sums[0] = stoneValue[0];
	for (int i = 1; i < sums.size(); i++) {
		sums[i] = stoneValue[i] + sums[i - 1];
	}

	return Solve_Game(stoneValue, sums, 0, stoneValue.size()-1, cache);
}
};
