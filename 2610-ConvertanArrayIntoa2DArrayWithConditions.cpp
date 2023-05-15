#include <vector>
#include <unordered_map>

class Solution {
public:
std::vector<std::vector<int>> findMatrix(std::vector<int>& nums) {

	std::unordered_map<int, int> num_occurances;
	std::vector<std::vector<int>> result;
	std::vector<int> current_row;
	bool extra_num_flag = true;

	for (int i = 0; i < nums.size(); i++) {
		num_occurances[nums[i]]++;
	}

	while (extra_num_flag) {

		extra_num_flag = false;
		for (auto& num : num_occurances) {

			if (num.second > 1) {
				extra_num_flag = true;
			}
			if (num.second > 0) {
				current_row.push_back(num.first);
				num_occurances[num.first]--;
			}
		}
		result.push_back(current_row);
        current_row.clear();
	}

	return result;
}
};
