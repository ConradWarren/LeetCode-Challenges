#include <vector>
#include <priority_queue>

long long maxScore(std::vector<int>& nums1, std::vector<int>& nums2, int k) {

	std::vector<std::pair<int, int>> sortable_nums(nums1.size());
	std::priority_queue<int, std::vector<int>, std::greater<int>> min_heap;
	long long sum = 0;
	long long score = 0;

	for (int i = 0; i < nums1.size(); i++) {
		sortable_nums[i].first = nums2[i];
		sortable_nums[i].second = nums1[i];
	}

	std::sort(sortable_nums.rbegin(), sortable_nums.rend());

	for (int i = 0; i < k; i++) {
		min_heap.push(sortable_nums[i].second);
		sum += sortable_nums[i].second;
	}

	score = sortable_nums[k - 1].first * sum;

	for (int i = k; i < sortable_nums.size(); i++) {
		sum -= min_heap.top();
		min_heap.pop();
		min_heap.push(sortable_nums[i].second);
		sum += sortable_nums[i].second;
		score = (score > sum * sortable_nums[i].first) ? score : sortable_nums[i].first * sum;
	}
	
	return score;
}
