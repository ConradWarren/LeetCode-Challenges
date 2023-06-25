#include <vector>
#include <stack>

class Solution {
public:
std::vector<int> survivedRobotsHealths(std::vector<int>& positions, std::vector<int>& healths, std::string directions) {

	std::vector<std::pair<int, int>> sortable_positions(positions.size());
	std::vector<int> result(healths.size());
	std::stack<std::pair<int, int>> robot_stack;
	int current_direction = 0;
	int idx = 0;

	for (int i = 0; i < positions.size(); i++) {
		sortable_positions[i].first = positions[i];
		sortable_positions[i].second = i;
	}

	std::sort(sortable_positions.begin(), sortable_positions.end());

	for (int i = 0; i < sortable_positions.size(); i++) {

		current_direction = (directions[sortable_positions[i].second] == 'R') ? 1 : 0;

		while (!robot_stack.empty() && robot_stack.top().first == 1 && current_direction == 0) {
			
			if (healths[robot_stack.top().second] > healths[sortable_positions[i].second]) {
				healths[robot_stack.top().second]--;
				healths[sortable_positions[i].second] = 0;
				break;
			}
			else if (healths[robot_stack.top().second] < healths[sortable_positions[i].second]) {
				healths[sortable_positions[i].second]--;
				healths[robot_stack.top().second] = 0;
				robot_stack.pop();
			}
			else {
				healths[robot_stack.top().second] = 0;
				healths[sortable_positions[i].second] = 0;
				robot_stack.pop();
				break;
			}
		}

		if (healths[sortable_positions[i].second] != 0) {
			robot_stack.push({ current_direction, sortable_positions[i].second });
		}
	}

	for (int i = 0; i < healths.size(); i++) {
		if (healths[i] != 0) {
			result[idx] = healths[i];
			idx++;
		}
	}

	result.resize(idx);

	return result;
}
};
