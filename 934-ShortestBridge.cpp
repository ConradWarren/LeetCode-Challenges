class Solution {
public:
std::queue<std::pair<int, int>> Map_Island(std::vector<std::vector<int>>& grid, int x_pos, int y_pos) {

	std::queue<std::pair<int, int>> valid_starting_positions;
	std::queue <std::pair<int, int>> position_que;

	position_que.push({ y_pos, x_pos });

	while (!position_que.empty()) {

		int y = position_que.front().first;
		int x = position_que.front().second;
		position_que.pop();
		bool valid_pos_flag = false;
		grid[y][x] = 2;

		if (x + 1 < grid.size()) {

			if (!valid_pos_flag && grid[y][x + 1] == 0) valid_pos_flag = true;

			else if (grid[y][x + 1] == 1) {
			  grid[y][x + 1] = 2;
				position_que.push({ y, x + 1 });
			} 

		}
		if (x - 1 >= 0) {
			if (!valid_pos_flag && grid[y][x - 1] == 0) valid_pos_flag = true;

			else if (grid[y][x - 1] == 1) {
				grid[y][x - 1] = 2;
				position_que.push({ y, x - 1 });
			}
		}
		if (y + 1 < grid.size()) {

			if (!valid_pos_flag && grid[y+1][x] == 0) valid_pos_flag = true;

			else if (grid[y+1][x] == 1) {
			  grid[y+1][x] = 2;
				position_que.push({ y+1, x });
			}
		}
		if (y - 1 >= 0) {

			if (!valid_pos_flag && grid[y - 1][x] == 0) valid_pos_flag = true;

			else if (grid[y - 1][x] == 1) {
			  grid[y - 1][x] = 2;
				position_que.push({ y - 1, x });
			}
		}

		if (valid_pos_flag) {
			valid_starting_positions.push({ y, x });
		}

	}
	return valid_starting_positions;
}

int Breadth_First_Search(std::vector<std::vector<int>>& grid, std::queue<std::pair<int, int>>& positions) {

	while (!positions.empty()) {

		int y = positions.front().first;
		int x = positions.front().second;
		positions.pop();
		int count = grid[y][x];

		if (x + 1 < grid.size()) {

			if (!grid[y][x+1]) {
				grid[y][x + 1] = count + 1;
				positions.push({ y, x + 1 });
			}
			else if (grid[y][x + 1] == 1) return count - 2;
		}
		if (x - 1 >= 0) {

			if (!grid[y][x - 1]) {
				grid[y][x - 1] = count + 1;
				positions.push({ y, x - 1 });
			}
			else if (grid[y][x - 1] == 1) return count - 2;
			
		}
		if (y + 1 < grid.size()) {
			if (!grid[y + 1][x]) {
				grid[y + 1][x] = count + 1;
				positions.push({ y + 1, x });
			}
			else if (grid[y+1][x] == 1) return count - 2;
		}
		if (y - 1 >= 0) {
			if (!grid[y - 1][x]) {
				grid[y - 1][x] = count + 1;
				positions.push({ y - 1, x });
			}
			else if (grid[y - 1][x] == 1) return count - 2;
		}
	}
	return 0;
}

int shortestBridge(std::vector<std::vector<int>>& grid) {

	std::queue<std::pair<int, int>> valid_starting_pos;

	for (int i = 0; i < grid.size() * grid.size(); i++) {

		if (grid[i / grid.size()][i % grid.size()]) {
			valid_starting_pos = Map_Island(grid, i % grid.size(), i / grid.size());
			break;
		}
		
	}

	return Breadth_First_Search(grid, valid_starting_pos);
}
};
