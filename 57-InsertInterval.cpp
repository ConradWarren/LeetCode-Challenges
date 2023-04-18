#include <vector>

class Solution {
public:
std::vector<std::vector<int>> insert(std::vector<std::vector<int>>& intervals, std::vector<int>& newInterval) {

	std::vector<std::vector<int>> result;

	for (int i = 0; i < intervals.size(); i++) {

		if (newInterval[1] < intervals[i][0]) {

			result.push_back(newInterval);
			for (; i < intervals.size(); i++) {
				result.push_back(intervals[i]);
			}
			return result;
		}
		else if (newInterval[0] > intervals[i][1]) {
			result.push_back(intervals[i]);
		}
		else {

			newInterval[0] = min(newInterval[0], intervals[i][0]);
			newInterval[1] = max(newInterval[1], intervals[i][1]);

		}

	}

	result.push_back(newInterval);

	return result;
}
};
