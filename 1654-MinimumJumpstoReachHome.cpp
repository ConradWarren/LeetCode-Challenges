#include <vector>

class Solution {
public:
void Solve_Min_Jumps(std::vector<int>& positions, int a, int b,int x, int current_position,int jumps, bool jump_back_flag) {

	if (current_position < 0 || current_position >= positions.size()) {
		return;
	}

	if (jumps >= positions[current_position]) {
		return;
	}

	positions[current_position] = jumps;

	if (current_position == x) {
		return;
	}

	if (!jump_back_flag) {
		Solve_Min_Jumps(positions, a, b, x, current_position - b, jumps + 1, true);
	}

	Solve_Min_Jumps(positions, a, b, x, current_position + a,jumps+1, false);

	return;
}

int minimumJumps(std::vector<int>& forbidden, int a, int b, int x) {

	std::vector<int> positions(6000, INT_MAX);
	for (int i = 0; i < forbidden.size(); i++) {
		positions[forbidden[i]] = -1;
	}

	Solve_Min_Jumps(positions, a, b, x, 0, 0, true);
	
	return (positions[x] == INT_MAX) ? -1: positions[x];
}
};
