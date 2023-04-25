#include <vector>

class Solution {
public:
bool checkXMatrix(std::vector<std::vector<int>>& grid) {

	for (int i = 0; i < grid.size(); i++) {
		if (grid[i][i] == 0) return false;
		if (grid[i][grid.size() - 1 - i] == 0) return false;
	}

	for (int i = 0; i < grid.size(); i++) {
		for (int j = 0; j < grid.size(); j++) {

			if (j == i) continue;
			
			if (j == grid.size() - 1 - i) continue;
			
			if (grid[i][j] != 0) return false;
		}
	}
	
	return true;
}
};
