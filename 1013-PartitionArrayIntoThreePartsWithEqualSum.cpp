#include <vector>

class Solution {
public:
bool canThreePartsEqualSum(std::vector<int>& arr) {


	int total = std::accumulate(arr.begin(), arr.end(), 0);

	if (total % 3) return false;
	
	int target = total / 3;
	int rolling_sum = 0;
	int target_hit_count = 0;

	for (int i = 0; i < arr.size(); i++) {

		rolling_sum += arr[i];

		if (rolling_sum == target) {
			target_hit_count++;
			rolling_sum = 0;
		}

		if (target_hit_count == 2 && i != arr.size()-1) {
			if (std::accumulate(arr.begin() + i + 1, arr.end(), 0) == target) {
				return true;
			}
			else {
				return false;
			}
		}

	}

	return false;
}
};
