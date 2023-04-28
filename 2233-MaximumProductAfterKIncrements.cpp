#include <vector>

class Solution {
public:
int maximumProduct(std::vector<int>& nums, int k) {

	std::priority_queue<int, std::vector<int>, std::greater<int>> min_heap(nums.begin(), nums.end());
	long long max_product = 1;
	int num = 0;
	
	while (k > 0) {
		num = min_heap.top();
		min_heap.push(num+1);
		min_heap.pop();
		k--;
	}

	while (!min_heap.empty()) {
		max_product *= min_heap.top();
		max_product %= 1000000007;
		min_heap.pop();
	}

	return int(max_product);
}
};
