#include <unordered_map>

class Solution {
public:
int longestConsecutive(std::vector<int>& nums) {

	std::unordered_map<int, int> num_map;

	for (int i = 0; i < nums.size(); i++) {
		num_map[nums[i]] = false;
	}

	int best = 0;
	for (auto& num : num_map) {

		if (num.second) continue;

		int idx = 1;
		int current_streak = 1;
		while (num_map.find(num.first + idx) != num_map.end()) {
			
			if (num_map[num.first + idx]) {
				current_streak += num_map[num.first + idx];
				break;
			}
			num_map[num.first+idx] = 1;
			idx++;
			current_streak++;
		}
		best = max(current_streak, best);

		num_map[num.first] = current_streak;

	}

	return best;
}
};
