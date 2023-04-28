#include <vector>

class Solution {
public:

bool Is_Intersection(int a_point_1, int a_point_2, int b_point_1, int b_point_2) {

	int begin = (a_point_1 > b_point_1) ? a_point_1 : b_point_1;
	int end = (a_point_2 < b_point_2) ? a_point_2 : b_point_2;

	if (begin >= end) return false;

	return true;
}
bool isRectangleOverlap(std::vector<int>& rec1, std::vector<int>& rec2) {

	if (Is_Intersection(rec1[0], rec1[2], rec2[0], rec2[2]) && Is_Intersection(rec1[1], rec1[3], rec2[1], rec2[3])) {
		return true;
	}

	return false;
}
};
