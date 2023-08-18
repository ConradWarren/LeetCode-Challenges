#include <vector>

class Solution {
public:
int maxArea(std::vector<int>& height) {

	int left_edge = 0;
	int right_edge = height.size() - 1;
	int result = 0;

	while (left_edge < right_edge) {

		if (height[left_edge] < height[right_edge]) {
			result = (result > height[left_edge] * (right_edge - left_edge)) ? result : height[left_edge] * (right_edge - left_edge);
			left_edge++;
		}
		else if (height[left_edge] > height[right_edge]) {
			result = (result > height[right_edge] * (right_edge - left_edge)) ? result : height[right_edge] * (right_edge - left_edge);
			right_edge--;
		}
		else {
			result = (result > height[left_edge] * (right_edge - left_edge)) ? result : height[left_edge] * (right_edge - left_edge);
			left_edge++;
			right_edge--;
		}
	}

	return result;
}
};
