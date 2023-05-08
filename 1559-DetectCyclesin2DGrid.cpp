#include <vector>

class Solution {
public:
bool Depth_First_Search(std::vector<std::vector<char>>& grid, std::vector<std::vector<int>>& has_visted, int x_pos, int y_pos,int distance, char target) {


	if (x_pos < 0 || y_pos < 0 || x_pos >= grid[0].size() || y_pos >= grid.size()) {
		return false;
	}

	if (grid[y_pos][x_pos] != target) {
		return false;
	}

	if (has_visted[y_pos][x_pos] && abs(has_visted[y_pos][x_pos] - distance) > 3) {
		return true;
	}

	if (has_visted[y_pos][x_pos]) {
		return false;
	}

	has_visted[y_pos][x_pos] = distance;

	if (Depth_First_Search(grid, has_visted, x_pos + 1, y_pos,distance +1 ,target)) {
		return true;
	}
	if (Depth_First_Search(grid, has_visted, x_pos, y_pos+1, distance + 1,target)) {
		return true;
	}
	if (Depth_First_Search(grid, has_visted, x_pos-1, y_pos, distance + 1, target)) {
		return true;
	}
	if (Depth_First_Search(grid, has_visted, x_pos, y_pos-1, distance + 1, target)) {
		return true;
	}

	return false;
}


bool containsCycle(std::vector<std::vector<char>>& grid) {

	std::vector<std::vector<int>> has_visted(grid.size(), std::vector<int>(grid[0].size(), 0));

	for (int i = 0; i < grid.size(); i++) {
		for (int j = 0; j < grid[i].size(); j++) {
			if (has_visted[i][j]) {
				continue;
			}

			if (Depth_First_Search(grid, has_visted, j, i, 1, grid[i][j])) {
				return true;
			}
			
		}
	}

	return false;
}
};
