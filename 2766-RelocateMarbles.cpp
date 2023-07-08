#include <vector>
#include <unordered_set>

class Solution {
public:
std::vector<int> relocateMarbles(std::vector<int>& nums, std::vector<int>& moveFrom, std::vector<int>& moveTo) {

	std::unordered_set<int> marble_postions;
	std::vector<int> result;

	for (int i = 0; i < nums.size(); i++) {
		marble_postions.insert(nums[i]);
	}

	for (int i = 0; i < moveFrom.size(); i++) {

		if (marble_postions.find(moveFrom[i]) != marble_postions.end()) {
			marble_postions.erase(moveFrom[i]);
			marble_postions.insert(moveTo[i]);
		}
	}

	for (auto& num : marble_postions) {
		result.push_back(num);
	}

	std::sort(result.begin(), result.end());

	return result;
}
};
