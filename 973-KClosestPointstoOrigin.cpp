#include <vector>

class Solution {
public:
std::vector<std::vector<int>> kClosest(std::vector<std::vector<int>>& points, int k) {

	std::vector<std::pair<int, int>> scored_points(points.size());
	std::vector<std::vector<int>> result(k);
	

	for (int i = 0; i < points.size(); i++) {
		scored_points[i].first = (points[i][0] * points[i][0]) + (points[i][1] * points[i][1]);
		scored_points[i].second = i;
	}

	std::sort(scored_points.begin(), scored_points.end());

	for (int i = 0; i < k; i++) {
		result[i] = points[scored_points[i].second];
	}

	return result;
}
};
