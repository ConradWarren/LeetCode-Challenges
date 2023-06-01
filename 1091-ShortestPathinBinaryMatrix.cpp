#include <vector>
#include <queue>

class Solution {
public:
int shortestPathBinaryMatrix(std::vector<std::vector<int>>& grid) {

	if (grid.front().front()) return -1;
	
	int n = grid.size();
	int target = (n * n) - 1;
	int y = 0;
	int x = 0;
	int current_distance = 0;

	std::vector<std::vector<bool>> visted_node(grid.size(), std::vector<bool>(grid.size(), false));

	std::queue<std::pair<int, int>> queue;

	queue.push({ 0, 1 });

	while (!queue.empty()) {

		if (queue.front().first == target) return queue.front().second;
		
		y = queue.front().first / n;
		x = queue.front().first % n;
		current_distance = queue.front().second;
		queue.pop();

		if (visted_node[y][x]) continue;
		
		visted_node[y][x] = true;

		if (x + 1 < n && y + 1 < n && !grid[y + 1][x + 1]) {
			queue.push({ ((y + 1) * n) + (x + 1) ,current_distance + 1 });
		}
		if (x + 1 < n && !grid[y][x + 1]) {
			queue.push({ (y * n) + (x + 1) ,current_distance + 1 });
		}
		if (y + 1 < n && !grid[y + 1][x]) {
			queue.push({ ((y + 1) * n) + x ,current_distance + 1 });
		}
		if (x - 1 >= 0 && y - 1 >= 0 && !grid[y - 1][x - 1]) {
			queue.push({ ((y - 1) * n) + (x - 1) ,current_distance + 1 });
		}
		if (x - 1 >= 0 && !grid[y][x - 1]) {
			queue.push({ (y * n) + (x - 1) ,current_distance + 1 });
		}
		if (y - 1 >= 0 && !grid[y - 1][x]) {
			queue.push({ ((y - 1) * n) + x ,current_distance + 1 });
		}
		if (y - 1 >= 0 && x + 1 < n && !grid[y - 1][x + 1]) {
			queue.push({ ((y - 1) * n) + (x + 1) ,current_distance + 1 });
		}
		if (y + 1 < n && x - 1 >= 0 && !grid[y + 1][x - 1]) {
			queue.push({ ((y + 1) * n) + (x - 1) ,current_distance + 1 });
		}
	}
	return -1;
}
};
