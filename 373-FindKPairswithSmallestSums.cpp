#include <vector>
#include <priority_queue>

class Solution {
public:
std::vector<std::vector<int>> kSmallestPairs(std::vector<int>& nums1, std::vector<int>& nums2, int k) {

	std::priority_queue<std::vector<int>, std::vector<std::vector<int>>, std::greater<std::vector<int>>> min_heap;

	std::vector<std::vector<int>> result(k, std::vector<int>(2));

	int idx = 0;

	min_heap.push({ nums1[0] + nums2[0],0, 0 });

	while (idx < k && !min_heap.empty()) {

		int i = min_heap.top()[1];
		int j = min_heap.top()[2];

		result[idx][0] = nums1[i];
		result[idx][1] = nums2[j];

		min_heap.pop();

		if (i == j) {
			if (i + 1 < nums1.size()) {
				min_heap.push({ nums1[i + 1] + nums2[j], i + 1, j });
			}
			if (j + 1 < nums2.size()) {
				min_heap.push({ nums1[i] + nums2[j + 1], i, j + 1 });
			}
			if (i + 1 < nums1.size() && j + 1 < nums2.size()) {
				min_heap.push({ nums1[i + 1] + nums2[j + 1], i + 1, j + 1 });
			}
		}
		else if (i > j && i+1 < nums1.size()) {
			min_heap.push({ nums1[i + 1] + nums2[j], i + 1, j });
		}
		else if(j > i && j+1 <nums2.size()){
			min_heap.push({ nums1[i] + nums2[j + 1], i, j + 1 });
		}

		idx++;
	}

	if (idx < result.size()) {
		result.resize(idx);
	}

	return result;
}
};
