#include <vector>

class Solution {
public:
int equalPairs(std::vector<std::vector<int>>& grid) {

	std::vector<std::vector<int>> grid_transposed(grid.size(), std::vector<int>(grid.size()));
	int result = 0;

	for (int i = 0; i < grid.size(); i++) {
		for (int j = 0; j < grid.size(); j++) {
			grid_transposed[i][j] = grid[j][i];
		}
	}

	for (int i = 0; i < grid.size(); i++) {
		for (int j = 0; j < grid.size(); j++) {

			if (grid[i] == grid_transposed[j]) result++;
			
		}
	}
	return result;
}
};
