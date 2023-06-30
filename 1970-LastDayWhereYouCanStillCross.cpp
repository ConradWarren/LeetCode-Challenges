#include <vector>

class Solution {
public:
bool Depth_Frist_Search(std::vector<std::vector<int>>& grid,std::vector<std::vector<bool>>& visted_nodes, int y, int x, int day) {

	if (y < 0 || y >= grid.size() || x < 0 || x >= grid[0].size()) return false;

	if (visted_nodes[y][x]) return false;
	
	if (grid[y][x] <= day) return false;
	
	if (y == grid.size() - 1) return true;
	
	visted_nodes[y][x] = true;

	if (Depth_Frist_Search(grid,visted_nodes, y+1, x, day)) return true;
	
	if (Depth_Frist_Search(grid,visted_nodes, y, x+1, day)) return true;
	
	if (Depth_Frist_Search(grid,visted_nodes, y, x-1, day)) return true;
	
	if (Depth_Frist_Search(grid,visted_nodes, y-1, x, day)) return true;
	
	return false;
}


int latestDayToCross(int row, int col, std::vector<std::vector<int>>& cells) {

	std::vector<std::vector<int>> grid(row, std::vector<int>(col, cells.size()+1));
	std::vector<std::vector<bool>> visted_nodes;
	int low = 0;
	int high = cells.size();
	int mid = (low + high) / 2;

	for (int i = 0; i < cells.size(); i++) {
		grid[int(cells[i][0] - 1)][int(cells[i][1] - 1)] = i + 1;
	}

	while (low < high) {

		bool passes_flag = false;
		visted_nodes.clear();
		visted_nodes.resize(row, std::vector<bool>(col, false));
		for (int i = 0; i < grid[0].size(); i++) {
			
			if (Depth_Frist_Search(grid,visted_nodes, 0, i, mid)) {
				passes_flag = true;
				break;
			}
		}

		if (passes_flag) low = mid + 1;
		
		else high = mid;
		
		mid = (low + high) / 2;
	}

	return max(low - 1, 0);
}
};
