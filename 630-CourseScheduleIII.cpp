#include <vector>
#include <priority_queue>

class Solution {
public:
int scheduleCourse(std::vector<std::vector<int>>& courses) {

	int current_day = 0;
	int result = 0;
	std::priority_queue<int> course_times;
	std::sort(courses.begin(), courses.end(), [](const std::vector<int>& a, const std::vector<int>& b) { return a[1] < b[1]; });

	for (int i = 0; i < courses.size(); i++) {

		if (current_day + courses[i][0] <= courses[i][1]) {
			result++;
			current_day += courses[i][0];
			course_times.push(courses[i][0]);
		}
		else if(!course_times.empty() && course_times.top() > courses[i][0]) {
			current_day += courses[i][0];
			current_day -= course_times.top();
			course_times.pop();
			course_times.push(courses[i][0]);
		}
	}

	return result;
}
};
