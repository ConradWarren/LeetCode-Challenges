#include <vector>

class Solution {
public:
std::vector<std::vector<int>> construct2DArray(std::vector<int>& original, int m, int n) {

	if (m * n != original.size()) {
		return {};
	}

	std::vector<std::vector<int>> result(m, std::vector<int>(n));

	for (int i = 0; i < original.size(); i++) {
		result[i / n][i % n] = original[i];
	}

	return result;
}
};
