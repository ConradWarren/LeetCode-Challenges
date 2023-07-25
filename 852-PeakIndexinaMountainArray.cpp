#include <vector>

class Solution {
public:
int peakIndexInMountainArray(std::vector<int>& arr) {

	int low = 1;
	int high = arr.size()-1;
	int mid = (low + high) / 2;

	while (low < high) {

		if (arr[mid] > arr[mid - 1] && arr[mid] > arr[mid + 1]) {
			return mid;
		}

		if (arr[mid] > arr[mid - 1]) {
			low = mid + 1;
		}
		else {
			high = mid;
		}
		mid = (low + high) / 2;
	}
	return low;
}
};
