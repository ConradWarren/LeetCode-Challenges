#include <vector>

class Solution {
public:
int Count_Valid_Sets(std::vector<int>& nums, int idx, int sum, std::vector<std::vector<int>>& cache) {

	if (sum == 0) {
		return 1;
	}

	if (idx >= nums.size() || sum < 0) {
		return 0;
	}

	if (cache[idx][sum] != -1) {
		return cache[idx][sum];
	}

	int skip = Count_Valid_Sets(nums, idx + 1, sum, cache);
	int takes = Count_Valid_Sets(nums, idx + 1, sum - nums[idx], cache);

	cache[idx][sum] = (skip + takes)%(1000000007);

	return (skip + takes) % (1000000007);
}

int numberOfWays(int n, int x) {

	std::vector<int> valid_numbers;
	std::vector<std::vector<int>> cache;
	int num = 1;
	int base = 1;


	while (num <= n) {
		valid_numbers.push_back(num);
		base++;
		num = 1;
		for (int i = 0; i < x; i++) {
			num *= base;
		}
	}

	cache.resize(valid_numbers.size(), std::vector<int>(n + 1, -1));

	return Count_Valid_Sets(valid_numbers, 0, n, cache);
}
};
