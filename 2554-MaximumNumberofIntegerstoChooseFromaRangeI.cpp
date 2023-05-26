#include <vector>
#include <unordered_set>

class Solution {
public:
int maxCount(std::vector<int>& banned, int n, int maxSum) {

	int idx = 1;
	int sum = 0;
	int count = 0;
	std::unordered_set<int> banned_nums;

	for (int i = 0; i < banned.size(); i++) {
		banned_nums.insert(banned[i]);
	}

	while (idx <= n && sum + idx <= maxSum) {

		if (banned_nums.find(idx) == banned_nums.end()) {
			sum += idx;
			count++;
		}
		idx++;
	}
	return count;
}
};
