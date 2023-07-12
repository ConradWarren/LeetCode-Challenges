#include <vector>

class Solution {
public:
int minimumDifference(std::vector<int>& nums) {

	int n = nums.size() / 2;
	int total = 0;
	int idx = 0;
	int best = INT_MAX;

	std::vector<std::vector<int>> first_half_sums(n + 1);
	
	for (int i = ((1 << n) - 1); i >= 0; i--) {

		total = 0;
		idx = 0;
		for (int j = 0; j < n; j++) {
			if (i & (1 << j)) {
				idx++;
				total += nums[j];
			}
			else {
				total -= nums[j];
			}
		}
		first_half_sums[idx].push_back(total);
	}

	for (int i = 0; i <= n; i++) {
		std::sort(first_half_sums[i].begin(), first_half_sums[i].end());
	}

	for (int i = (1 << n) - 1; i >= 0; i--) {

		total = 0;
		idx = 0;

		for (int j = 0; j < n; j++) {
			if (i & (1 << j)) {
				idx++;
				total += nums[j + n];
			}
			else {
				total -= nums[j + n];
			}
		}

		auto p = std::lower_bound(first_half_sums[idx].begin(), first_half_sums[idx].end(), total);
		if (p != first_half_sums[idx].end()) {
			best = (best < std::abs(total - *p)) ? best : std::abs(total - *p);
		}
		if (p != first_half_sums[idx].begin()) {
			p--;
			best = (best < std::abs(total - *p)) ? best : std::abs(total - *p);
		}
	}
	return best;
}
};
