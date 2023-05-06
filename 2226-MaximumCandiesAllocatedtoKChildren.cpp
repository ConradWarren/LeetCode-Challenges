#include <vector>

class Solution {
public:
bool Can_Split(std::vector<int>& candies, long long k, int group_size) {

	if (group_size == 0) return true;
	
	for (int i = 0; i < candies.size(); i++) {
		k -= candies[i] / group_size;

		if (k <= 0) return true;
	}
	return false;
}

int maximumCandies(std::vector<int>& candies, long long k) {
	
	long long min_group_size = std::accumulate(candies.begin(), candies.end(), 0ULL) / k;
	int low = 0;
	int high = int(min_group_size)+1;

	int mid = (low + high) / 2;

	while (low < high) {

		if (Can_Split(candies, k, mid)) {
			low = mid + 1;
		}
		else {
			high = mid;
		}
		mid = (low + high) / 2;
	}
	return low-1;
}
};
