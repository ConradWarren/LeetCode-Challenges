#include <vector>

class Solution {
public:
bool Is_Valid(std::vector<int>& batteries, long long target, int n) {

	long long sum = 0;

	for (int i = 0; i < batteries.size(); i++) {
		sum += (target < batteries[i]) ? target : batteries[i];
	}
	return sum >= ((long long)(n)*target);
}

long long maxRunTime(int n, std::vector<int>& batteries) {

	long long low = 1;
	long long high = std::accumulate(batteries.begin(), batteries.end(), 0LL)+1;
	long long mid = (low + high) / 2;

	while (low < high) {

		if (Is_Valid(batteries, mid, n)) {
			low = mid+1;
		}
		else {
			high = mid;
		}
		mid = (low + high) / 2;
	}

	return low-1;
}
};
