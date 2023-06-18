#include <vector>

class Solution {
public:
int Depth_First_Search(std::vector<std::vector<int>>& grid, int last_value, int y_pos, int x_pos, std::vector<std::vector<int>>& cache) {

	if (x_pos < 0 || y_pos < 0 || y_pos >= grid.size() || x_pos >= grid[0].size()) {
		return -1;
	}

	if (grid[y_pos][x_pos] <= last_value) {
		return -1;
	}

	if (cache[y_pos][x_pos] != -1) {
		return cache[y_pos][x_pos];
	}

	cache[y_pos][x_pos] = 0;
	cache[y_pos][x_pos] += 1 + Depth_First_Search(grid, grid[y_pos][x_pos], y_pos, x_pos+1, cache);
	cache[y_pos][x_pos] %= 1000000007;
	cache[y_pos][x_pos] += 1 + Depth_First_Search(grid, grid[y_pos][x_pos], y_pos+1, x_pos, cache);
	cache[y_pos][x_pos] %= 1000000007;
	cache[y_pos][x_pos] += 1 + Depth_First_Search(grid, grid[y_pos][x_pos], y_pos-1, x_pos, cache);
	cache[y_pos][x_pos] %= 1000000007;
	cache[y_pos][x_pos] += 1 + Depth_First_Search(grid, grid[y_pos][x_pos], y_pos, x_pos-1, cache);
	cache[y_pos][x_pos] %= 1000000007;

	return cache[y_pos][x_pos];
}

int countPaths(std::vector<std::vector<int>>& grid) {

	std::vector<std::vector<int>> cache(grid.size(), std::vector<int>(grid[0].size(), -1));

	int mod = int(1e9) + 7;
	int sum = 0;

	for (int i = 0; i < grid.size(); i++) {
		for (int j = 0; j < grid[0].size(); j++) {

			if (cache[i][j] != -1) {
				sum += (cache[i][j] % mod);
			}
			else {
				sum += (Depth_First_Search(grid, -1, i, j, cache))%mod;
			}
			sum++;
			sum %= mod;
		}
	}

	return sum;
}
};
