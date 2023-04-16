#include <vector>
#include <unordered_map>

class Solution {
public:
long long countGood(std::vector<int>& nums, int k) {

	std::vector<int> pair_counts = { 0, 0, 1 };
	std::unordered_map<int, int> occurances;

	int current_pairs = 0;
	int back_idx = 0;
	long long total_sub_arrays = 0;
	
	for (int i = 0; i < nums.size(); i++) {

		current_pairs -= pair_counts[occurances[nums[i]]];
		occurances[nums[i]]++;

		while (occurances[nums[i]] >= pair_counts.size()) {
			pair_counts.push_back(pair_counts.back() + pair_counts.size() - 1);
		}
		current_pairs += pair_counts[occurances[nums[i]]];

		while (current_pairs >= k && back_idx < nums.size()) {
			total_sub_arrays += (nums.size() - i);
			current_pairs -= pair_counts[occurances[nums[back_idx]]];
			occurances[nums[back_idx]]--;
			current_pairs += pair_counts[occurances[nums[back_idx]]];
			back_idx++;
		}
		
	}

	return total_sub_arrays;
}
};
