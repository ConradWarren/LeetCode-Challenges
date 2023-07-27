#include <vector>

class Solution {
public:
int minSpeedOnTime(std::vector<int>& dist, double hour) {

	
	int high = 1e7 + 1;
	int low = 1;
	int mid = (low + high) / 2;

	while (low < high) {


		double total_time = 0;
		
		for (int i = 0; i < dist.size(); i++) {

			total_time += (double(dist[i]) / double(mid));
			
			if (i != dist.size() - 1) {
				total_time = std::ceil(total_time);
			}
		}
		
		if (total_time <= hour) {
			high = mid;
		}
		else {
			low = mid + 1;
		}

		mid = (low + high) / 2;
	}


	return (high == 1e7+1) ? -1 : high;
}
};
