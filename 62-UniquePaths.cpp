class Solution {
public:
int Count_Paths(std::vector<std::vector<int>>& grid, int y, int x) {

	if (y < 0 || x < 0 || y >= grid.size() || x >= grid[0].size()) {
		return 0;
	}

	if (y + 1 == grid.size() && x + 1 == grid[0].size()) {
		return 1;
	}

	if (grid[y][x] != -1) {
		return grid[y][x];
	}

	int down = Count_Paths(grid, y + 1, x);
	int right = Count_Paths(grid, y, x + 1);

	grid[y][x] = down + right;

	return down + right;
}

int uniquePaths(int m, int n) {

	std::vector<std::vector<int>> grid(m, std::vector<int>(n, -1));

	return Count_Paths(grid, 0, 0);
}
};
