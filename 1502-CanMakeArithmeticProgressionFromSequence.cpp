#include <vector>

class Solution {
public:
bool canMakeArithmeticProgression(std::vector<int>& arr) {

	std::sort(arr.begin(), arr.end());

	int target = arr[1] - arr[0];

	for (int i = 1; i < arr.size() - 1; i++) {
		if (arr[i + 1] - arr[i] != target) {
			return false;
		}
	}

	return true;
}
};
