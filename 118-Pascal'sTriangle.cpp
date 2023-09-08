class Solution {
public:
std::vector<std::vector<int>> generate(int numRows) {

	std::vector<std::vector<int>> result(numRows);

	result[0] = { 1 };

	for (int i = 1; i < numRows; i++) {
		
		result[i].resize(i + 1, 1);

		for (int j = 1; j < result[i].size() - 1; j++) {
			result[i][j] = result[i - 1][j - 1] + result[i - 1][j];
		}

	}

	return result;
}
};
