#include <vector>

class Solution {
public:
int Depth_First_Search(std::vector<std::vector<int>>& grid,int y, int x,int last_value, std::vector<std::vector<int>>& cache) {

	if (y < 0 || x < 0 || y >= grid.size() || x >= grid[0].size()) {
		return -1;
	}

	if (grid[y][x] <= last_value) {
		return -1;
	}

	if (cache[y][x] != -1) {
		return cache[y][x];
	}

	int result = 1;
	int current = 0;

	current = 1 + Depth_First_Search(grid, y+1, x, grid[y][x], cache);
	result = (result > current) ? result : current;

	current = 1 + Depth_First_Search(grid, y, x+1, grid[y][x], cache);
	result = (result > current) ? result : current;
	
	current = 1 + Depth_First_Search(grid, y-1, x, grid[y][x], cache);
	result = (result > current) ? result : current;

	current = 1 + Depth_First_Search(grid, y, x-1, grid[y][x], cache);
	result = (result > current) ? result : current;

	cache[y][x] = result;

	return result;
}


int longestIncreasingPath(std::vector<std::vector<int>>& matrix) {

	std::vector<std::vector<int>> cache(matrix.size(), std::vector<int>(matrix[0].size(), -1));
	int result = 0;
	int current = 0;
	
	for (int i = 0; i < matrix.size(); i++) {
		for (int j = 0; j < matrix[0].size(); j++) {

			if (cache[i][j] != -1) {
				continue;
			}

			current = Depth_First_Search(matrix, i, j, -1, cache);
			result = (result > current) ? result : current;
		}
	}

	return result;
}
};
