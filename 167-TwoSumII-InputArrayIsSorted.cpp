#include <vector>

class Solution {
public:
std::vector<int> twoSum(std::vector<int>& numbers, int target) {

	int low = 0;
	int high = numbers.size() - 1;
	int sum = numbers[low] + numbers[high];
	while (low < high) {

		if (sum == target) {
			return { low+1, high+1 };
		}

		if (sum < target) {
			low++;
		}
		else {
			high--;
		}
		sum = numbers[low] + numbers[high];
	}

	return {};
}
};
