#include <vector>
#include <unordered_map>

class Solution {
public:
std::vector<int> topKFrequent(std::vector<int>& nums, int k) {

	std::unordered_map<int, int> num_occurances;
	std::vector<std::pair<int, int>> sortable_nums;
	std::vector<int> result(k);

	for (int i = 0; i < nums.size(); i++) {
		num_occurances[nums[i]]++;
	}

	for (auto& x : num_occurances) {
		sortable_nums.push_back({ x.second, x.first });
	}
	
	std::sort(sortable_nums.rbegin(), sortable_nums.rend());

	for (int i = 0; i < k; i++) {
		result[i] = sortable_nums[i].second;
	}

	return result;
}
};
