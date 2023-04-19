
class Solution {
public:
int numRookCaptures(std::vector<std::vector<char>>& board) {

	int rook_y_pos = -1;
	int rook_x_pos = -1;
	int total_captures = 0;

	for (int i = 0; i < board.size(); i++) {
		for (int j = 0; j < board[i].size(); j++) {
			if (board[i][j] == 'R') {
				rook_y_pos = i;
				rook_x_pos = j;
				break;
			}
		}
	}

	int temp_pos = rook_x_pos + 1;
	while (temp_pos < 8) {
		if (board[rook_y_pos][temp_pos] == 'p') {
			total_captures++;
			break;
		}
		else if (board[rook_y_pos][temp_pos] == 'B') {
			break;
		}
		temp_pos++;
	}
	temp_pos = rook_x_pos - 1;
	while (temp_pos >= 0) {
		if (board[rook_y_pos][temp_pos] == 'p') {
			total_captures++;
			break;
		}
		else if (board[rook_y_pos][temp_pos] == 'B') {
			break;
		}
		temp_pos--;
	}
	temp_pos = rook_y_pos - 1;
	while (temp_pos >= 0) {
		if (board[temp_pos][rook_x_pos] == 'p') {
			total_captures++;
			break;
		}
		else if (board[temp_pos][rook_x_pos] == 'B') {
			break;
		}
		temp_pos--;
	}
	temp_pos = rook_y_pos + 1;
	while (temp_pos < 8) {
		if (board[temp_pos][rook_x_pos] == 'p') {
			total_captures++;
			break;
		}
		else if (board[temp_pos][rook_x_pos] == 'B') {
			break;
		}
		temp_pos++;
	}
	return total_captures;
}
};
