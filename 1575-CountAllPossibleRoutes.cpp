#include <vector>

class Solution {
public:
int Solve_Routes(std::vector<int>& nums, int idx,int fuel, int target, std::vector<std::vector<int>>& cache) {

	if (fuel < 0) return 0;
	
	if (cache[idx][fuel] != -1) return cache[idx][fuel];
	
	int sum = (idx == target) ? 1 : 0;
	int mod = int(1e9) + 7;
	for (int i = idx + 1; i < nums.size(); i++) {
		if (nums[i] - nums[idx] > fuel) break;
		sum += Solve_Routes(nums, i, fuel - (nums[i] - nums[idx]), target, cache);
		sum %= mod;
	}

	for (int i = idx - 1; i >= 0; i--) {
		if (nums[idx] - nums[i] > fuel) break;
		sum += Solve_Routes(nums, i, fuel - (nums[idx] - nums[i]), target, cache);
		sum %= mod;
	}

	cache[idx][fuel] = sum;

	return sum;
}

int countRoutes(std::vector<int>& locations, int start, int end, int fuel) {
	
	std::vector<std::vector<int>> cache(locations.size(), std::vector<int>(fuel + 1, -1));
	int low = 0;
	int high = locations.size();
	int mid = (low + high) / 2;

	start = locations[start];
	end = locations[end];

	std::sort(locations.begin(), locations.end());
	
	while (low < high) {
		if (locations[mid] == start) {
			start = mid;
			break;
		}
		if (locations[mid] < start) low = mid + 1;
		else high = mid;
		mid = (low + high) / 2;
	}

	low = 0;
	high = locations.size();
	mid = (low + high) / 2;

	while (low < high) {
		if (locations[mid] == end) {
			end = mid;
			break;
		}
		if (locations[mid] < end) low = mid + 1;
		else high = mid;
		mid = (low + high) / 2;
	}

	return Solve_Routes(locations, start, fuel, end, cache);
}
};
