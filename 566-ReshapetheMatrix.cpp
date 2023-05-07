#include <vector>

class Solution {
public:
std::vector<std::vector<int>> matrixReshape(std::vector<std::vector<int>>& mat, int r, int c) {

	if ((r * c) != (mat.size() * mat[0].size())) {
		return mat;
	}

	std::vector<std::vector<int>> result(r, std::vector<int>(c));

	for (int i = 0; i < mat.size() * mat[0].size(); i++) {
		result[i / c][i % c] = mat[i/mat[0].size()][i%mat[0].size()];
	}

	return result;
}
};
