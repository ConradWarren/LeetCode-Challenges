#include <vector>

class Solution {
public:
int Find_Min_Operations(std::vector<int>& arr1, std::vector<int>& arr2, int idx_1, int idx_2, int last_value, std::vector<std::vector<int>>& cache) {

	if (idx_1 >= arr1.size()) return 0;
	
	if (cache[idx_2][idx_1] != -1) return cache[idx_2][idx_1];
	
	int skips = (arr1[idx_1] > last_value) ? Find_Min_Operations(arr1, arr2, idx_1 + 1, idx_2, arr1[idx_1], cache) : int(1e5);
	
	while (idx_2 < arr2.size() && arr2[idx_2] <= last_value) {
		idx_2++;
	}

	int takes = (idx_2 < arr2.size()) ? 1 + Find_Min_Operations(arr1, arr2, idx_1 + 1, idx_2 + 1, arr2[idx_2], cache) : int(1e5);

	cache[idx_2][idx_1] = (skips < takes) ? skips : takes;

	return cache[idx_2][idx_1];
}


int makeArrayIncreasing(std::vector<int>& arr1, std::vector<int>& arr2) {

	std::vector<std::vector<int>> cache(arr2.size()+1, std::vector<int>(arr1.size(), -1));	

	std::sort(arr2.begin(), arr2.end());
	arr2.erase(std::unique(arr2.begin(), arr2.end()), arr2.end());

	int result = Find_Min_Operations(arr1, arr2, 0, 0, -1, cache);

	return (result < 1e5) ? result : -1;
}
};
