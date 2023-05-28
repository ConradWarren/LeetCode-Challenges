class Solution {
public:
std::vector<std::vector<int>> differenceOfDistinctValues(std::vector<std::vector<int>>& grid) {

	std::vector<std::vector<int>> result(grid.size(), std::vector<int>(grid[0].size()));

	std::unordered_set<int> set_1;
	std::unordered_set<int> set_2;
	int y = 0;
	int x = 0;

	for (int i = 0; i < grid.size(); i++) {
		for (int j = 0; j < grid[i].size(); j++) {

			y = i - 1;
			x = j - 1;

			while (x >= 0 && y >= 0) {
				set_1.insert(grid[y][x]);
				x--;
				y--;
			}

			y = i + 1;
			x = j + 1;

			while (y < grid.size() && x < grid[0].size()) {
				set_2.insert(grid[y][x]);
				x++;
				y++;
			}

			result[i][j] = std::abs(int(set_1.size()) - int(set_2.size()));
			set_1.clear();
			set_2.clear();
		}
	}

	return result;
}
};
