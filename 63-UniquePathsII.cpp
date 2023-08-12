#include <vector>

class Solution {
public:
int uniquePathsWithObstacles(std::vector<std::vector<int>>& obstacleGrid) {

	std::vector<std::vector<int>> Grid(obstacleGrid.size(), std::vector<int>(obstacleGrid.front().size(), 0));

	for (int i = 0; i < Grid.size(); i++) {
		if (obstacleGrid[i][0]) {
			break;
		}
		Grid[i][0] = 1;
	}

	for (int i = 0; i < Grid.front().size(); i++) {
		if (obstacleGrid[0][i]) {
			break;
		}
		Grid[0][i] = 1;
	}

	for (int i = 1; i < Grid.size(); i++) {
		for (int j = 1; j < Grid.front().size(); j++) {
			if (obstacleGrid[i][j]) {
				continue;
			}
			Grid[i][j] = Grid[i - 1][j] + Grid[i][j - 1];
		}
	}

	return Grid.back().back();
}
};
