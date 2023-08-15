#include <vector>

class Solution {
public:
int trap(std::vector<int>& height) {

	int edge = height.front();
	int current = 0;
	int total = 0;
		
	for (int i = 1; i < height.size(); i++) {
		if (height[i] >= edge) {
			total += current;
			current = 0;
			edge = height[i];
		}
		else {
			current += edge - height[i];
		}
	}

	current = 0;
	edge = height.back();

	for (int i = height.size() - 2; i >= 0; i--) {
		if (height[i] > edge) {
			total += current;
			current = 0;
			edge = height[i];
		}
		else {
			current += edge - height[i];
		}
	}

	return total;
}
};
