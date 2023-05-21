#include <vector>
#include <unordered_map>
#include <string>

class Solution {
public:
std::vector<std::vector<int>> substringXorQueries(std::string s, std::vector<std::vector<int>>& queries) {

	int target_num = 0;
	std::string binary_target;
	std::vector<std::vector<int>> result(queries.size(), std::vector<int>(2, -1));
	std::unordered_map<int, std::pair<int, int>> binary_nums;

	for (int i = 0; i < s.length(); i++) {

		int current_num = 0;

		if (s[i] == '0') {
			
			if (binary_nums.find(0) == binary_nums.end()) {
				binary_nums[0].first = i;
				binary_nums[0].second = i;
			}
			continue;
		}

		for (int j = i; j < s.length() && j - i < 30; j++) {

			if (s[j] == '0') {
				current_num <<= 1;
			}
			else {
				current_num <<= 1;
				current_num |= 1;
			}

			if (binary_nums.find(current_num) == binary_nums.end()) {
				binary_nums[current_num].first = i;
				binary_nums[current_num].second = j;
			}
		}

	}

	for (int i = 0; i < queries.size(); i++) {
		target_num = queries[i][0] ^ queries[i][1];
		
		if (binary_nums.find(target_num) != binary_nums.end()) {
			result[i][0] = binary_nums[target_num].first;
			result[i][1] = binary_nums[target_num].second;
		}

	}

	return result;
}
};
