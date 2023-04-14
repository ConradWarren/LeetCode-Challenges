#include <vector>

bool validMountainArray(std::vector<int>& arr) {
	
	if (arr.size() < 3) return false;

	bool increasing_flag = true;

	if (arr[0] < arr[1]) return false;

	for (int i = 0; i < arr.size() - 1; i++) {

		if (arr[i] == arr[i + 1]) return false;

		if (increasing_flag && arr[i] > arr[i+1]) increasing_flag = false;
		else if (!increasing_flag && arr[i] < arr[i+1]) return false;
	}

	return (increasing_flag) ? false : true;
}
