#include <vector>

class Solution {
public:
int diagonalSum(std::vector<std::vector<int>>& mat) {

	int sum = 0;
	for (int i = 0; i < mat.size(); i++) {
		sum += mat[i][i];
		mat[i][i] = 0;
	}

	for (int i = mat.size() - 1; i >= 0; i--) {
		sum += mat[mat.size() - i - 1][i];
	}

	return sum;
}
};
