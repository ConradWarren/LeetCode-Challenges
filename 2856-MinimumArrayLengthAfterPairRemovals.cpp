class Solution {
public:
bool Is_Valid(std::vector<int>& nums, int k) {

	if (k == 0) return true;

	std::stack<int> num_stack;

	for (int i = 0; i < k; i++) {
		num_stack.push(nums[i]);
	}

	for (int i = nums.size()-1; i >= k; i--) {

		if (num_stack.empty()) return true;

		if (num_stack.top() < nums[i]) {
			num_stack.pop();
		}
	}
	
	return num_stack.empty();
}

int minLengthAfterRemovals(std::vector<int>& nums) {

	int high = (nums.size() / 2) + 1;
	int low = 0;
	int mid = (high + low) / 2;


	while (low < high){

		if (Is_Valid(nums, mid)) {
			low = mid + 1;
		}
		else {
			high = mid;
		}

		mid = (low + high) / 2;
	}


	return nums.size() - ((low - 1) * 2);
}
};
