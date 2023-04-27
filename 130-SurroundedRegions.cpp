#include <vector>

class Solution {
public:
void Depth_First_Search(std::vector<std::vector<char>>& board, std::vector<std::vector<bool>>& should_be_x, int x_pos, int y_pos) {

	if (x_pos < 0 || y_pos < 0 || y_pos >= board.size() || x_pos >= board[0].size()) {
		return;
	}
	if (board[y_pos][x_pos] == 'X' || !should_be_x[y_pos][x_pos]) {
		return;
	}
	should_be_x[y_pos][x_pos] = false;

	Depth_First_Search(board, should_be_x, x_pos+1, y_pos);
	Depth_First_Search(board, should_be_x, x_pos, y_pos+1);
	Depth_First_Search(board, should_be_x, x_pos-1, y_pos);
	Depth_First_Search(board, should_be_x, x_pos, y_pos-1);
}

void solve(std::vector<std::vector<char>>& board) {

	std::vector<std::vector<bool>> should_be_x(board.size(), std::vector<bool>(board[0].size(), true));

	for (int i = 0; i < board[0].size(); i++) {

		if (board[0][i] == 'O') Depth_First_Search(board, should_be_x, i, 0);
		
		if (board.back()[i] == 'O') Depth_First_Search(board, should_be_x, i, board.size()-1);
		
	}

	for (int i = 0; i < board.size(); i++) {

		if (board[i][0] == 'O') Depth_First_Search(board, should_be_x, 0, i);
		
		if (board[i].back() == 'O') Depth_First_Search(board, should_be_x, board[0].size()-1, i);
		
	}

	for (int i = 0; i < board.size(); i++) {
		for (int j = 0; j < board[i].size(); j++) {
			if (should_be_x[i][j]) board[i][j] = 'X';
		}
	}

}
};
