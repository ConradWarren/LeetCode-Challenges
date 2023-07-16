#include <vector>
#include <priority_queue>

class Solution {
public:
int minimumIndex(std::vector<int>& nums) {
    
    if (nums.size() == 1) {
		return -1;
	}

	std::unordered_map<int, int> left_num_occurances;
	std::unordered_map<int, int> right_num_occurances;
	std::priority_queue<std::pair<int, int>> left_heap;
	std::priority_queue<std::pair<int, int>> right_heap;

	left_num_occurances[nums[0]]++;

	for (int i = 1; i < nums.size(); i++) {
		right_num_occurances[nums[i]]++;
	}

	for (auto& num : right_num_occurances) {
		right_heap.push({ num.second, num.first });
	}

	left_heap.push({ 1, nums[0] });
    
    if (left_heap.top().second == right_heap.top().second && right_heap.top().first * 2 > (nums.size() - 1)) {
		return 0;
	}

	for (int i = 1; i < nums.size() - 1; i++) {

		left_num_occurances[nums[i]]++;
		right_num_occurances[nums[i]]--;

		while (!left_heap.empty() && left_num_occurances[left_heap.top().second] != left_heap.top().first) {
			left_heap.pop();
		}

		left_heap.push({ left_num_occurances[nums[i]], nums[i] });

		while (!right_heap.empty() && right_num_occurances[right_heap.top().second] != right_heap.top().first) {
			right_heap.pop();
		}
		right_heap.push({ right_num_occurances[nums[i]], nums[i] });

		if (left_heap.top().first * 2 <= (i + 1)) {
			continue;
		}

		if (right_heap.top().first * 2 <= nums.size() - (i+1)) {
			continue;
		}

		if (left_heap.top().second == right_heap.top().second) {
			return i;
		}

	}

	return -1;
}
};
