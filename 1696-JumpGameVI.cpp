#include <vector>
#include <priority_queue>

class Solution {
public:
int maxResult(std::vector<int>& nums, int k) {

	std::vector<int> idx_max(nums.size());
	std::priority_queue<std::pair<int, int>> pq;

	idx_max[nums.size() - 1] = nums.back();
	pq.push({ nums.back(), nums.size() - 1 });

	for (int i = nums.size() - 2; i >= 0; i--) {

		while (pq.top().second > i + k) {
			pq.pop();
		}

		idx_max[i] = nums[i] + pq.top().first;
		pq.push({ idx_max[i], i });
	}

	return idx_max.front();
}
};
