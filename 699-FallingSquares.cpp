#include <vector>

class Solution {
public:
bool Intersection(std::vector<int>& square_1, std::vector<int>& square_2) {

	int left_edge_1 = square_1[0];
	int left_edge_2 = square_2[0];

	int right_edge_1 = square_1[1] + square_1[0];
	int right_edge_2 = square_2[1] + square_2[0];

	if (left_edge_1 > left_edge_2 && left_edge_1 < right_edge_2) {
		return true;
	}
	if (right_edge_1 > left_edge_2 && right_edge_1 < right_edge_2) {
		return true;
	}
	if (left_edge_1 <= left_edge_2 && right_edge_1 >= right_edge_2) {
		return true;
	}

	return false;
}


std::vector<int> fallingSquares(std::vector<std::vector<int>>& positions) {

	std::vector<int> result(positions.size());
	std::vector<int> heights(positions.size(), 0);
	int current_height = 0;
	int largest_height = 0;

	for (int i = 0; i < positions.size(); i++) {

		current_height = 0;

		for (int j = 0; j < i; j++) {
			if (Intersection(positions[j], positions[i]) && heights[j] > current_height) {
				current_height = heights[j];
			}
		}

		heights[i] = positions[i][1] + current_height;
		largest_height = (largest_height > heights[i]) ? largest_height : heights[i];
		result[i] = largest_height;
	}


	return result;
}
};
