#include <vector>

class Solution {
public:
int countUnguarded(int m, int n, std::vector<std::vector<int>>& guards, std::vector<std::vector<int>>& walls) {

	std::vector<std::vector<bool>> grid(m, std::vector<bool>(n, false));
	std::vector<std::vector<bool>> is_gaurded(m, std::vector<bool>(n, false));
	int guarded_count = 0;

	for (int i = 0; i < guards.size(); i++) {
		grid[guards[i][0]][guards[i][1]] = true;
	}
	for (int i = 0; i < walls.size(); i++) {
		grid[walls[i][0]][walls[i][1]] = true;
	}

	for (int i = 0; i < guards.size(); i++) {

		int x_pos = guards[i][1];
		int y_pos = guards[i][0];

		while (x_pos+1 < n) {
			x_pos++;
			if (grid[y_pos][x_pos]) break;
			
			if (!is_gaurded[y_pos][x_pos]) {
				is_gaurded[y_pos][x_pos] = true;
				guarded_count++;
			}
		}

		x_pos = guards[i][1];

		while (x_pos - 1 >= 0) {
			x_pos--;
			if (grid[y_pos][x_pos]) break;
			
			if (!is_gaurded[y_pos][x_pos]) {
				is_gaurded[y_pos][x_pos] = true;
				guarded_count++;
			}
		}

		x_pos = guards[i][1];

		while (y_pos + 1 < m) {
			y_pos++;
			if (grid[y_pos][x_pos]) break;
			
			if (!is_gaurded[y_pos][x_pos]) {
				is_gaurded[y_pos][x_pos] = true;
				guarded_count++;
			}

		}

		y_pos = guards[i][0];

		while (y_pos - 1 >= 0) {
			y_pos--;
			if (grid[y_pos][x_pos]) break;
			
			if (!is_gaurded[y_pos][x_pos]) {
				is_gaurded[y_pos][x_pos] = true;
				guarded_count++;
			}
		}
	}

	return (m * n) - guarded_count - guards.size() - walls.size();
}
};
