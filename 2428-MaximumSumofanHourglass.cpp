#include <vector>

class Solution {
public:
int maxSum(std::vector<std::vector<int>>& grid) {

	int rolling_sum_1 = 0;
	int rolling_sum_2 = 0;
	int max_sum = 0;

	for (int i = 0; i < grid.size()-2; i++) {

		rolling_sum_1 = 0;
		rolling_sum_2 = 0;

		for (int j = 0; j < 3; j++) {
			rolling_sum_1 += grid[i][j];
			rolling_sum_2 += grid[i + 2][j];
		}

		max_sum = (max_sum > rolling_sum_1 + rolling_sum_2 + grid[i + 1][1]) ? max_sum : rolling_sum_1+ rolling_sum_2 + grid[i+1][1];

		for (int j = 3; j < grid[i].size(); j++) {

			rolling_sum_1 += grid[i][j];
			rolling_sum_1 -= grid[i][j - 3];

			rolling_sum_2 += grid[i + 2][j];
			rolling_sum_2 -= grid[i + 2][j - 3];

			max_sum = (max_sum > rolling_sum_1 + rolling_sum_2 + grid[i + 1][j-1]) ? max_sum : rolling_sum_1 + rolling_sum_2 + grid[i + 1][j-1];
		}
	}
	return max_sum;
}
};
