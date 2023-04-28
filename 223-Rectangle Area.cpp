class Solution {
public:
int Calculate_Intersection(int a_point_1, int a_point_2, int b_point_1, int b_point_2) {

	int begin = (a_point_1 > b_point_1) ? a_point_1 : b_point_1;
	int end = (a_point_2 < b_point_2) ? a_point_2 : b_point_2;

	if (begin > end) return 0;
	
	return end - begin;
}

int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {

	int area_1 = (ax2 - ax1) * (ay2 - ay1);
	int area_2 = (bx2 - bx1) * (by2 - by1);

	int intersection_1 = Calculate_Intersection(ax1, ax2, bx1, bx2);
	int intersection_2 = Calculate_Intersection(ay1, ay2, by1, by2);

	return area_1 + area_2 - (intersection_1 * intersection_2);
}
};
