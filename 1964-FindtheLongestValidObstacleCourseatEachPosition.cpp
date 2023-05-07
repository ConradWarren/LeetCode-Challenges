#include <vector>

std::vector<int> longestObstacleCourseAtEachPosition(std::vector<int>& obstacles) {

	if (obstacles.size() == 1) return { 1 };
	
	std::vector<int> result(obstacles.size(), 0);
	int max_length = 2;
	std::vector<int> min_height_for_length(obstacles.size() + 1, 0);
	
	result[0] = 1;
	min_height_for_length[1] = 0;
	min_height_for_length[2] = obstacles[0];

	for (int i = 1; i < obstacles.size(); i++) {

		if (obstacles[i] >= min_height_for_length[max_length]) {
			result[i] = max_length;
			max_length++;
			min_height_for_length[max_length] = obstacles[i];
		}
		else {
			int low = 1;
			int high = max_length;
			int mid = (low + high) / 2;
			while (low < high) {

				if (min_height_for_length[mid] <= obstacles[i]) low = mid + 1;
				
				else high = mid;

				mid = (low + high) / 2;
			}

			result[i] = low - 1;
			min_height_for_length[low] = obstacles[i];
		}
	}
	return result;
}
