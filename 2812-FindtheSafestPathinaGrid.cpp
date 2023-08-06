class Solution {
public:
bool Can_Pass(std::vector<std::vector<int>>& grid, int limit, std::vector<std::vector<int>>& cache) {

	int y = 0;
	int x = 0;
	int temp_y = 0;
	int temp_x = 0;
	int distance = 0;
	int temp_distance = 0;
	std::vector<std::pair<int, int>> directions = { {0,1},{1,0},{0,-1},{-1, 0} };
	std::queue<std::pair<int, int>> que;
	
	que.push({ 0, grid[0][0]});

	while (!que.empty()) {
		
		int y = que.front().first / grid.size();
		int x = que.front().first % grid.size();
		int distance = que.front().second;
		que.pop();

		for (int i = 0; i < directions.size(); i++) {

			temp_y = y + directions[i].first;
			temp_x = x + directions[i].second;

			if (temp_y < 0 || temp_x < 0 || temp_y >= grid.size() || temp_x >= grid.size()) {
				continue;
			}

			if (cache[temp_y][temp_x] == limit) {
				continue;
			}

			cache[temp_y][temp_x] = limit;

			temp_distance = (distance < grid[temp_y][temp_x]) ? distance : grid[temp_y][temp_x];

			if (temp_distance >= limit) {
				que.push({ (temp_y * grid.size()) + temp_x , temp_distance });
			}

			if (temp_y == grid.size() - 1 && temp_x == grid.size() - 1 && temp_distance >= limit) {
				return true;
			}
		}

	}

	return false;
}

void Breadth_First_Search(std::queue<std::pair<int, int>>& que, std::vector<std::vector<int>>& grid) {

	int y = 0;
	int x = 0;
	int temp_y = 0;
	int temp_x = 0;
	int distance = 0;
	std::vector<std::pair<int, int>> directions = { {0,1},{1,0},{0,-1},{-1, 0} };

	while (!que.empty()) {

		y = que.front().first / grid.size();
		x = que.front().first % grid.size();
		distance = que.front().second + 1;
		que.pop();

		for (int i = 0; i < directions.size(); i++) {

			temp_y = y + directions[i].first;
			temp_x = x + directions[i].second;

			if (temp_y < 0 || temp_x < 0 || temp_y >= grid.size() || temp_x >= grid.size()) {
				continue;
			}

			if (grid[temp_y][temp_x] <= distance) {
				continue;
			}

			grid[temp_y][temp_x] = distance;
			que.push({ temp_y * grid.size() + temp_x, distance });
		}

	}
}

int maximumSafenessFactor(std::vector<std::vector<int>>& grid) {

	if (grid.size() == 1) {
		return 0;
	}

	std::vector<std::vector<int>> distance_grid(grid.size(), std::vector<int>(grid[0].size(), INT_MAX));
	std::vector<std::vector<int>> cache(grid.size(), std::vector<int>(grid[0].size(), -1));

	std::queue<std::pair<int, int>> que;
	int low = 0;
	int high = grid.size();
	int mid = (low + high) / 2;

	for (int i = 0; i < grid.size(); i++) {
		for (int j = 0; j < grid[0].size(); j++) {
			if (grid[i][j] == 1) {
				distance_grid[i][j] = 0;
				que.push({ i * distance_grid.size() + j, 0 });
			}
		}
	}

	Breadth_First_Search(que, distance_grid);



	while (low < high) {

		if (Can_Pass(distance_grid, mid, cache)) {
			low = mid + 1;
		}
		else {
			high = mid;
		}
		mid = (low + high) / 2;
	}

	return low-1;
}
};
