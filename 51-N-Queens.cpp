#include <vector>

class Solution {
public:
void Build_Board(std::vector<int>& board,int n, int idx, std::vector<bool>& coloums, std::vector<bool>& positive_daigonals, std::vector<bool>& negative_daigonals, std::vector<std::vector<int>>& result){

	if (idx >= n) {
		result.push_back(board);
		return;
	}

	for (int i = 0; i < n; i++) {

		if (coloums[i] || positive_daigonals[i + idx] || negative_daigonals[(i - idx + n)]) {
			continue;
		}

		coloums[i] = true;
		positive_daigonals[i + idx] = true;
		negative_daigonals[(i - idx + n)] = true;

		board[idx] = i;
		Build_Board(board, n, idx + 1, coloums, positive_daigonals, negative_daigonals, result);

		board[idx] = -1;

		coloums[i] = false;
		positive_daigonals[i+idx] = false;
		negative_daigonals[(i - idx + n)] = false;
	}
}

std::vector<std::vector<std::string>> solveNQueens(int n) {

	std::vector<int> board(n, -1);
	std::vector<bool> coloums(n, false);
	std::vector<bool> posative_daigonals(2*n, false);
	std::vector<bool> negative_daigonals(2*n, false);
	std::vector<std::vector<int>> result;
	std::vector<std::vector<std::string>> output;

	Build_Board(board, n, 0, coloums, posative_daigonals, negative_daigonals, result);
	
	output.resize(result.size(), std::vector<std::string>(n, std::string(n, '.')));

	for (int i = 0; i < result.size(); i++) {
		for (int j = 0; j < result[0].size(); j++) {
			output[i][j][result[i][j]] = 'Q';
		}
	}
	return output;
}
};
