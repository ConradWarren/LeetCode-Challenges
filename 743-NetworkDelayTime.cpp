#include <vector>
#include <priority_queue>

class Solution {
public:
int networkDelayTime(std::vector<std::vector<int>>& times, int n, int k) {

	std::vector<std::vector<std::pair<int, int>>> graph(n+1);
	std::vector<int> time_taken(n+1, INT_MAX);
	std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> min_heap;
	int node = 0;
	int current_time = 0;
	int result = -1;


	for (int i = 0; i < times.size(); i++) {
		graph[times[i][0]].push_back({ times[i][1], times[i][2] }); //destination, time
	}

	min_heap.push({0,k});
	time_taken[k] = 0;

	while (!min_heap.empty()){

		
		node = min_heap.top().second;
		current_time = min_heap.top().first;
		
		

		min_heap.pop();

		for (int i = 0; i < graph[node].size(); i++) {
			
			if (time_taken[graph[node][i].first] > current_time + graph[node][i].second) {
				time_taken[graph[node][i].first] = current_time + graph[node][i].second;
				min_heap.push({ time_taken[graph[node][i].first] ,graph[node][i].first });
			}
		}
	}
	
	for (int i = 1; i < time_taken.size(); i++) {
		result = (result > time_taken[i]) ? result : time_taken[i];
	}
	return (result == INT_MAX) ? -1 : result;
}
};
