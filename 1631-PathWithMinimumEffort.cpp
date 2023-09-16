class Solution {
public:
bool Can_Pass(std::vector<std::vector<int>>& heights, int limit, std::vector<std::vector<int>>& cache) {

	std::vector<std::pair<int, int>> directions = { {0,1},{1,0},{-1,0},{0,-1} };
	std::queue<int> node_queue;
	int y = 0, x = 0, temp_y = 0, temp_x = 0;
	

	node_queue.push(0);
	cache[0][0] = limit;

	while (!node_queue.empty()) {

		y = node_queue.front() / heights[0].size();
		x = node_queue.front() % heights[0].size();

		if (y + 1 == heights.size() && x + 1 == heights[0].size()) {
			return true;
		}


		node_queue.pop();

		for (int i = 0; i < directions.size(); i++) {

			temp_y = y + directions[i].first;
			temp_x = x + directions[i].second;

			if (temp_y < 0 || temp_x < 0 || temp_y >= heights.size() || temp_x >= heights[0].size()) {
				continue;
			}

			if (cache[temp_y][temp_x] == limit) {
				continue;
			}

			if (std::abs(heights[y][x] - heights[temp_y][temp_x]) <= limit) {
				cache[temp_y][temp_x] = limit;
				node_queue.push((temp_y * heights[0].size()) + temp_x);
			}
		}

	}

	return false;
}

int minimumEffortPath(std::vector<std::vector<int>>& heights) {

	int low = 0;
	int high = int(1e6);
	int mid = (low + high) / 2;
	std::vector<std::vector<int>> cache(heights.size(), std::vector<int>(heights[0].size(), -1));

	while (low < high){

		if (Can_Pass(heights, mid, cache)) {
			high = mid;
		}
		else {
			low = mid + 1;
		}
		mid = (low + high) / 2;
	}

	return high;
}
};
