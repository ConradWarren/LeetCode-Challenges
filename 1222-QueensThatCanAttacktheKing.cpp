#include <vector>

class Solution {
public:
std::vector<std::vector<int>> queensAttacktheKing(std::vector<std::vector<int>>& queens, std::vector<int>& king) {

	std::vector<std::vector<bool>> board(8, std::vector<bool>(8, false));
	std::vector<std::vector<int>> result;


	for (int i = 0; i < queens.size(); i++) {
		board[queens[i][0]][queens[i][1]] = true;
	}

	for (int i = king[1] + 1; i < 8; i++) {
		if (board[king[0]][i]) {
			result.push_back({king[0], i});
			break;
		}
	}
	for (int i = king[1] - 1; i >= 0; i--) {
		if (board[king[0]][i]) {
			result.push_back({ king[0], i });
			break;
		}
	}
	for (int i = king[0] + 1; i < 8; i++) {
		if (board[i][king[1]]) {
			result.push_back({ i, king[1]});
			break;
		}
	}
	for (int i = king[0] - 1; i >= 0; i--) {
		if (board[i][king[1]]) {
			result.push_back({ i, king[1] });
			break;
		}
	}

	for (int i = king[1] + 1, j = king[0] + 1; i < 8 && j < 8; i++, j++) {
		if (board[j][i]) {
			result.push_back({j, i});
			break;
		}
	}
	
	for (int i = king[1] - 1, j = king[0] - 1; i >= 0 && j >= 0; i--, j--) {
		if (board[j][i]) {
			result.push_back({ j, i });
			break;
		}
	}
	for (int i = king[1] + 1, j = king[0] - 1; i < 8 && j >= 0; i++, j--) {
		if (board[j][i]) {
			result.push_back({ j, i });
			break;
		}
	}
	for (int i = king[1] - 1, j = king[0] + 1; i >=0  && j < 8; i--, j++) {
		if (board[j][i]) {
			result.push_back({ j, i });
			break;
		}
	}
	

	return result;
}
};
