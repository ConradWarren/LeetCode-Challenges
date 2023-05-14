class Solution {
public:
int maxMoves(std::vector<std::vector<int>>& grid) {

	std::vector<std::vector<bool>> possible(grid.size(), std::vector<bool>(grid[0].size(), false));
	bool valid_flag = false;

	for (int i = 0; i < grid.size(); i++) {
		possible[i][0] = true;
	}

	for (int j = 0; j < grid[0].size() - 1; j++) {

		valid_flag = false;

		if (possible[0][j] && grid[0][j] < grid[0][j + 1]) {
			possible[0][j + 1] = true;
			valid_flag = true;
		}

		if (possible[0][j] && grid[0][j] < grid[1][j + 1]) {
			possible[1][j + 1] = true;
			valid_flag = true;
		}

		for (int i = 1; i < grid.size() - 1; i++) {

			if (!possible[i][j]) continue;
			
			if (grid[i][j] < grid[i - 1][j + 1]) {
				possible[i - 1][j + 1] = true;
				valid_flag = true;
			}
			if (grid[i][j] < grid[i][j + 1]) {
				possible[i][j + 1] = true;
				valid_flag = true;
			}
			if (grid[i][j] < grid[i + 1][j + 1]) {
				possible[i + 1][j + 1] = true;
				valid_flag = true;
			}
		}

		if (possible[grid.size() - 1][j] && grid[grid.size() - 1][j] < grid[grid.size() - 1][j + 1]) {
			possible[grid.size() - 1][j + 1] = true;
			valid_flag = true;
		}

		if (possible[grid.size() - 1][j] && grid[grid.size() - 1][j] < grid[grid.size() - 2][j + 1]) {
			possible[grid.size() - 2][j + 1] = true;
			valid_flag = true;
		}

		if (!valid_flag) return j;
	}

	return grid[0].size() - 1;
}
};
