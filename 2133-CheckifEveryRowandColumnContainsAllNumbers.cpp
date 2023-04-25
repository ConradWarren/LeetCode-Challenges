#include <vector>

class Solution {
public:
bool checkValid(std::vector<std::vector<int>>& matrix) {

	for (int i = 0; i < matrix.size(); i++) {
		std::vector<bool> row_vec(matrix.size() + 1, false);
		std::vector<bool> coloum_vec(matrix.size() + 1, false);

		for (int j = 0; j < matrix.size(); j++) {
			if (row_vec[matrix[i][j]]) return false;
			if (coloum_vec[matrix[j][i]]) return false;
			row_vec[matrix[i][j]] = true;
			coloum_vec[matrix[j][i]] = true;
		}
	}
	return true;
}
};
