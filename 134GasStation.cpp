#include <vector>
#include <numeric>

class Solution {
public:
int canCompleteCircuit(std::vector<int>& gas, std::vector<int>& cost) {

	int n = gas.size();
	std::vector<int> off_set(n);
	for (int i = 0; i < n; i++) {
		off_set[i] = gas[i] - cost[i];
	}
	
	if (std::accumulate(off_set.begin(), off_set.end(), 0) < 0) {
		return -1;
	}

	for (int i = 0; i < n; i++) {
		
		if (off_set[i] < 0) {
			continue;
		}

		int gas = 0;
		bool failed_flag = false;
		for (int j = i; j < n; j++) {
			gas += off_set[j];
			if (gas < 0) {
				i = j - 1;
				failed_flag = true;
				break;
			}
		}

		if (!failed_flag) {
			return i;
		}
	}

	return -1;
}
};
