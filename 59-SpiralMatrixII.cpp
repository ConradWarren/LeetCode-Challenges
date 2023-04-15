#include <vector>

class Solution {
public:
std::vector<std::vector<int>> generateMatrix(int n) {

	std::vector<std::vector<int>> grid(n, std::vector<int>(n, 0));

	int idx = 1;
	int top_border = 0;
	int left_border = 0;
	int right_border = n;
	int bottom_border = n;

	while (idx <= (n * n)) {

		for (int i = left_border; i < right_border; i++) {
			if (idx > n * n) break;
			grid[top_border][i] = idx;
			idx++;
		}

		top_border++;
		
		for (int i = top_border; i < bottom_border; i++) {
			if (idx > n * n) break;
			grid[i][right_border - 1] = idx;
			idx++;
		}

		right_border--;

		for (int i = right_border - 1; i >= left_border; i--) {
			if (idx > n * n) break;
			grid[bottom_border - 1][i] = idx;
			idx++;
		}

		bottom_border--;

		for (int i = bottom_border - 1; i >= top_border; i--) {
			if (idx > n * n) break;
			grid[i][left_border] = idx;
			idx++;
		}

		left_border++;
	}

	return grid;
}
};
