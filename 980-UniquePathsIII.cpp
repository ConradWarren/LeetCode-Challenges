class Solution {
public:
int Count_Paths(std::vector<std::vector<int>>& grid, int y, int x,int count) {

	if (y < 0 || x < 0 || y >= grid.size() || x >= grid[0].size()) {
		return 0;
	}

	if (grid[y][x] == -1) {
		return 0;
	}

	if (grid[y][x] == 2) {
		return (count == 0) ? 1 : 0;
	}

	grid[y][x] = -1;

	int result = 0;

	result += Count_Paths(grid, y+1, x, count - 1);
	result += Count_Paths(grid, y, x+1, count - 1);
	result += Count_Paths(grid, y-1, x, count - 1);
	result += Count_Paths(grid, y, x-1, count - 1);

	grid[y][x] = 0;

	return result;
}

int uniquePathsIII(std::vector<std::vector<int>>& grid) {

	int count = 0;
	int start_y = 0;
	int start_x = 0;

	for (int i = 0; i < grid.size(); i++) {
		for (int j = 0; j < grid[0].size(); j++) {

			if (grid[i][j] == 0) {
				count++;
			}
			else if (grid[i][j] == 1) {
				start_y = i;
				start_x = j;
			}

		}
	}

	return Count_Paths(grid, start_y, start_x, count+1);
}
};
