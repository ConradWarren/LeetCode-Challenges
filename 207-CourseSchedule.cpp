class Solution {
public:
bool canFinish(int numCourses, std::vector<std::vector<int>>& prerequisites) {

	std::vector<int> n_degree(numCourses, 0);
	std::vector<std::vector<int>> graph(numCourses);
	std::vector<bool> completed_course(numCourses, false);
	std::queue<int> course_queue;

	int course_count = 0;
	int current_course = 0;

	for (int i = 0; i < prerequisites.size(); i++) {
		graph[prerequisites[i][0]].push_back(prerequisites[i][1]);
		n_degree[prerequisites[i][1]]++;
	}

	for (int i = 0; i < n_degree.size(); i++) {
		if (n_degree[i] == 0) {
			course_queue.push(i);
			course_count++;
			completed_course[i] = true;
		}
	}

	

	while (!course_queue.empty()) {

		current_course = course_queue.front();
		course_queue.pop();

		for (int i = 0; i < graph[current_course].size(); i++) {

			if (completed_course[graph[current_course][i]]) {
				
				continue;
			}

			n_degree[graph[current_course][i]]--;

			if (n_degree[graph[current_course][i]] == 0) {
				completed_course[graph[current_course][i]] = true;
				course_queue.push(graph[current_course][i]);
				course_count++;
			}
		}
	}

	return (course_count >= numCourses);
}
};
