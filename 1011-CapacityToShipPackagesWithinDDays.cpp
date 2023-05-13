#include <vector>

class Solution {
public:
bool Is_Possible(std::vector<int>& weights, int days, int capacity) {

	int sum = 0;
	for (int i = 0; i < weights.size(); i++) {

		if (sum + weights[i] <= capacity) sum += weights[i];
		
		else {
			days--;
			sum = weights[i];
			if (days == 0) return false;
		}
	}

	return true;
}


int shipWithinDays(std::vector<int>& weights, int days) {

	int high = std::accumulate(weights.begin(), weights.end(), 0);
	int low = 0;
	int mid = 0;

	for (int i = 0; i < weights.size(); i++) {
		low = (low > weights[i]) ? low : weights[i];
	}

	mid = (low + high) / 2;

	while (low < high) {

		if (Is_Possible(weights, days, mid)) high = mid;
		
		else low = mid + 1;
		
		mid = (low + high) / 2;
	}

	return high;
}
};
