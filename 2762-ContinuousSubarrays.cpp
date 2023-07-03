#include <vector>
#include <priority_queue>

class Solution {
public:
long long continuousSubarrays(std::vector<int>& nums) {

	long long total_subarrays = ((long long)(nums.size()) * (long long)(nums.size() + 1)) / 2;
	int back_idx = 0;
	std::priority_queue<std::pair<int, int>> max_heap;
	std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> min_heap;

	for (int i = 0; i < nums.size(); i++) {

		max_heap.push({ nums[i], i });
		min_heap.push({ nums[i], i });

		while (max_heap.top().first - nums[i] > 2 || nums[i] - min_heap.top().first > 2) {

			total_subarrays -= (nums.size() - i);
			back_idx++;

			while (max_heap.top().second < back_idx) {
				max_heap.pop();
			}

			while (min_heap.top().second < back_idx) {
				min_heap.pop();
			}

		}
	}

	return total_subarrays;
}
};
