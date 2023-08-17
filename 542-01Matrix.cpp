#include <vector>
#Include <queue>

class Solution {
public:
void Breadth_First_Search(std::vector<std::vector<int>>& grid, std::queue<std::pair<int, int>>& node_queue) {

	std::vector<std::pair<int, int>> directions = { {0,1},{1,0},{0,-1},{-1,0} };
	int y = 0;
	int x = 0;
	int temp_y = 0;
	int temp_x = 0;
	int distance = 0;

	while (!node_queue.empty()) {

		y = node_queue.front().first / grid[0].size();
		x = node_queue.front().first % grid[0].size();
		distance = 1 + node_queue.front().second;
		node_queue.pop();

		for (int i = 0; i < directions.size(); i++) {

			temp_y = y + directions[i].first;
			temp_x = x + directions[i].second;

			if (temp_y < 0 || temp_x < 0 || temp_y >= grid.size() || temp_x >= grid[0].size()) {
				continue;
			}

			if (grid[temp_y][temp_x] > distance) {
				grid[temp_y][temp_x] = distance;
				node_queue.push({ (temp_y * grid[0].size()) + temp_x, distance });
			}
		}
	}

}

std::vector<std::vector<int>> updateMatrix(std::vector<std::vector<int>>& mat) {

	std::vector<std::vector<int>> result(mat.size(), std::vector<int>(mat[0].size(), INT_MAX));
	std::queue<std::pair<int, int>> node_queue;

	for (int i = 0; i < mat.size(); i++) {
		for (int j = 0; j < mat[0].size(); j++) {
			if (mat[i][j] == 0) {
				node_queue.push({ (i * mat[0].size()) + j ,0 });
				result[i][j] = 0;
			}
		}
	}

	Breadth_First_Search(result, node_queue);

	return result;
}
};
