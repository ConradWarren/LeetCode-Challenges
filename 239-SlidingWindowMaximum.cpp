#include <vector>
#include <priority_queue>

class Solution {
public:
std::vector<int> maxSlidingWindow(std::vector<int>& nums, int k) {

	std::priority_queue<std::pair<int, int>> pq;
	std::vector<int> result(nums.size() - k + 1);

	for (int i = 0; i < k; i++) {
		pq.push({ nums[i], i });
	}

	result[0] = pq.top().first;

	for (int i = k; i < nums.size(); i++) {
		
		pq.push({ nums[i], i });

		while (pq.top().second <= i - k) {
			pq.pop();
		}

		result[i - k + 1] = pq.top().first;
	}
	return result;
}
};
