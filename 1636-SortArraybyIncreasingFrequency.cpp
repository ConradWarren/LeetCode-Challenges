#include <vector>
#include <unordered_map>

class Solution {
public:

std::vector<int> frequencySort(std::vector<int>& nums) {

	std::unordered_map<int, int> num_occurances;
	std::vector<std::pair<int, int>> sortable_nums;

	for (int i = 0; i < nums.size(); i++) {
		num_occurances[nums[i]]++;
	}

	for (auto& num : num_occurances) {
		sortable_nums.push_back({ num.second, -num.first });
	}

	std::sort(sortable_nums.begin(), sortable_nums.end());

	int idx = 0;
	for (int i = 0; i < sortable_nums.size(); i++) {

		for (int j = 0; j < sortable_nums[i].first; j++) {
			nums[idx] = -sortable_nums[i].second;
			idx++;
		}
	}

	return nums;
}
};
