#include <vector>
#include <unordered_ma>

class Solution {
public:
std::vector<int> numberOfPairs(std::vector<int>& nums) {

	std::unordered_map<int, int> num_occurances;
	int number_of_leftover_nums = 0;
	int number_of_pairs = 0;

	for (int i = 0; i < nums.size(); i++) {
		num_occurances[nums[i]]++;
	}

	for (auto& num : num_occurances) {

		number_of_leftover_nums += num.second % 2;
		number_of_pairs += num.second / 2;
	}

	return { number_of_pairs, number_of_leftover_nums };
}
};
