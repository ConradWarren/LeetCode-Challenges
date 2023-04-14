#include <vector>

class Solution {
public:
std::vector<int> spiralOrder(std::vector<std::vector<int>>& matrix) {

	int bottom_boarder = matrix.size();
	int top_boarder = 0;
	int left_boarder = 0;
	int right_boarder = matrix[0].size();

	std::vector<int> spiral_order(matrix.size() * matrix[0].size());
	int idx = 0;

	while (idx < spiral_order.size()) {

		for (int i = left_boarder; i < right_boarder; i++) {

			if (idx >= spiral_order.size()) break;

			spiral_order[idx] = matrix[top_boarder][i];
			idx++;
		}

		top_boarder++;

		for (int i = top_boarder; i < bottom_boarder; i++) {

			if (idx >= spiral_order.size()) break;
			
			spiral_order[idx] = matrix[i][right_boarder - 1];
			idx++;
		}

		right_boarder--;

		for (int i = right_boarder - 1; i >= left_boarder; i--) {

			if (idx >= spiral_order.size()) break;
			
			spiral_order[idx] = matrix[bottom_boarder - 1][i];
			idx++;
		}

		bottom_boarder--;

		for (int i = bottom_boarder - 1; i >= top_boarder; i--) {

			if (idx >= spiral_order.size()) break;
			
			spiral_order[idx] = matrix[i][left_boarder];
			idx++;
		}

		left_boarder++;
	}

	return spiral_order;
}
};
