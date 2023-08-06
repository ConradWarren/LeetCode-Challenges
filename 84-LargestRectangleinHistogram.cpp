#include <vector>
#include <stack>

class Solution {
public:
int largestRectangleArea(std::vector<int>& heights) {

	std::stack<std::pair<int, int>> h_stack; 
	int largest_area = 0;
	int edge = 0;
	
	for (int i = 0; i < heights.size(); i++) {

		edge = i;

		while (!h_stack.empty() && h_stack.top().first >= heights[i]){
			edge = h_stack.top().second;
			largest_area = (largest_area > h_stack.top().first * (i - h_stack.top().second)) ? largest_area : h_stack.top().first * (i - h_stack.top().second);
			h_stack.pop();
		}

		largest_area = (largest_area > heights[i] * (i - edge + 1)) ? largest_area : heights[i] * (i - edge + 1);

		h_stack.push({ heights[i], edge });
	}

	edge = heights.size() - 1;

	while (!h_stack.empty()){
		largest_area = (largest_area > h_stack.top().first * (edge - h_stack.top().second + 1)) ? largest_area : h_stack.top().first * (edge - h_stack.top().second + 1);
		h_stack.pop();
	}

	return largest_area;
}
};
