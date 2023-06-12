#include <vector>
#include <string>

class Solution {
public:
std::vector<std::string> summaryRanges(std::vector<int>& nums) {

	if (nums.empty()) return {};
	
	int starting_value = nums.front();
	int last_valid = nums.front();
	std::vector<std::string> result;

	for (int i = 1; i < nums.size(); i++) {

		if (nums[i] == last_valid + 1) {
			last_valid++;
		}
		else if (starting_value == last_valid) {
			result.push_back(std::to_string(starting_value));
			starting_value = nums[i];
			last_valid = nums[i];
		}
		else {
			result.push_back(std::to_string(starting_value) + "->" + std::to_string(last_valid));
			starting_value = nums[i];
			last_valid = nums[i];
		}
	}

	if (starting_value == last_valid) result.push_back(std::to_string(starting_value));
	
	else result.push_back(std::to_string(starting_value) + "->" + std::to_string(last_valid));
	
	return result;
}
};
