class Solution {
public:
void Depth_First_Search(std::vector<std::vector<std::vector<int>>>& cache,std::vector<std::string>& grid, int bitmask, int keys, int y_pos, int x_pos,int distance, int& result) {

	if (y_pos < 0 || x_pos < 0 || y_pos >= grid.size() || x_pos >= grid[0].size()) {
		return;
	}

	if (grid[y_pos][x_pos] == '#') {
		return;
	}

	if (cache[bitmask][y_pos][x_pos] <= distance || distance >= result) {
		return;
	}

	if (int(grid[y_pos][x_pos]) >= int('a') && int(grid[y_pos][x_pos]) <= 'z' && !(bitmask & (1 << grid[y_pos][x_pos] - int('a')))) {
		bitmask |= (1 << (grid[y_pos][x_pos] - int('a')));
		keys--;
	}

	if (keys == 0) {
		result = (result < distance) ? result : distance;
		return;
	}

	if (grid[y_pos][x_pos] >= int('A') && grid[y_pos][x_pos] <= 'Z' && !(bitmask & (1 << grid[y_pos][x_pos] - int('A'))) ) {
		return;
	}

	cache[bitmask][y_pos][x_pos] = distance;

	Depth_First_Search(cache, grid, bitmask, keys, y_pos+1, x_pos, distance + 1, result);
	Depth_First_Search(cache, grid, bitmask, keys, y_pos, x_pos+1, distance + 1, result);
	Depth_First_Search(cache, grid, bitmask, keys, y_pos-1, x_pos, distance + 1, result);
	Depth_First_Search(cache, grid, bitmask, keys, y_pos, x_pos-1, distance + 1, result);

}

int shortestPathAllKeys(std::vector<std::string>& grid) {

	std::vector<std::vector<std::vector<int>>> cache;
	std::vector<std::pair<int, int>> directions = { {1,0},{0,1},{-1,0},{0,-1} };
	std::queue<std::vector<int>> que;
	int start_y = 0;
	int start_x = 0;
	int keys = 0;
	int key_bitmask = 0;
	int result = INT_MAX;
	

	for (int i = 0; i < grid.size(); i++) {
		for (int j = 0; j < grid[0].size(); j++) {

			if (grid[i][j] == '@') {
				start_y = i;
				start_x = j;
			}
			else if (grid[i][j] >= int('a') && grid[i][j] <= int('z')) {
				keys++;
			}

		}
	}
	cache.resize(int(1 << (keys + 1)), std::vector<std::vector<int>>(grid.size(), std::vector<int>(grid[0].size(), INT_MAX)));

	Depth_First_Search(cache, grid, key_bitmask, keys, start_y, start_x, 0, result);

	return (result == INT_MAX) ? -1 : result;
}
};
