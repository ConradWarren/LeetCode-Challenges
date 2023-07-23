#include <vector>

class Solution {
public:
long long maxArrayValue(std::vector<int>& nums) {
	
	std::priority_queue<long long> pq;
	

	for (int i = nums.size() - 1; i >= 0; i--) {

		if (pq.empty() || nums[i] > pq.top()) {
			pq.push(nums[i]);
		}
		else {
			long long temp = pq.top();
			pq.pop();
			pq.push(nums[i] + temp);
		}
	}

	return pq.top();
}
};
