#include <vector>

class Solution {
public:
int Find_Max(std::vector<std::vector<int>>& events, int k, int idx,int last_valid, std::vector<std::vector<int>>& cache) {

	if (idx >= events.size()) {
		return 0;
	}

	if (k == 0) {
		return 0;
	}

	if (last_valid >= events[idx][0]) {
		return Find_Max(events, k, idx + 1, last_valid, cache);
	}

	if (cache[idx][k] != -1) {
		return cache[idx][k];
	}

	int skips = Find_Max(events, k, idx + 1, last_valid, cache);

	int takes = events[idx][2] + Find_Max(events, k - 1, idx + 1, events[idx][1], cache);

	cache[idx][k] = (skips > takes) ? skips : takes;

	return cache[idx][k];
}


int maxValue(std::vector<std::vector<int>>& events, int k) {

	std::sort(events.begin(), events.end());

	std::vector<std::vector<int>> cache(events.size(), std::vector<int>(k + 1, -1));

	return Find_Max(events, k, 0, -1, cache);
}
};
