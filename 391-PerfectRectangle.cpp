#include <set>
#include <vector>

class Solution {
public:
bool isRectangleCover(std::vector<std::vector<int>>& rectangles) {

	int lowest_point = rectangles[0][1];
	int farthest_left_point = rectangles[0][0];

	int highest_point = rectangles[0][3];
	int farthest_right_point = rectangles[0][2];

	std::set<std::pair<int, int>> Set;
	long long Area = 0;

	for (int i = 0; i < rectangles.size(); i++) {

		if (rectangles[i][1] < lowest_point) {
			lowest_point = rectangles[i][1];
		}

		if (rectangles[i][0] < farthest_left_point) {
			farthest_left_point = rectangles[i][0];
		}

		if (rectangles[i][3] > highest_point) {
			highest_point = rectangles[i][3];
		}

		if (rectangles[i][2] > farthest_right_point) {
			farthest_right_point = rectangles[i][2];
		}

		std::pair<int, int> point_1 = { rectangles[i][0], rectangles[i][1] };
		std::pair<int, int> point_2 = { rectangles[i][0], rectangles[i][3] };
		std::pair<int, int> point_3 = { rectangles[i][2], rectangles[i][3] };
		std::pair<int, int> point_4 = { rectangles[i][2], rectangles[i][1] };

		if (Set.find(point_1) == Set.end()) Set.insert(point_1);
		else Set.erase(point_1);
		
		if (Set.find(point_2) == Set.end()) Set.insert(point_2);
		else Set.erase(point_2);
		
		if (Set.find(point_3) == Set.end()) Set.insert(point_3);
		else Set.erase(point_3);
		
		if (Set.find(point_4) == Set.end()) Set.insert(point_4);
		else Set.erase(point_4);

		Area += ((long long)(rectangles[i][2] - rectangles[i][0]) * (long long)(rectangles[i][3] - rectangles[i][1]));
	}
	
	if (Set.size() != 4) return false;

	auto point = Set.begin();
	if ((*point).first != farthest_left_point || (*point).second != lowest_point) return false;
	point++;
	point++;
	point++;
	if ((*point).first != farthest_right_point || (*point).second != highest_point) return false;
	
	if (Area != (long long)(farthest_right_point - farthest_left_point) * (long long)(highest_point - lowest_point)) return false;
	
	return true;
}
};
