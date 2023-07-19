#include <vector>

class Solution {
public:
int eraseOverlapIntervals(std::vector<std::vector<int>>& intervals) {

	int result = 0;
	int last_edge = INT_MIN;
	std::sort(intervals.begin(), intervals.end());

	for (int i = 0; i < intervals.size(); i++) {

		if (intervals[i][0] >= last_edge) {
			last_edge = intervals[i][1];
		}
		else {
			result++;
			last_edge = (last_edge < intervals[i][1]) ? last_edge : intervals[i][1];
		}
	}
	return result;
}
};
